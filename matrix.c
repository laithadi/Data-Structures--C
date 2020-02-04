/*
--------------------------------------------------
Project: cp264a3q2
File:    a3q2.c
Description: public test driver program
Author:  Laith Adi
Version: 2020-01-23
--------------------------------------------------
*/


//---------------------------------------------------------
void magic_square(int *m, int n) {
    /* assign 3X3 matrix to following values
     8     1     6
     3     5     7
     4     9     2
     */
    int values[9] = { 8, 1, 6, 3, 5, 7, 4, 9, 2 };
    int i, len = n*n, *p = values;
    for (i = 0; i < len; i++) *m++ = *p++;
}


//---------------------------------------------------------
void display_matrix(int *m, int n) {
    int *p = m, i, j;
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n; j++) printf("%4d", *p++);
    }
    printf("\n");
}

//---------------------------------------------------------
void transpose_matrix(int *m1, int *m2, int n) {
	int i, j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++) {
			*(m2 + (i*n) + j) = *(m1 + i + (j*n));
		}
	}
}

//---------------------------------------------------------
int is_magic_square(int *m, int n) {

	int rowsum = n*(n*n+1)/2;
	int sum;

	// check the rows add up to the sum
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += *(m + i*n + j);
		}
		// check to see if the sum of the row = rowsum
		if (sum != rowsum) {
			return 0;
			break;
		}
	}

	// check the columns add up to the sum
	for (int j = 0; j < n; j++) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += *(m + i*n + j);
		}
		// check if the sum of the column = rowsum
		if (sum != rowsum) {
			return 0;
			break;
		}
	}

	//For diagonal elements
   sum = 0;
   for ( int i = 0; i < n; i++) {
	  for (int j = 0; j < n; j++) {
		 if (i == j)
			sum += *(m + i*n +j);
	  }
   }

   if (sum != rowsum) {
	   return 0;
   }

	return 1;

}



//---------------------------------------------------------
void multiply_matrix(int *m1, int *m2, int *m3, int n) {
	int i,j,k,sum;
	for (i=0;i<n;i++) {
		for (j=0; j<4; j++) {
			sum =0;
			for (k=0; k<n; k++) {
				sum += (*(m1 + i*n + k)) * (*(m2 + k*n +j));
			}
			*(m3+i*n+j) =sum;
		}
	}
}


#include "matrix.h"

int main() {
  int n = 3;
  int m1[n][n];
  int m2[n][n];
  int m3[n][n];

  int *p1 = &m1[0][0];
  magic_square(p1, n);
  printf("\nm1:");
  display_matrix(p1, n);
  printf("is_magic_square:%d\n", is_magic_square(p1, n));

  int *p2 = &m2[0][0];
  printf("\nm1':");
  transpose_matrix(p1, p2, n);
  display_matrix(p2, n);
  printf("is_magic_square:%d\n", is_magic_square(p2, n));

  int *p3 = &m3[0][0];
  multiply_matrix(p1, p2, p3, n);
  printf("\nm1*m1':");
  display_matrix(p3, n);
  printf("is_magic_square:%d\n", is_magic_square(p3, n));

  return 0;
}
