#pragma once
#include "stdafx.h"
#include "Audioclient.h"
#include "Audiopolicy.h"
#include "Mmdeviceapi.h"
class DiskWavSink
{
public:
	DiskWavSink();
	~DiskWavSink();

	HRESULT SetFormat(PWAVEFORMATEX pwfx);
	HRESULT CopyData(BYTE *data, UINT32 availableFrames, BOOL *done);

};

