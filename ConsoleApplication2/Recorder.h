#pragma once
#include "DiskWavSink.h"
class Recorder
{
public:
	Recorder();
	~Recorder();
	HRESULT RecordAudioStream(DiskWavSink *sink);
};

