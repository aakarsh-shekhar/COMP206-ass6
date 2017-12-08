#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void removeChar(FILE *p);

void producer()
{ 
	FILE *q;
	FILE *buffer;
	
	printf("inside PRODUCER\n");

	q = fopen("mydata.txt", "r");
	buffer = fopen("DATA.txt","a");

	char c = fgetc(q);
	while (!feof(q))
	{
		//removeChar(q);
		//printf("buffer1: %c", c);
		fprintf(buffer,"%c\n", c);
		if(!feof(q))
			c = fgetc(q);
		else
			break;
	}
	fclose(buffer);
	fclose(q);
}

void removeChar(FILE *p)
{
	p = fopen("mydata.txt", "r+w");

	char c = fgetc(p);
	while(!feof(p))
	{
		c = fgetc(p);
		fseek( p, -1, SEEK_CUR );
		fprintf(p,"%c", c);
	}

	fclose(p);
}