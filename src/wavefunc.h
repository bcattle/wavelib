#ifndef WAVEFUNC_H_
#define WAVEFUNC_H_

#include "cwtmath.h"

#ifdef __cplusplus
extern "C" {
#endif

void meyer(int N,float lb,float ub,float *phi,float *psi,float *tgrid);

void gauss(int N,int p,float lb,float ub,float *psi,float *t);

void mexhat(int N,float lb,float ub,float *psi,float *t);

void morlet(int N,float lb,float ub,float *psi,float *t);  


#ifdef __cplusplus
}
#endif


#endif /* WAVEFUNC_H_ */
