/*
ID:manolis2
PROG:checker
LANG:C++
*/

#include <cstdio>
#include <algorithm>

using namespace std;

FILE *input = fopen("checker.in","r");
FILE *output = fopen("checker.out","w");
int n, solutions=0, queengrames[13];
bool diag1[30], diag2[30];

// list
struct node{
	int data;
	node *next;
};
node *head; //  head->next is the first element in the list

void dfs(int depth)
{
	if (depth==n)
	{
		if (solutions<3)
		{
			for (int i=0; i<n-1; i++)
				fprintf(output,"%i%c",queengrames[i]+1,' ');
			fprintf(output,"%i\n",queengrames[n-1]+1);
		}
		solutions++;
		return;
	}
	
	node* prev=head;
	node* current=head->next;
	for ( ; current; prev=current,current=current->next)
 		if (diag1[depth+current->data] && diag2[depth-current->data+12])
		{
			diag1[depth+current->data]=false;
			diag2[depth-current->data+12]=false;
			queengrames[depth]=current->data;
			prev->next=current->next;
			dfs(depth+1);
			diag1[depth+current->data]=true;
			diag2[depth-current->data+12]=true;
			prev->next=current;	
		}

	return;
}

int main()
{
	fscanf(input,"%i",&n);
	for (int i=0; i<30; i++)
	{
		diag1[i]=true;
		diag2[i]=true;
	}
	head = new node;
	node *prev=head;
	for (int i=0; i<n; i++)
	{
		prev->next = new node;
		prev = prev->next;
		prev->data = i;
	}
	prev->next=0;
	dfs(0);
	fprintf(output,"%i\n",solutions);
	return 0;
}

