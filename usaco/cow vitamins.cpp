/*
ID:manolis2
PROG:holstein
LANG:C++
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

FILE *input = fopen("holstein.in","r");
FILE *output = fopen("holstein.out","w");
int vitamins, requirements[25], nfoods, foods[15][25];

struct node{
	vector<int> eaten;
	int vitlevels[25];
};
queue<node> bfsqueue;

void process(node current)
{
	bool found=true;
	for (int i=0; i<vitamins; i++)
		if (current.vitlevels[i]<requirements[i])
		{
			found = false;
			break;
		}
	if (found)
	{
		fprintf(output,"%i",current.eaten.size());
		for (int i=0; i<current.eaten.size(); i++)
			fprintf(output,"%c%i",' ',current.eaten[i]+1);
		fprintf(output,"\n");
		exit(0);
	}
	
	node temp;
	temp.eaten=current.eaten;
	int i;
	if (current.eaten.empty())
		i=0;
	else
		i=current.eaten.back()+1;
	for (; i<nfoods; i++)
	{
		temp.eaten.push_back(i);
		for (int j=0; j<vitamins; j++)
			temp.vitlevels[j] = current.vitlevels[j]+foods[i][j];
		bfsqueue.push(temp);
		temp.eaten.pop_back();
	}
}

int main()
{
	fscanf(input,"%i",&vitamins);
	for (int i=0; i<vitamins; i++)
		fscanf(input,"%i",&requirements[i]);
	fscanf(input,"%i",&nfoods);
	for (int i=0; i<nfoods; i++)
		for (int j=0; j<vitamins; j++)
			fscanf(input,"%i",&foods[i][j]);
			
	node initial;
	vector<int> sinitial;
	initial.eaten = sinitial;
	for (int i=0; i<25; i++)
		initial.vitlevels[i]=0;
	bfsqueue.push(initial);
	
	while (!bfsqueue.empty())
	{
		process(bfsqueue.front());
		bfsqueue.pop();
	}
		
	return 0;
}

