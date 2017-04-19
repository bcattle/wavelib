/*
Copyright (c) 2014, Rafat Hussain
*/
#ifndef WTMATH_H_
#define WTMATH_H_

#include "wavefilt.h"

#ifdef __cplusplus
extern "C" {
#endif

int upsamp(float *x, int lenx, int M, float *y);

int upsamp2(float *x, int lenx, int M, float *y);

int downsamp(float *x, int lenx, int M, float *y);

int per_ext(float *sig, int len, int a,float *oup);

int symm_ext(float *sig, int len, int a,float *oup);

void circshift(float *array, int N, int L);

int testSWTlength(int N, int J);

int wmaxiter(int sig_len, int filt_len);

float costfunc(float *x, int N, char *entropy, float p);

#ifdef __cplusplus
}
#endif


#endif /* WAVELIB_H_ */
