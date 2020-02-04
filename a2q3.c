 /*
 -------------------------------------------------------
 Project: cp264a1q1
 File:  a2q3.c
 -------------------------------------------------------
 Author:  Laith Adi
 Version:  2020-01-24
 -------------------------------------------------------
 */

#include "bisection.h"

int main(int argc, char* args[])
{
	float p[] = {1, 2, 3, 4};
	int n = 4;
	float a = -2, b = 2;

	float pa = horner(p, n, a);
	float pb = horner(p, n, b);
	printf("f(%f): %f\n", a, pa);
	printf("f(%f): %f\n", b, pb);

	if (pa * pb < 0) {
	   float r = bisection(p, n, a, b);
	   printf("root: %f\n", r);
	   printf("f(%f): %f\n", r, horner(p, n, r));
	}
	return 0;
}

