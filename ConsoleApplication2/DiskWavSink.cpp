// classes example
#include "stdafx.h"
#include "DiskWavSink.h"
#include <stdio.h>
#include <iostream>

DiskWavSink::DiskWavSink()
{
}


DiskWavSink::~DiskWavSink()
{
}

HRESULT DiskWavSink::SetFormat(PWAVEFORMATEX pwfx){
	return 0;
}


HRESULT DiskWavSink::CopyData(BYTE *data, UINT32 availableFrames, BOOL *done){

	for (UINT32 i = 0; i < availableFrames; i++)
	{
		std::cout << *(data + i);
	}
	std::cout << std::endl;

	return 0;
}
