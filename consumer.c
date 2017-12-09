#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void consumer()
{
	char c;
	FILE *p;

	p = fopen("DATA.txt", "r+");

	c = fgetc(p);

	printf("%c", c);

	fclose(p);
}
