// classes example
#include "stdafx.h"
#include "DiskWavSink.h"
#include <stdio.h>
#include <assert.h>
#include "kiss_fft.h"
#include "kiss_fftr.h"
#include <iostream>

PWAVEFORMATEX m_pwfx;
byte* recordBuffer;;
int maxSamples;
int heldSamples = 0;

DiskWavSink::DiskWavSink()
{
}


DiskWavSink::~DiskWavSink()
{
}



HRESULT AudioSink::SetFormat(PWAVEFORMATEX pwfx, UINT32 bufferSize){
	m_pwfx = pwfx;
	recordBuffer = new byte[bufferSize * pwfx->nBlockAlign];
	std::cout << "Record buffer set to: " << (bufferSize * pwfx->nBlockAlign) << " bytes " << std::endl;
	return 0l;
}

float readfloat(BYTE * buffer, int offset) {

	if (buffer == NULL){
		return 0;
	}
	byte pbyte = buffer[offset];
	if (offset % 4 == 0){
		//data is aligned
		return  *(int*)(buffer + offset);
	}
	throw ExceptionNestedException;
	
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

int offset;





HRESULT AudioSink::CopyData(BYTE *data, UINT32 availableFrames, BOOL *done){

	memcpy((void*)recordBuffer, data, availableFrames * m_pwfx->nBlockAlign);



	for (size_t i = 0; i < availableFrames; i++)
	{

		std::cout << (short) data[i] << std::endl;

	}




	//for (size_t i = 0; i < availableFrames; i = i + 2 * sizeof(float))
	//{
	//	float left = readfloat(data, i);
	//	float right = readfloat(data, i + sizeof(float));
	//	float total = left + right;
	//	realSamples[i / (2 * sizeof(float))] = total;
	//}

	//std::cout << std::endl;
	//kiss_fft_cpx * complexOut = new kiss_fft_cpx[numberOfSamples];
	//TestFftReal("SOMETHING", realSamples, complexOut, numberOfSamples);
	//delete[] (complexOut);

	return 0;
}




