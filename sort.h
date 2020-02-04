#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second);
void display_array(int *a, int n);

void selection_sort(int *a, int left, int right);
void quick_sort(int *a, int left, int right);
void copy_array(int *a, int *b, int n);
int is_sorted(int *a, int n);

void display_array(int *a, int n)
{
  int i;
  for (i=0; i<n; ++i) {
    if (i%10 == 0) printf("\n");
      printf("%3d ", *(a+i));
  }
  printf("\n");
}

void swap(int *first, int *second)
{
  int temp = *first;
  *first = *second;
  *second = temp;
}


void copy_array(int *a, int *b, int n)
{
	// for loop to iterate through a and making the value at that address equal b
	for (int i = 0; i < n; i++) {
		// gab the address of b and make it point to a
		*b = *a;
		b += 1;
		a += 1;

	}
}

int is_sorted(int *a, int n)
{
	if (n == 0)
		return 1;   // Edge case

	int previous_value= *a;

	while (n)
	{
	   if (*a < previous_value)
			 return 0;
	   previous_value= *a;

	   ++a;
	   --n;
	 }
	 return 1;
}


void selection_sort(int *a, int left, int right)
{
	int k;

	for (int i = 0; i < right + 1; i++) {
		k = i;
		for (int j = i+1; j < right + 1; j++) {
			if (*(a+j) < *(a+k)) {
				k = j;
			}
		}

		if (i != k) {
			swap(a+k, a+i);
		}
	}

}



void quick_sort(int *a, int left, int right)
{

	if (left >= right)
		return;

	int pivot = left, i = left, j = right;

	while(i < j) {
		while(*(a+i) <= *(a+pivot) && i < right)
			i++;
		while(*(a+j) > *(a+pivot))
			j--;
		if(i < j)
			swap(a+i, a+j);
	}

	swap(a+pivot, a+j);
	quick_sort(a, left, j-1);
	quick_sort(a, j+1, right);
}












