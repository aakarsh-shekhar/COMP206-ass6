#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

//#include<sys/types.h>
//#include<sys/wait.h>

#include "consumer.c"
#include "producer.c"

int fileSize();

int main()
{

	FILE *r;

	r = fopen("TURN.txt", "w");	
	fprintf(r, "%c", '0');
	fclose(r);

	int ans = 0;
	int x=0;
	const int size=fileSize();
	int counterP=0;
	int counterC=0;
	char turn = '\0';

	int pid = fork();

	do
	{
		r = fopen("TURN.txt", "r+");
		turn = fgetc(r);
		fclose(r);

		if(pid == 0 && turn == '0')
		{
			ans = producer(counterP);
			counterP++;
			r = fopen("TURN.txt", "w");	
			fprintf(r,"%c", '1');
			fclose(r);
			wait();
		}

		if(pid != 0 && turn == '1')
		{
			consumer();
			counterC++;
			r = fopen("TURN.txt", "w");	
			fprintf(r,"%c", '0');
			fclose(r);
			wait();
		}

		if(ans == 1 ||pid == -1)
			exit;
	x++;
	size;
	//printf("x-%d : turn-%c : ans-%d : pid-%d : size-%d\n", x, turn, ans, pid, counterP);
	}while(counterP < size && ans != 1 && counterC < size);

	return 0;
}


int fileSize()
{
	int size = 0;

	FILE *file;

	file = fopen("mydata.txt", "r+");

	fgetc(file);

	while(!feof(file))
	{
		fgetc(file);
		size++;
	}

	
	fclose(file);

	return size;
}