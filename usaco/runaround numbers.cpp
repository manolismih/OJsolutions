/*
ID:manolis2
PROG:runround
LANG:C++11
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

FILE *input = fopen("runround.in","r");
FILE *output = fopen("runround.out","w");
int length, number[12] = {0};
char snumber[12];
bool avail[10] = {0,1,1,1,1,1,1,1,1,1}, visited[9]={0}, completed_once[9]={0};

bool check()
{
	bool visited[9] = {0};
	int i,count;
	for (i=0, count=0; !visited[i]; i=(i+number[i])%length, count++)
		visited[i]=true;
	return (count==length);
}

void findnextrunaround(int i)
{
	if (i==length && check())
	{
		for (i=0; i<length; i++)
			fprintf(output,"%i",number[i]);
		fprintf(output,"\n");
		exit(0);
	}
	for (int j=1; j<10; j++)
		if ((completed_once[i] || j>=number[i]) && avail[j] && (!visited[(i+j)%length] || i==length-1 && (i+j)%length==0)) 
		{
			avail[j] = false;
			visited[(i+j)%length] = true;
			number[i] = j;
			findnextrunaround(i+1);
			avail[j]=true;
			visited[(i+j)%length] = false;
		}
	completed_once[i]=true;
	return;
}

int main()
{
	fscanf(input,"%s",snumber);
	length = strlen(snumber);
	for (int i=0; i<length; i++)
		number[i] = int(snumber[i]) - int('0');
	number[length-1]++;
	for (int i=length-1; i>0 && number[i]==10; i--)
	{
		number[i]=0;
		completed_once[i]=true;
		number[i-1]++;
	}
	if (number[0] == 10)
	{
		number[0] = 0;
		length++;
	}
		
	for (;; length++)
		findnextrunaround(0); 
	return 0;
}

