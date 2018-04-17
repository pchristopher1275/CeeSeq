
@type
{
	
}
@end

@type
{
	"typeName": "CueEntry"
	"fields": [
		{"name": "fileId", "type": "String *"},
		{"name": "cues",   "type": "IntAr"}
	]
	"containers": [
        {
            "type": "array",
            "typeName": "CueEntryAr", 
            "elemName": "CueEntr",
            "binarySearch": [
               {"compare": "CueEntry_cmpByFileIdPp", "multi": true, "tag": "ByFilename"}
            ]
        },
        {
            "type": "array",
            "typeName": "CueEntryPtAr", 
            "elemName": "CueEntry *"
        }
  	]
}
@end

APIF void CueEntry_cmpByFileId(CueEntry *left, CueEntry *right)
{
	if (left->fileId < right->fileId) {
		return -1;
	} else if (left->fileId > right->fileId) {
		return 1;
	}
	return 0;
}

@type
{
	"typeName": "FilenameEntry",
	"fields": [
		{"name": "filename", "type": "String *"},
		{"name": "fileId",   "type": "int"}
	]
	"containers": [
        {
            "type": "array",
            "typeName": "FilenameEntryAr", 
            "elemName": "FilenameEntry",
            "binarySearch": [
               {"compare": "FilenameEntry_cmp"}
            ]
        }
    ]
}
@end

APIF int FilenameEntry_cmp(FilenameEntry *left, FilenameEntry *right)
{
	return String_cmp(left->filename, right->filename);
}


@type
{
	"typeName": "AudioBuffer",
	"fields": [
		{"name": "fileId",         "type": "int"},
		{"name": "cueOutlet",      "type": "CueOutlet"},
		{"name": "cancel",         "type": "Sequence *", "lifecycle": "unmanaged"},
		{"name": "cue",            "type": "int"}
	],
	"containers": [
        {
            "type": "array",
            "typeName": "AudioBufferAr", 
            "elemName": "AudioBuffer"
        },
        {
            "type": "array",
            "typeName": "AudioBufferPtAr", 
            "elemName": "AudioBuffer *",
            "binarySearch": [
               {"compare": "AudioBuffer_cmpByCuePp", "tag": "ByCue"}
            ]
        }
  	]
}
@end
#define AudioBuffer_isPlaying(ab) ((ab)->cue > 1)

APIF int AudioBuffer_cmpByCuePp(AudioBuffer **leftP, AudioBuffer **rightP)
{
	AudioBuffer *left  = *leftP;
	AudioBuffer *right = *rightP;
	if (left->cue < right->cue) {
		return -1
	} else if (left->cue > right->cue) {
		return 1
	}
	return 0;
}

@type
{
	"typeName": "AudioPlayer",
	"fields": [
		{"name", "nextCue",                "type": "int"},
		{"name", "nextCancel",             "type": "int"},
		{"name", "nextFileId",             "type": "int"},
		{"name": "cueMap",                 "type": "CueEntryAr"},
		{"name": "runningAudioBuffers",    "type": "AudioBufferPtAr"},
		{"name": "freePlayerPool",         "type": "PortPtAr"},
		{"name": "filenames",              "type": "FilenameEntryAr"},
		{"name": "atoms",                  "type": "AtomAr"}
	]
}
@end

COVER static inline int AudioPlayer_fileIdFromFilename(AudioPlayer *self, String *filename, Error *err)
{
	FilenameEntry *filenameEntry = FilenameEntryAr_binSearch(&self->filenames, filename);
	if (filenameEntry == NULL) {
		FilenameEntry e = {.filename = String_dup(filename), .fileId = self->nextFileId++};
		FilenameEntryAr_binInsert(&self->filenames, e);
		filenameEntry = StringPtAr_binSearch(&self->filenames, filename);
		if (fname == NULL) {
			Error_format0(err, "INTERNAL ERROR");
			return 0;
		}
	}
	return filenameEntry->fileId;
}

COVER static inline int AudioPlayer_getCue(AudioPlayer *self, int fileId, Error *err)
{

	CueEntry *cueEntry = CueEntryAr_binSearchByFileId(&self->cueMap, fileId);
	if (cueEntry == NULL) {
		// XXX: need to preload the file in question
		CueEntry cueEntry = {0};
		CueEntry_init(&cueEntry);
		cueEntry.fileId = fileId;
		CueEntryAr_binInsertByFileId(&self->cueMap, cueEntry);
		cueEntry = CueEntryAr_binSearchByFileId(&self->cueMap, fileId);
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
		cue = self->nextCue++;
		// XXX: need to preload this cue
	}
	return cue;
}

COVER static inline void AudioPlayer_releaseCue(AudioPlayer *self, int fileId, int cue) 
{
	CueEntry *cueEntry = CueEntryAr_binSearchByFileId(&self->cueMap, fileId);
	if (cueEntry == NULL) {
		return;
	}
	IntAr_push(&cueEntry->cues, cue);
}

COVER static inline void AudioPlayer_maybeFreeUpPort(AudioPlayer *self, Error *err)
{
	const int maxTries = 10;
	for (int i = 0; i < maxTries && PortPtAr_len(&self->freePlayerPool) <= 0; i++) {
		if (self->nextCancel >= AudioBufferPtAr_len(&self->runningAudioBuffers)) {
			self->nextCancel = 0;
		}
		AudioBuffer **audioBuffer = AudioBufferPtAr_get(&self->runningAudioBuffers, self->nextCancel, err);
		Sequence_stop((*audioBuffer)->cancel);
		self->nextCancel++;
	}
	if (PortPtAr_len(&self->freePlayerPool) > 0) {
		return;
	}
	Error_format0(err, "INTERNAL ERROR: failed to free up port");
}

COVER static inline void AudioPlayer_sendPlayMessage(AudioPlayer *self, AudioBuffer *audioBuffer)
{
	AtomAr_truncate(&self->atoms);
	AtomAr_push(&self->atoms,)

}

APIF AudioBuffer *AudioPlayer_createBuffer(AudioPlayer *self, String *filename, Error *err)
{
	// XXX: need to assign port
	int fileId = AudioPlayer_fileIdFromFilename(self, filename, err);
	Error_returnNullOnError(err);
	AudioBuffer *audioBuffer = AudioBuffer_new();
	audioBuffer->fileId   = fileId;
	return audioBuffer;
}

APIF void AudioPlayer_releaseBuffer(AudioPlayer *self, AudioBuffer *audioBuffer)
{
	if (AudioBuffer_isPlaying) {
		AudioPlayer_stop(self, audioBuffer);
	}	
	AudioBuffer_free(audioBuffer);
}

APIF void AudioPlayer_play(AudioPlayer *self, AudioBuffer *audioBuffer, Sequence *cancel, Error *err) 
{
	if (AudioBuffer_isPlaying(audioBuffer)) {
		AudioPlayer_stop(self, audioBuffer);
	}

	AudioPlayer_maybeFreeUpPort(self, err);
	Error_returnVoidOnError(err);

	Port *port = PortPtAr_get(&self->freePlayerPool, PortPtAr_last(&self->freePlayerPool), err);
	Error_returnVoidOnError(err);
	int cue = AudioPlayer_getCue(self, filename, err);
	Error_returnVoidOnError(err);

	// At this point we commit
	PortPtAr_pop(&self->freePlayerPool);
	audioBuffer->outputPort = port;
	audioBuffer->cue        = cue;
	audioBuffer->cancel     = cancel;
	return;	
}

APIF void AudioPlayer_stop(AudioPlayer *self, AudioBuffer *audioBuffer)
{
	// Send stop message
	AudioBufferPtAr_binRemoveByCue(&self->runningAudioBuffers, audioBuffer);
	AudioPlayer_releaseCue(self, audioBuffer->fileId, audioBuffer->cue);
	PortPtAr_push(&self->freePlayerPool, audioBuffer->outputPort);
	audioBuffer->outputPort = NULL;
	audioBuffer->cue        = 0;
	audioBuffer->cancel     = NULL;
}
