#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

//#include<sys/types.h>
// #include<sys/wait.h>

#include "consumer.c"
#include "producer.c"

int main()
{

	FILE *r;
	r = fopen("TURN.txt", "r+w");	

	fseek( r, 0, SEEK_SET);	
	fprintf(r,"%c\n", '0');

	int pid = fork();

	char turn = fgetc(r);

	if(pid == -1)
		exit(1);

	if(pid == 0) //&& turn == '0')
	{
		printf("producer\n");
		producer();
		fseek( r, 0, SEEK_SET);
		fprintf(r,"%c", '1');
		wait();
	}

	if(pid != 0) //&& turn != '0')
	{
		printf("consumer\n");
		consumer();
		fseek( r, 0, SEEK_SET);
		fprintf(r,"%c\n", '0');
		wait();
	}

	fclose(r);

	return 0;
}