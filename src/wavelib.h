/*
Copyright (c) 2014, Rafat Hussain
*/
#ifndef WAVELIB_H_
#define WAVELIB_H_

#include "wtmath.h"
#include "cwt.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER)
#pragma warning(disable : 4200)
#pragma warning(disable : 4996)
#endif

#ifndef cplx_type
#define cplx_type float
#endif


typedef struct cplx_t {
	cplx_type re;
	cplx_type im;
} cplx_data;

typedef struct wave_set* wave_object;

wave_object wave_init(char* wname);

struct wave_set{
	char wname[50];
	int filtlength;// When all filters are of the same length. [Matlab uses zero-padding to make all filters of the same length]
	int lpd_len;// Default filtlength = lpd_len = lpr_len = hpd_len = hpr_len
	int hpd_len;
	int lpr_len;
	int hpr_len;
	float *lpd;
	float *hpd;
	float *lpr;
	float *hpr;
	float params[0];
};

typedef struct wt_set* wt_object;

wt_object wt_init(wave_object wave,char* method, int siglength, int J);

struct wt_set{
	wave_object wave;
	conv_object cobj;
	char method[10];
	int siglength;// Length of the original signal.
	int outlength;// Length of the output DWT vector
	int lenlength;// Length of the Output Dimension Vector "length"
	int J; // Number of decomposition Levels
	int MaxIter;// Maximum Iterations J <= MaxIter
	int even;// even = 1 if signal is of even length. even = 0 otherwise
	char ext[10];// Type of Extension used - "per" or "sym"
	char cmethod[10]; // Convolution Method - "direct" or "FFT"

	int N; //
	int cfftset;
	int zpad;
	int length[102];
	float *output;
	float params[0];
};

typedef struct wtree_set* wtree_object;

wtree_object wtree_init(wave_object wave, int siglength, int J);

struct wtree_set{
	wave_object wave;
	conv_object cobj;
	char method[10];
	int siglength;// Length of the original signal.
	int outlength;// Length of the output DWT vector
	int lenlength;// Length of the Output Dimension Vector "length"
	int J; // Number of decomposition Levels
	int MaxIter;// Maximum Iterations J <= MaxIter
	int even;// even = 1 if signal is of even length. even = 0 otherwise
	char ext[10];// Type of Extension used - "per" or "sym"

	int N; //
	int nodes;
	int cfftset;
	int zpad;
	int length[102];
	float *output;
	int *nodelength;
	int *coeflength;
	float params[0];
};

typedef struct wpt_set* wpt_object;

wpt_object wpt_init(wave_object wave, int siglength, int J);

struct wpt_set{
	wave_object wave;
	conv_object cobj;
	int siglength;// Length of the original signal.
	int outlength;// Length of the output DWT vector
	int lenlength;// Length of the Output Dimension Vector "length"
	int J; // Number of decomposition Levels
	int MaxIter;// Maximum Iterations J <= MaxIter
	int even;// even = 1 if signal is of even length. even = 0 otherwise
	char ext[10];// Type of Extension used - "per" or "sym"
	char entropy[20];
	float eparam;

	int N; //
	int nodes;
	int length[102];
	float *output;
	float *costvalues;
	float *basisvector;
	int *nodeindex;
	int *numnodeslevel;
	int *coeflength;
	float params[0];
};

typedef struct cwt_set* cwt_object;

cwt_object cwt_init(char* wave, float param, int siglength,float dt, int J);

struct cwt_set{
	char wave[10];// Wavelet - morl/morlet,paul,dog/dgauss
	int siglength;// Length of Input Data
	int J;// Total Number of Scales
	float s0;// Smallest scale. It depends on the sampling rate. s0 <= 2 * dt for most wavelets
	float dt;// Sampling Rate
	float dj;// Separation between scales. eg., scale = s0 * 2 ^ ( [0:N-1] *dj ) or scale = s0 *[0:N-1] * dj
	char type[10];// Scale Type - Power or Linear
	int pow;// Base of Power in case type = pow. Typical value is pow = 2
	int sflag;
	int pflag;
	int npad;
	int mother;
	float m;// Wavelet parameter param
	float smean;// Input Signal mean

	cplx_data *output;
	float *scale;
	float *period;
	float *coi;
	float params[0];
};


void dwt(wt_object wt, float *inp);

void idwt(wt_object wt, float *dwtop);

void wtree(wtree_object wt, float *inp);

void dwpt(wpt_object wt, float *inp);

void idwpt(wpt_object wt, float *dwtop);

void swt(wt_object wt, float *inp);

void iswt(wt_object wt, float *swtop);

void modwt(wt_object wt, float *inp);

void imodwt(wt_object wt, float *dwtop);

void setDWTExtension(wt_object wt, char *extension);

void setWTREEExtension(wtree_object wt, char *extension);

void setDWPTExtension(wpt_object wt, char *extension);

void setDWPTEntropy(wpt_object wt, char *entropy, float eparam);

void setWTConv(wt_object wt, char *cmethod);

int getWTREENodelength(wtree_object wt, int X);

void getWTREECoeffs(wtree_object wt, int X, int Y, float *coeffs, int N);

int getDWPTNodelength(wpt_object wt, int X);

void getDWPTCoeffs(wpt_object wt, int X, int Y, float *coeffs, int N);

void setCWTScales(cwt_object wt, float s0, float dj, char *type, int power);

void setCWTScaleVector(cwt_object wt, float *scale, int J, float s0, float dj);

void setCWTPadding(cwt_object wt, int pad);

void cwt(cwt_object wt, float *inp);

void icwt(cwt_object wt, float *cwtop);

int getCWTScaleLength(int N);

void wave_summary(wave_object obj);

void wt_summary(wt_object wt);

void wtree_summary(wtree_object wt);

void wpt_summary(wpt_object wt);

void cwt_summary(cwt_object wt);

void wave_free(wave_object object);

void wt_free(wt_object object);

void wtree_free(wtree_object object);

void wpt_free(wpt_object object);

void cwt_free(cwt_object object);


#ifdef __cplusplus
}
#endif


#endif /* WAVELIB_H_ */
