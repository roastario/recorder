// classes example
#include "stdafx.h"
#include "DiskWavSink.h"
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "kiss_fft.h"
#include "kiss_fftr.h"

UINT32 samplesPerSecond;
UINT32 numberOfChannels;
PWAVEFORMATEX m_pwfx;

DiskWavSink::DiskWavSink()
{
}


DiskWavSink::~DiskWavSink()
{
}

HRESULT AudioSink::SetFormat(PWAVEFORMATEX pwfx){
	m_pwfx = pwfx;
	return 0l;
}

float readfloat(BYTE * buffer, int offset) {

	float result = 0;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << *(buffer + offset + i) << ", " ;
		*((BYTE *) (&result) + (3 - i)) = *(buffer + offset + i);
	}

	return result;
}

void TestFftReal(const char* title, const kiss_fft_scalar *in, kiss_fft_cpx *out, int N)
{
	kiss_fftr_cfg cfg;

	if ((cfg = kiss_fftr_alloc(N, 0/*is_inverse_fft*/, NULL, NULL)) != NULL)
	{
		size_t i;
		kiss_fftr(cfg, in, out);
		free(cfg);
	}
	else
	{
		printf("not enough memory?\n");
		exit(-1);
	}
}

HRESULT AudioSink::CopyData(BYTE *data, UINT32 availableFrames, BOOL *done){

	int numberOfSamples = availableFrames / 4;
	assert(numberOfSamples);

	float * realSamples = new float[numberOfSamples];

	for (size_t i = 0; i < availableFrames; i = i + 2 * sizeof(float))
	{
		float left = readfloat(data, i);
		float right = readfloat(data, i + sizeof(float));
		float total = left + right;
		realSamples[i / (2 * sizeof(float))];
	}

	std::cout << std::endl;
	kiss_fft_cpx * complexOut = new kiss_fft_cpx[numberOfSamples];
	TestFftReal("SOMETHING", realSamples, complexOut, numberOfSamples);
	free(realSamples);
	free(complexOut);

	return 0;
}




