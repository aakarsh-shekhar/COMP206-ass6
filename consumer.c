#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void consumer()
{
	char c;
	FILE *p;

	p = fopen("DATA.txt", "r");

	c = fgetc(p);

	while(!feof(p))
	{
		printf("%c", c);
		c = fgetc(p);
	}

	fclose(p);
}
