#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>	

int producer(int i)
{
	int ans = 0;

	FILE *q;
	FILE *buffer;

	q = fopen("mydata.txt", "r");
	buffer = fopen("DATA.txt","w");

	fseek( q, i, SEEK_SET);
	char c = fgetc(q);

	if(c == EOF)
	{
		ans = 1;
		printf("*********************");
	}

	else
	{
		fprintf(buffer,"%c", c);
		ans = 0;
	}

	fclose(buffer);
	fclose(q);

	return ans;	
}