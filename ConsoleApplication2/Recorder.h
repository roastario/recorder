#pragma once
#include "AudioSink.h"
class Recorder
{
public:
	Recorder();
	~Recorder();
	HRESULT RecordAudioStream(AudioSink *sink);
};

