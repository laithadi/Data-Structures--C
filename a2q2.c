 /*
 -------------------------------------------------------
 Project: cp264a1q1
 File:  a2q2.c
 -------------------------------------------------------
 Author:  Laith Adi
 Version:  2020-01-24
 -------------------------------------------------------
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float horner(float p[], int n, float x)
{
	float result = 0;

	for (int i = 0; i<=n; i++) {
		result += p[i] * pow(x, n - i);
	}

	return result;
}

int main(int argc, char* args[])
{
    //get polynomial efficients from command line arguments
    if (argc <= 1) {
        printf("Need more than one arguments, e.g.: 1 2 3 4\n");
        return 0;
    }

    int n = argc-1, i;

    // declare float array data structure for coefficients
    float coefficients[n];
    // read command line arguments convert them to floating numbers atof(args[i+1]);
    for (i = 1; i <= n; i++) {
    		coefficients[i] = atof(args[i]);
    	}

    // repetitive polynomial evaluation for user input of x value
    float x = 0.0;
    do {
        //get x value from keyboard
        do {
            printf("Please enter x value (Ctrl+C or 999 to quit):\n");
            if (scanf("%f", &x) != 1) {
                printf("Invalid input\n");
            } else {
                break;
            }
            // flush the input buffer
            while(getchar() !='\n');
        } while (1);

        // write your code
        // escape when input 999
        if (x == 999) {
        	break;
        }
        // print the polynomial expression
        for (int i = 1; i<=n; i++) {
        	if (i<n) {
        		printf("%.1f*%.1f^%d + ", coefficients[i], x, n - i);
        	}
        	else {
        		printf("%.1f*%.1f^%d = ", coefficients[i], x, n - i);
        	}
        }
        printf("%.1f\n", horner(coefficients, n, x));
        // use x^n to denote x raised to the n-th power
        // use %.1f format for floating number
        // get polynomial's value by calling horner(p, n, x)

    } while (1);

    return 0;
}
