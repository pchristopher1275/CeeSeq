
@type
{
	"typeName": "AudioOutlet",
	"fields": [
		{"name": "port",   "type": "Port *"},
		{"name": "outlet", "type": "int"},
		{"name": "atoms",  "type": "AtomAr"}
	],
	"containers": [
        {
            "type": "array",
            "typeName": "AudioOutletPtAr", 
            "elemName": "AudioOutlet *"
        }
    ]
}
@end

APIF void AudioOutlet_userInit(AudioOutlet *self)
{
	AtomAr_changeLength(&self->atoms, 4);
}

APIF void AudioOutlet_sendPreload(AudioOutlet *self, Symbol *fileSymbol, int cue, Ticks offset, Error *err)
{
	Atom *a = self->atoms.data;
	a[0] = Atom_fromSymbol(Symbol_gen("preload"));
	a[1] = Atom_fromInteger(cue);
	a[2] = Atom_fromSymbol(fileSymbol);
	int argc = 3;
	if (offset > 0) {
		double ms = Ticks_toMs(offset);
		a[3] = Atom_fromInteger((long)ms);
		argc++;
	}
	Port_send(self->port, self->outlet, argc, argv, err);
	return;
}

APIF void AutioOutlet_sendPlay(AudioOutlet *self, int cue, Error *err)
{
	Port_sendInteger(self->port, self->outlet, cue, err);
}

APIF void AutioOutlet_sendStop(AudioOutlet *self, Error *err)
{
	Port_sendInteger(self->port, self->outlet, 0, err);
}



@type
{
	"typeName": "CueEntry"
	"fields": [
		{"name": "fileSymbol", "type": "Symbol *"},
		{"name": "cues",       "type": "IntAr"}
	]
	"containers": [
        {
            "type": "array",
            "typeName": "CueEntryAr", 
            "elemName": "CueEntry",
            "binarySearch": [
               {"compare": "CueEntry_cmpByFileSymbol", "tag": "ByFileSymbol"}
            ]
        }
  	]
}
@end

APIF void CueEntry_cmpByFileSymbol(CueEntry *left, CueEntry *right)
{
	if (left->fileSymbol < right->fileSymbol) {
		return -1;
	} else if (left->fileSymbol > right->fileSymbol) {
		return 1;
	}
	return 0;
}

@type
{
	"typeName": "AudioBuffer",
	"fields": [
		{"name": "fileSymbol",     "type": "Symbol *"},
		{"name": "audioOutlet",    "type": "AudioOutlet *"},
		{"name": "cancel",         "type": "Sequence *", "lifecycle": "unmanaged"},
		{"name": "isTempCue",      "type": "bool"},
		{"name": "cue",            "type": "int"}
	],
	"containers": [
        {
            "type": "array",
            "typeName": "AudioBufferPtAr", 
            "elemName": "AudioBuffer *",
            "binarySearch": [
               {"compare": "AudioBuffer_cmpByPointerPp", "tag": "ByPointer"}
            ]
        }
  	]
}
@end

COVER static inline bool AudioBuffer_isPlaying(AudioBuffer *self)
{
	return self->audioOutlet != NULL;
}

COVER static inline bool AudioBuffer_needsStop(AudioBuffer *self)
{
	return AudioBuffer_isPlaying(self) || self->isTempCue;
}

APIF int AudioBuffer_cmpByPointerPp(AudioBuffer **leftP, AudioBuffer **rightP)
{
	AudioBuffer *left  = *leftP;
	AudioBuffer *right = *rightP;
	if (left < right) {
		return -1
	} else if (left > right) {
		return 1
	}
	return 0;
}

@type
{
	"typeName": "AudioPlayer",
	"fields": [
		{"name", "nextNormalCue",          "type": "int"},
		{"name", "nextTempCue",            "type": "int"},
		{"name", "nextCancel",             "type": "int"},
		{"name", "nextFileId",             "type": "int"},
		{"name": "normalCueMap",           "type": "CueEntryPtAr"},
		{"name": "freeTempCues",           "type": "IntAr"},
		{"name": "listTildeOutlet",        "type": "AudioOutlet *"},
		{"name": "runningAudioBuffers",    "type": "AudioBufferPtAr"},
		{"name": "freePlayerPool",         "type": "AudioOutletPtAr"},
		{"name": "filenames",              "type": "FilenameEntryAr"},
		{"name": "atoms",                  "type": "AtomAr"}
	]
}
@end

#define AudioPlayer_firstUsableCue   2
#define AudioPlayer_lastUsableCue    32767
#define AudioPlayer_tempReservedCues 1000
#define AudioPlayer_firstNormalCue   AudioPlayer_firstUsableCue
#define AudioPlayer_lastNormalCue    (AudioPlayer_lastUsableCue - AudioPlayer_tempReservedCues - 1)
#define AudioPlayer_firstTempCue     (AudioPlayer_lastNormalCue + 1)
#define AudioPlayer_lastTempCue      AudioPlayer_lastUsableCue 

COVER void AudioPlayer_userInit(AudioPlayer *self)
{
	self->nextNormalCue = AudioPlayer_firstNormalCue;
	self->nextTempCue   = AudioPlayer_firstTempCue;
}

COVER static inline int AudioPlayer_getNormalCue(AudioPlayer *self, Symbol *fileSymbol, Error *err)
{
	CueEntry *cueEntry = CueEntryPtAr_binSearchByFileSymbol(&self->normalCueMap, fileSymbol);
	if (cueEntry == NULL) {
		CueEntry cueEntryValue = {0};
		CueEntry_init(&cueEntryValue);
		cueEntryValue.fileSymbol = fileSymbol;
		CueEntryAr_binInsertByFileSymbol(&self->normalCueMap, cueEntryValue);
		cueEntry = CueEntryPtAr_binSearchByFileSymbol(&self->normalCueMap, fileSymbol);
		if (cueEntry == NULL) {
			Error_format0(err, "INTERNAL ERROR");
			return 0;
		}
	}
	int cue = 0;
	if (IntAr_len(&cueEntry->cues) > 0) {
		cue = IntAr_get(&cueEntry->cues, IntAr_last(&cueEntry->cues), err);
		Error_returnNullOnError(err);
		IntAr_pop(&cueEntry->cues);
	} else {
		if (self->nextNormalCue > AudioPlayer_lastNormalCue) {
			Error_format0(err, "Exhausted normal cues");
			return 0;
		}
		cue = self->nextNormalCue++;
		AudioOutlet_sendPreload(self->listTildeOutlet, fileSymbol, cue, -1, err);
		Error_returnZeroOnError(err);
	}
	return cue;
}

COVER static inline void AudioPlayer_releaseNormalCue(AudioPlayer *self, Symbol *fileSymbol, int cue) 
{
	CueEntry *cueEntry = CueEntryPtAr_binSearchByFileSymbol(&self->normalCueMap, fileSymbol);
	if (cueEntry == NULL) {
		return;
	}
	IntAr_push(&cueEntry->cues, cue);
}

COVER static inline void AudioPlayer_maybeFreeUpPlayer(AudioPlayer *self, Error *err)
{
	
	// Loop as long as there are no free ports or until maxTries.
	const int maxTries = 10;
	for (int i = 0; i < maxTries && AudioOutletPtAr_len(&self->freePlayerPool) <= 0; i++) {
		if (self->nextCancel >= AudioBufferPtAr_len(&self->runningAudioBuffers)) {
			self->nextCancel = 0;
		}
		AudioBuffer **audioBuffer = AudioBufferPtAr_get(&self->runningAudioBuffers, self->nextCancel, err);
		Sequence_stop((*audioBuffer)->cancel);
		self->nextCancel++;
	}
	
	if (AudioOutletPtAr_len(&self->freePlayerPool) > 0) {
		return;
	}

	Error_format0(err, "INTERNAL ERROR: failed to free up port");
}

APIF AudioBuffer *AudioPlayer_createBuffer(AudioPlayer *self, String *filename)
{
	AudioBuffer *audioBuffer = AudioBuffer_new();
	audioBuffer->fileSymbol  = Symbol_gen(filename);
	return audioBuffer;
}

APIF void AudioPlayer_releaseBuffer(AudioPlayer *self, AudioBuffer *audioBuffer)
{
	if (AudioBuffer_needsStop(audioBuffer)) {
		AudioPlayer_stop(self, audioBuffer);
	} 
	AudioBuffer_free(audioBuffer);
}

APIF void AudioPlayer_prepareTemporaryCue(AudioPlayer *self, AudioBuffer *audioBuffer, Ticks offset, Error *err)
{
	int cue = 0;
	if (IntAr_len(&self->freeTempCues) <= 0) {
		if (self->nextTempCue > AudioPlayer_lastTempCue) {
			Error_format0(err, "Exhausted temporary cues");
			return;
		}
		cue = self->nextTempCue++;
	} else {
		cue = IntAr_get(&self->freeTempCues, IntAr_last(&self->freeTempCues), err);
		Error_returnVoidOnError(err);
		IntAr_pop(&self->freeTempCues);
	}
	audioBuffer->isTempCue = true;
	audioBuffer->cue       = cue;
	AudioOutlet_sendPreload(audioBuffer->listTildeOutlet, audioBuffer->fileSymbol, offset, err);
	Error_returnVoidOnError(err);
}

APIF void AudioPlayer_play(AudioPlayer *self, AudioBuffer *audioBuffer, Sequence *cancel, Error *err) 
{
	if (AudioBuffer_isPlaying(audioBuffer)) {
		AudioPlayer_stop(self, audioBuffer);
	}

	AudioPlayer_maybeFreeUpPlayer(self, err);
	Error_returnVoidOnError(err);

	AudioOutlet **audioOutlet = AudioOutletPtAr_get(&self->freePlayerPool, AudioOutletPtAr_last(&self->freePlayerPool), err);
	Error_returnVoidOnError(err);

	int cue = 0;
	if (!audioBuffer->isTempCue) {
		cue = AudioPlayer_getNormalCue(self, audioBuffer->fileSymbol, err);
		Error_returnVoidOnError(err);
	}
	

	// At this point we commit
	AudioOutletPtAr_pop(&self->freePlayerPool);
	if (!audioBuffer->isTempCue) {
		audioBuffer->cue = cue;
	}
	audioBuffer->audioOutlet = *audioOutlet;
	audioBuffer->cancel      = cancel;
	AudioOutlet_sendPlay(audioBuffer->audioOutlet);
	AudioBufferPtAr_binInsertByPointer(&self->runningAudioBuffers, audioBuffer);
	return;	
}

APIF void AudioPlayer_stop(AudioPlayer *self, AudioBuffer *audioBuffer)
{
	// 3 States to consider 
	//    (1) The audioBuffer only has fileSymbol is populated. The sequence is stoped
	//    (2) The audioBuffer has fileSymbol and cue populated. The sequence is stoped, but a temporary cue has been allocated
	//    (3) The audioBuffer is playing, so everything is allocated.
	// Send stop message
	if (AudioBuffer_isPlaying(audioBuffer)) {
		AudioBufferPtAr_binRemoveByPointer(&self->runningAudioBuffers, audioBuffer);	
		AudioOutletPtAr_push(&self->freePlayerPool, audioBuffer->outputPort);
	}
	if (AudioBuffer_needsStop(audioBuffer)) {
		if (audioBuffer->isTempCue) {
			IntAr_push(&self->freeTempCues, audioBuffer->cue);
		} else {
			AudioPlayer_releaseNormalCue(self, audioBuffer->fileSymbol, audioBuffer->cue);
		}
	}
	
	audioBuffer->cue         = 0;
	audioBuffer->audioOutlet = NULL;
	audioBuffer->cancel      = NULL;
	audioBuffer->isTempCue   = false;
}
