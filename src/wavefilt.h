/*
Copyright (c) 2014, Rafat Hussain
Copyright (c) 2016, Holger Nahrstaedt
*/
#ifndef WAVEFILT_H_
#define WAVEFILT_H_

#include <stdio.h>
#include "conv.h"
#define _USE_MATH_DEFINES
#include "math.h"

#ifdef __cplusplus
extern "C" {
#endif


int filtlength(const char* name);

int filtcoef(const char* name, float *lp1, float *hp1, float *lp2, float *hp2);

void copy_reverse(const float *in, int N, float *out);
void qmf_even(const float *in, int N, float *out);
void qmf_wrev(const float *in, int N, float *out);
void copy(const float *in, int N, float *out);
#ifdef __cplusplus
}
#endif


#endif /* WAVEFILT_H_ */