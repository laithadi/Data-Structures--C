 /*
 -------------------------------------------------------
 Project: cp264a1q1
 File:  a2q3.c
 -------------------------------------------------------
 Author:  Laith Adi
 Version:  2020-01-24
 -------------------------------------------------------
 */

#include <stdio.h>
#include <math.h>
#define ABS(x) x < 0 ? -x : x
#define REALSMALL(x) (int) (x < 1e-6)

float horner(float *p, int n, float x);
float bisection(float *p, int n, float a, float b);

float
horner(float *p, int n, float x)
{
	float r = 0;
	while (n--)
		r += *(p++) * pow(x, n);
	return r;
}

float
bisection(float *p, int n, float a, float b)
{
	float r = a;
	while (!REALSMALL(ABS(b - a))) {
		if (REALSMALL(ABS(horner(p, n, (r = (a + b) / 2)))))
			b = a;
		else if (horner(p, n, a) * horner(p, n, r) < 0)
			b = r;
		else
			a = r;
	}
	return r;
}
