/*
Project: a3q3
File: a3q3.c
Description: public test driver
Author: Laith Adi
Version: 2020-01-23
*/
#include "mystring.h"

int letter_count(char *s)
{
	int count = 0;

	for (int i = 0; i < 100; i++) {
		if (isalpha((*(s+i))) != 0) {
			count += 1 ;
		}
	}

	return count;

}

void lower_case(char *s) {

	for (int i = 0; i < 100; i++) {
		if ((*(s+i)) >= 'A' && (*(s+i)) <= 'Z') {
			*(s+i) = *(s+i) + 32;
		}
	}
}

int word_count(char *s) {

	int count = 0, i = 0;

	while (*s != '\0') {

		if (*s == ' ') {
			i = 0;
		}

		else if (!i) {
			i = 1;
			count++;
		}

		s++;

	}

	return count;
}

void trim(char *s) {

	char n[strlen(s)+1];
	char *ptr = n;
	char *p = s;

		while (*p == ' ')
			p++;

		while (*p != '\0') {
			if (*p == ' ' && (*(p+1) == ' ' || *(p+1) == '\0'))
				p++;
			else {
				*ptr = *(p++);
				ptr++;
			}
		}

		strcpy(s, n);
}

int main(int argc, char* args[]) {
  setbuf(stdout, NULL);
  char str[100] = "     This Is    a Test   ";
  printf("\nInput string: \"%s\"", str);
  printf("\nLetter count:%d", letter_count(str));
  printf("\nWord count:%d", word_count(str));
  trim(str);
  printf("\nAfter trimming:\"%s\"", str);
  lower_case(str);
  printf("\nAfter lower case:\"%s\"", str);

  return 0;
}


