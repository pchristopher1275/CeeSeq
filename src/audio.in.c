
@type
{
	"typeName": "Resource",
	"fields": [
		// projectLibrary must be a full (starts with slash) path to the project library directory (i.e. the dir where all the projects are stored)
		{"name": "songLibrary", "type": "String *"},

		// Which song is currently is currently (or will be) loaded.
		{"name": "songName",    "type": "String *",  "setter":"none"}

		{"name": "lastTime",    "type": "time_t"},
		{"name": "batchIndex",  "type": "int"}
	],
}
@end

APIF Resource *Resource_newBuild(String *songLibrary) 
{
	Resource *self = Resource_new();
	String_free(self->songLibrary);
	self->songLibrary = String_fmt("%s", "/Users/pete/Desktop/SnippetSequencer");
	self->songLibrary = String_dup(songLibrary);
	return self;
}

APIF bool Resource_setSongName(Resource *self, String *songName, Error *err) 
{
	String_free(self->songName);
	self->songName = String_dup(songName);

#   ifndef TEST_BUILD
	{
		String *projectDir = String_fmt("%s/%s", self->projectLibrary, self->songName);

		char filename[MAX_PATH_CHARS] = "UNUSED";
		char fullpath[MAX_PATH_CHARS] = "";
		strncpy(fullpath, projectDir, MAX_PATH_CHARS-1);
		short path = 0;
		if (path_frompathname(fullpath, &path, filename)) {
			Error_fomrmat("path_frompathname failed for path '%s'", projectDir);
			return;
		}


		short recursive = 1;
		if (!path_setdefault(path, recursive)) {
			Error_format(err, "Failed to set default path to %s", projectDir);
		}
		String_free(projectDir);
	}
#   endif

	
	return;
}

APIF bool Resource_projectAudioFileExists(Resource *self, Symbol *fileSymbol, Error *err)
{
	if (String_isempty(self->songName)) {
		Error_format(err, "Resource not assigned songName");
		return false;
	}

	String *path = String_fmt("%s/%s/audio/%s.wav", self->songLibrary, self->songName, Symbol_cstr(fileSymbol));
	int q = access(path, F_OK);
	if (!q) {
		Error_format(err, "Audio file '%s' does not exist", path);
	}
	String_free(path);
	return q ? true : false;
}

APIF Symbol *Resource_createProjectAudioFile(Resource *self, Error *err)
{
	time_t now;
	if (time(&now) < 0) {
		Error_format0(err, "Unix time command failed");
		return NULL;
	}
	if (self->lastTime == now) {
		self->batchIndex++;
	} else {
		self->batchIndex = 0;
	}
	String *buffer = String_fmt("%lld_%d", (long long)now, self->batchIndex);
	Symbol *fileSymbol = Symbol_gen(buffer):
	String_free(buffer);

	self->lastTime = now;
	return fileSymbol;
}


APIF void Resource_listDirectoryTEMP(Resource *self, String *path, Error *err)
{
	const char *paths[2] = {path, NULL};
	// FTS *tree = fts_open((char *const *)paths, FTS_PHYSICAL | FTS_NOCHDIR | FTS_NOSTAT, NULL);
	FTS *tree = fts_open((char *const *)paths, FTS_PHYSICAL | FTS_NOCHDIR, NULL);
	if(tree == NULL) {
		Error_format0(err, "Failed fts_open");
		return;
	}

	for (;;) {
		FTSENT *ent = fts_read(tree); // get next entry (could be file or directory).
		if(ent == NULL) {
			if(errno == 0) {
				break; // No more items, bail out of while loop
			}
			
			Error_format0(err, "Failed fts_read");
			return;
		}
			
 		if (ent->fts_info == FTS_F) {
 			printf("FILE: %s '%s'\n", ent->fts_path, ent->fts_name);
 		} else if (ent->fts_info == FTS_DP) {
 			printf("DP:   %s\n", ent->fts_path);
 			
 		} else if (ent->fts_info == FTS_DC) {
			Error_format0(err, "Unexpected directory cycle in fts call chain");
			goto END;
		}
	}
 
	/* fts_read() sets errno = 0 unless it has error. */
	if (errno != 0) {
		Error_format0(err, "Failed fts_read");
		goto END;
	}
 
  END:
	if(fts_close(tree) == -1) {
		if (!Error_iserror(err)) {
			Error_format0(err, "Failed fts_close");
		}
	}
}

COVER void Resource_unlinkDirectory(Resource *self, String *path, Error *err)
{
	const char *paths[2] = {path, NULL};
	FTS *tree = fts_open(paths, FTS_PHYSICAL | FTS_NOCHDIR | FTS_NOSTAT, NULL);
	if(tree == NULL) {
		Error_format(err, "Failed fts_open: %s", strerror(errno));
		return;
	}

	for (;;) {
		FTSENT *ent = fts_read(tree); // get next entry (could be file or directory).
		if(ent == NULL) {
			if(errno == 0) {
				break; // No more items, bail out of while loop
			}
			
			Error_format(err, "Failed fts_read: %s", strerror(errno));
			return;
		}
			
 		if (ent->fts_info == FTS_F) {
 			if (unlink(ent->fts_path) != 0) {
 				Error_format(err, "Resource_unlinkDirectory failed to remove file %s: %s", ent->fts_path, strerror(errno));
 				goto END;
 			}
 		} else if (ent->fts_info == FTS_DP) {
 			if (rmdir(ent->fts_path) != 0) {
 				Error_format(err, "Resource_unlinkDirectory failed to remove directory %s: %s", ent->fts_path, strerror(errno));
 				goto END;
 			}
 		}

		if (f->fts_info == FTS_DC) {
			Error_format0(err, "Unexpected directory cycle in fts call chain");
			goto END;
		}
	}
 
	/* fts_read() sets errno = 0 unless it has error. */
	if (errno != 0) {
		Error_format(err, "Failed fts_read: %s", strerror(errno));
		goto END;
	}
 
  END:
	if(fts_close(tree) == -1) {
		if (!Error_iserror(err)) {
			Error_format(err, "Failed fts_close: %s", strerror(errno));
			return;
		}
	}
}

APIF void Resource_setSongToUntitled(Resource *self, Error *err)
{
	String_free(self->songName);
	self->songName = String_fmt("%s", "untitled");
	String *path = String_fmt("%s/%s", self->songLibrary, self->songName);
	struct stat pathstat;
    if (stat(path, &pathstat) == 0 && (path.st_mode & S_IFDIR) != 0 ) {
    	Resource_unlinkDirectory(self, path, err);
    	Error_gotoLabelOnError(err, END);
    }
    if (mkdir(path, 0755) != 0) {
    	Error_format(err, "Failed to mkdir: %s", strerror(errno));
    	goto END;
    }
    String_free(path);
    path = String_fmt("%s/%s/audio", self->songLibrary, self->songName);
    if (mkdir(path, 0755) != 0) {
    	Error_format(err, "Failed to mkdir: %s", strerror(errno));
    	goto END;
    }
    
  END:
  	if (path != NULL) {
  		String_free(path);
  	}
  	return;
}

APIF void Resource_moveSong(Resource *self, String *newSongName, Error *err)
{
	if (String_isempty(self->songName)) {
		Error_format0(err, "Called Resource method without setting songName");
		return;
	}

	String *src = String_fmt("%s", self->songLibrary, self->songName);
	String *dst = String_fmt("%s/%s", self->songLibrary, newSongName);
	if (rename(src, dst) != 0) {
		Error_format(err, "Failed to move '%s' to '%s'", src, dst);
	} else {
		String_free(self->songName);
		self->songName = String_dup(newSongName);	
	}
	String_free(src);
	String_free(dst);
	return;
}


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
	AtomAr_changeLength(&self->atoms, 5);
}

APIF void AudioOutlet_sendPreload(AudioOutlet *self, Symbol *fileSymbol, int cue, Ticks startOffset, Ticks endOffset, Error *err)
{
	if (startOffset <= 0) {
		startOffset = 0;
	}
	if (endOffset <= 0) {
		endOffset = 0;
	}
	Atom *a = self->atoms.data;
	a[0] = Atom_fromSymbol(Symbol_gen("preload"));
	a[1] = Atom_fromInteger(cue);
	a[2] = Atom_fromSymbol(fileSymbol);
	a[3] = Atom_fromInteger((long)Ticks_toMs(startOffset));
	a[4] = Atom_fromInteger((long)Ticks_toMs(endOffset));
	Port_send(self->port, self->outlet, 5, self->atoms.data, err);
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
	// Cue entry maps a fileSymbol to a list of predefined
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
	"typeName": "AudioEvent",
	"fields": [
		// NOTE: stime can hold sequence time AND absolute time depending on the context
		{"name": "stime",         "type": "Ticks"},
		{"name": "cue",            "type": "int"},

		{"name": "offsetSTime",     "type": "Ticks"},
		{"name": "offsetCue",       "type": "int"}

		// Serialized
		{"name": "fileSymbol",     "type": "Symbol *"},

		{"name": "sampleStart",    "type": "Ticks"},
		{"name": "sampleEnd",      "type": "Ticks"},

		{"name": "fileLength",     "type": "Ticks"},
		

		// Unserialized
		{"name": "audioOutlet",    "type": "AudioOutlet *", "lifecycle": "unmanaged"},
		{"name": "cancel",         "type": "Sequence *", "lifecycle": "unmanaged"},
	],
	"containers": [
        {
            "type": "array",
            "typeName": "AudioEventAr", 
            "elemName": "AudioEvent",
            "binarySearch": [
               {"compare": "AudioEvent_cmpByTime", "tag": "ByTime"}
            ]
        },
        {
            "type": "array",
            "typeName": "AudioEventPq", 
            "elemName": "AudioEvent",
            "binarySearch": [
               {"compare": "AudioEvent_cmpByTime", "tag": "ByTime"}
            ]
        },
  	]
}
@end

COVER static inline bool AudioEvent_isPlaying(AudioBuffer *self)
{
	return self->audioOutlet != NULL;
}

COVER static inline bool AudioEvent_needsStop(AudioBuffer *self)
{
	return AudioBuffer_isPlaying(self) || self->offsetCue > 0;
}

APIF int AudioEvent_cmpByTime(AudioEvent *left, AudioEvent *right) 
{
	if (left->stime < right->stime) {
		return -1;
	} else if (left->stime > right->stime) {
		return 1;
	}
	return 0;
}

APIF AudioEvent AudioEvent_cleanClone(AudioEvent *self)
{
	AudioEvent e = {0};
	e.fileSymbol  = self->fileSymbol;
	e.sampleStart = self->sampleStart;
	e.sampleEnd   = self->sampleEnd;
	e.fileLength  = self->fileLength;
	return other;
}

@type
{
	"typeName": "AudioPlayer",
	"fields": [
		{"name": "pathManager",            "type": "Resource *"},
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

COVER static inline int AudioPlayer_getNormalCue(AudioPlayer *self, AudioBuffer *audioBuffer, Error *err)
{
	CueEntry *cueEntry = CueEntryPtAr_binSearchByFileSymbol(&self->normalCueMap, fileSymbol);
	if (cueEntry == NULL) {
		CueEntry cueEntryValue = {0};
		CueEntry_init(&cueEntryValue);
		cueEntryValue.fileSymbol = audioBuffer->fileSymbol;
		CueEntryAr_binInsertByFileSymbol(&self->normalCueMap, cueEntryValue);
		cueEntry = CueEntryPtAr_binSearchByFileSymbol(&self->normalCueMap, audioBuffer->fileSymbol);
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
		AudioOutlet_sendPreload(self->listTildeOutlet, audioBuffer->fileSymbol, cue, audioBuffer->sampleStart, audioBuffer->sampleEnd, err);
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


APIF AudioBuffer AudioPlayer_openBuffer(AudioPlayer *audioPlayer, String *filename, Ticks startTime, Ticks endTime, Error *err)
{
	AudioBuffer audioBuffer = {0};
	Resource_projectAudioFileExists(audioPlayer->pathManager, filename, err);
	Error_returnValueOnError(err, audioBuffer);

	AudioBuffer_init(&audioBuffer);
	audioBuffer.fileSymbol  = Symbol_gen(filename);
	audioBuffer.startTime   = startTime;
	audioBuffer.endTime     = endTime;
	return audioBuffer;
}

APIF void AudioPlayer_closeBuffer(AudioPlayer *self, AudioBuffer *audioBuffer)
{
	if (AudioBuffer_needsStop(audioBuffer)) {
		AudioPlayer_stop(self, audioBuffer);
	} 
	AudioBuffer_clear(audioBuffer);
}

APIF AudioBuffer AudioPlayer_cloneBuffer(AudioPlayer *self, AudioBuffer *input)
{
	AudioBuffer other = {0};
	AudioBuffer_init(&other);
	other.audioOutlet = NULL;
	other.cancel      = NULL;
	other.isTempCue   = false;
	other.cue         = 0;
	return other;
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
	AudioOutlet_sendPreload(audioBuffer->listTildeOutlet, audioBuffer->fileSymbol, audioBuffer->sampleStart+offset, audioBuffer->sampleEnd, err);
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
		cue = AudioPlayer_getNormalCue(self, audioBuffer, err);
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

@type 
{
    "typeName": "AudioSequence",
    "fields":[  
        {
            "name": "version", 
            "type": "long"
        },
        {  
            "name":"startTime",
            "type":"Ticks"
        },
        {  
            "name":"outletSpecifier",
            "type":"OutletSpecifier"
        },
        {  
            "name":"sequenceLength",
            "type":"Ticks"
        },
        {  
            "name":"cycle",
            "type":"bool"
        },
        {  
            "name":"inEndgroup",
            "type":"bool"
        },
        {  
            "name":"recordingSeq",
            "type":"AudioSequence *",
            "lifecycle": "unmanaged"
        },
        {
            "name":"audioPlayer",
            "type":"AudioPlayer *",
            "lifecycle": "unmanaged"
        },
        {  
            "name":"pendingStops",
            "type":"AudioEventPtPq"
        },
        {  
            "name":"events",
            "type":"AudioEventAr"
        },

        // In order to support extra an extra tail at the end of a cycling sequence, we have to be able to have 2 AudioBuffers running at once. In
        // order for that to be true, we have to have 2 seperate AudioBuffers. The easiest way to do this is to have a second set of AudioBuffers
        // that are used if cycle is true. NOTE: that this limits the length of the tail region of a file to be as long as the sequence (i.e. you
        // can have a 4 bar audio loop with an UPTO 4 bar tail).
        {  
            "name":"useEvents2",
            "type":"bool"
        },
        {  
            "name":"events2",
            "type":"AudioEventAr"
        },
    ], 
    "implements": ["Sequence"]
}
@end

AudioBuffer AudioSequence_cycleMarkerImpl = {0}, *AudioSequence_cycleMarker = &AudioSequence_cycleMarkerImpl;
AudioBuffer AudioSequence_endgMarkerImpl = {0},  *AudioSequence_endgMarker  = &AudioSequence_endgMarkerImpl;
#define AudioSequence_isMarkerBuffer(b) (b == AudioSequence_cycleMarker || b == AudioSequence_endgMarker)
#define AudioSequence_prepareLeadtime 15

APIF void AudioSequence_start(AudioSequence *self, Ticks clockStart, Ticks current, TimedPq *queue, RecordBuffer *recordBuffer, Error *err) 
{
	int nevents = AudioEventAr_len(&self->events);
    if (nevents <= 0) {
        return;
    }

    self->startTime    = self->cycle ? clockStart : current;
    self->cursor       = 0;
    self->inEndgroup   = false;
    self->useEvents2   = false;
    Ticks nextEvent    = 0;
    bool locateCursor  = true;
    if (self->cycle) {
        if (self->sequenceLength <= Sequence_minSequenceLength) {
            self->sequenceLength = Sequence_minSequenceLength;
        }
        while (current - self->startTime > self->sequenceLength) {
            self->startTime += self->sequenceLength;
        }

        AudioEventAr_foreach(it, &self->events) {
        	Ticks startTime     = it.var->stime + self->startTime;
        	Ticks endTime       = startTime + (it.var->audioBuffer.sampleStart - it.var->audioBuffer.sampleEnd);
        	Ticks realStartTime = startTime;
        	if (startTime <= current && current <= endTime) {
        		// The start time cuts the audio file into pieces
        		realStartTime = it.var->tempCueTime = current + AudioSequence_prepareLeadtime;
        		AudioPlayer_prepareTemporaryCue(self->audioPlayer, &it.var->audioBuffer, realStartTime-startTime, err);
        		Error_returnVoidOnError(err);
        	}

        	if (locateCursor) {
        		if (realStartTime >= current) {
	            	locateCursor = false;
	                nextEvent = realStartTime;
	            } else if (getNextEvent) {
	            	self->cursor++;
	        	}
        	}
        }
        if (self->cursor >= nevents) {
            Error_format0(err, "INTERNAL ERROR: cursor found to be >= nevents");
            return;
        }

    } else {
        AudioEventAr_foreach(it, &self->events) {
            nextEvent = it.var->stime + self->startTime;
            break;
        }
    }
    self->recordingSeq = NULL;
    if (recordBuffer != NULL) {
        NoteSequence *other = AudioSequence_castFromSequence(AudioSequence_compactNew(self, self->startTime));
        self->recordingSeq  = other; 
        RecordBuffer_push(recordBuffer, AudioSequence_castToSequence(other));
    }
    TimedPq_enqueue(queue, nextEvent, AudioSequence_castToSequence(self));
}

COVER static inline void AudioSequence_playStops(AudioSequence *self, Ticks current)
{
	// Play stops
    AudioEvent *peeked = AudioEventPq_pqPeek(&self->pendingStops);
    while (peeked != NULL) {
    	if (AudioEvent_time(peeked) > current) {
    		break;
    	}
    	AudioPlayer_stop(self->audioPlayer, &peeked->audioBuffer);
    	AudioEventPq_pqPop(&self->pendingStops);
    	peeked = AudioEventPq_pqPeek(&self->pendingStops);
    }
}

APIF void AudioSequence_stop(AudioSequence *self, Ticks current, Error *err) 
{
	self->cursor = AudioEventAr_len(&self->events);
	self->version++;
	AudioSequence_playStops(self, Ticks_maxTime);
}

APIF void AudioSequence_padNoteOff(AudioSequence *self, int padIndex, Ticks current, Error *err) 
{
    if (self->inEndgroup && !self->cycle) {
        AudioSequence_stop(self, current, err);
    }
}

APIF void AudioSequence_drive(AudioSequence *self, Ticks current, TimedPq *queue, Error *err) 
{
    Ticks nextEvent = Ticks_maxTime;

    // Play stops
    AudioSequence_playStops(self, current);

    // Start new sequences
    for (;;) {
    	AudioEventAr *events = self->useEvents2 ? &self->events2 : &self->events;
        AudioEventAr_foreachOffset(it, events, self->cursor) {
            AudioEvent *e = it.var;
            Ticks startTime = e.tempCueTime >= 0 ? e.tempCueTime : (e.stime + self->startTime);
            if (startTime > current) {
            	Ticks nextEvent = startTime;
            	TimedPq_enqueue(queue, nextEvent, AudioSequence_castToSequence(self));
               	return;
            }

            // This invalidates the tempCueTime in case it was used
            it.var->tempCueTime = -1;

            bool isMarker = AudioSequence_isMarkerBuffer(e->audioBuffer);
            if (!isMarker) {
                Ticks delta    = (e->audioBuffer.sampleEnd-e->audioBuffer.sampleStart) - (startTime - self->startTime);
                AudioEvent off = {.stime = startTime + delta, .audioBuffer = e->audioBuffer};
                AudioEventPq_pqPush(&self->pendingStops, off);
                AudioPlayer_play(self->audioPlayer, &e->audioBuffer, AudioSequence_castToSequence(self), err);
                Error_returnVoidOnError(err);
            } else if (e->audioBuffer == AudioSequence_endgMarker && !self->cycle) {
                self->inEndgroup = true;
            } 

            if (self->recordingSeq != NULL && !isMarker) {
                AudioEvent e  = *ne;
                e.stime       = self->recordingSeq->startTime + e.stime;
                e.audioBuffer = AudioPlayer_cloneBuffer(self->audioPlayer, &e.audioBuffer);
                AudioEventAr_push(&self->recordingSeq->events, e);
            }
            self->cursor++;
        }
        if (self->cycle) {
            if (self->sequenceLength <= Sequence_minSequenceLength) {
               self->sequenceLength = Sequence_minSequenceLength;
            }
            self->startTime += self->sequenceLength;
            self->cursor     = 0;
            self->useEvents2 = !self->useEvents2;
        } else {
            return;
        }
    }

}


APIF Sequence *AudioSequence_compactNew(AudioSequence *self, Ticks recordStart)
{
    AudioSequence *other   = AudioSequence_new();
    other->startTime       = recordStart;
    other->outletSpecifier = self->outletSpecifier;
    return AudioSequence_castToSequence(other);
}

APIF void AudioSequence_compactConcat(AudioSequence *self, Sequence *otherSeq, Error *err)
{
    AudioSequence *other = AudioSequence_castFromSequence(otherSeq);
    if (other == NULL) {
        Error_format(err, "AudioSequence_compactConcat was passed a sequence of type %s", Interface_toString(Interface_itype(otherSeq)));
        return;
    }
    AudioEventAr_foreach(it, &other->events) {
        if (AudioSequence_isMarkerValue(it.var)) {
            continue;
        }
        // Remember that self->startTime == recordStart
        AudioEvent e = *it.var;
        e.stime += (other->startTime - self->startTime);
        AudioEventAr_push(&self->events, e); 
    }
    return;
}

APIF void AudioSequence_compactSortEvents(AudioSequence *self)
{
    AudioEventAr_sort(&self->events);
}

APIF Ticks AudioSequence_compactComputeSequenceLength(AudioSequence *self)
{
    Ticks lastTime = Sequence_minSequenceLength;
    AudioEventAr_foreach(it, &self->events) {
    	Ticks end = it.var->stime + (it.var->audioBuffer.sampleEnd - it.var->audioBuffer.sampleStart);
    	if (end > lastTime) {
    		lastTime = end;
    	} 
    }

    MusicalContext_declareDefault(musicalContext);
    Ticks mlen   = musicalContext.quarterNotesPerMeasure*musicalContext.ticksPerQuarterNote;
    Ticks seqLen = (lastTime/mlen)*mlen + (lastTime % mlen == 0 ? 0 : mlen);
    if (seqLen < Sequence_minSequenceLength) {
        seqLen = Sequence_minSequenceLength;
    }
    return seqLen;
}

APIF void AudioSequence_compactFinish(AudioSequence *self, Ticks endgroupTime, Ticks sequenceLength, Error *err)
{
    if (endgroupTime >= 0) {
        int index = AudioEventAr_len(&self->events) > 0 ? 0 : -1;
        AudioEventAr_rforeach(it, &self->events) {
            if (AudioSequence_isMarkerValue(it.var)) {
                continue;
            }
            if (self->startTime + it.var->stime < endgroupTime) {
                index = it.index + 1;
                break;
            }
        }
        if (index >= 0) {
            AudioEvent newEv = {.stime = endgroupTime, .tempCueTime = -1, .audioBuffer = AudioSequence_endgMarker};
            AudioEventAr_insert(&self->events, index, newEv, err);
            Error_returnVoidOnError(err);
        }
    }

    self->sequenceLength = sequenceLength;
    FloatEvent newEv = {.stime = sequenceLength, .audioBuffer = AudioSequence_cycleMarker};
    AudioEventAr_push(&self->events, newEv);
    AudioEventAr_sort(&self->events);

    // Now copy all events to events2
    AudioEventAr_truncate(&self->events2);
    AudioEventAr_foreach(it, &self->events) {
    	AudioEventAr_push(&self->events2, *it.var);
    } 

    return;
}
