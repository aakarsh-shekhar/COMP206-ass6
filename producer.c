#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void removeChar(FILE *p);

void producer()
{ 
	FILE *q;
	FILE *buffer;

	q = fopen("mydata.txt", "r");
	buffer = fopen("DATA.txt","w");

	char c = fgetc(q);
	while (!feof(q))
	{
		fprintf(buffer,"%c", c);
		c = fgetc(q);
	}
	fclose(buffer);
	fclose(q);
}