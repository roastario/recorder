// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "DiskWavSink.h"
#include "Recorder.h"
#include "kiss_fft.h"


int _tmain(int argc, _TCHAR* argv[])
{

	AudioSink * diskSink = new DiskWavSink();
	Recorder * recorder = new Recorder();

	HRESULT result = recorder->RecordAudioStream(diskSink);

	return result;
}
