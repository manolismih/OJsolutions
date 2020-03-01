#include <cstdio>
#include <algorithm>
#define incmarks ++marks[0],++marks[1],++marks[2]
#define decmarks --marks[0],--marks[1],--marks[2]
#define cpmarks data[datai].dna[0]=dna[0][i], data[datai].dna[1]=dna[1][i], data[datai].dna[2]=dna[2][i]
using namespace std;

FILE *fin=fopen("chimin.txt","r"), *fout=fopen("chimout.txt","w");
int n, marks[3];
char dna[3][100005];

struct node{
	char dna[3];
	int priority, set;
};
node data[100005];

bool compare(node a, node b)
{
	if (a.priority != b.priority) return a.priority<b.priority;
	else return marks[a.set] < marks[b.set];
}
int min3()
{
	if (marks[0] < marks[1])
		if (marks[0] < marks[2])
			return 0;
		else return 2;
	if (marks[1] < marks[2])
		return 1;
	else return 2;
}

int main()
{
	fscanf(fin,"%d",&n);
	for (int i=0; i<3; i++)
		fscanf(fin,"%s",dna[i]);
	int datai=0;
	for (int i=0; i<n; i++)
		if (dna[0][i] == dna[1][i])
			if (dna[0][i] == dna[2][i])
				incmarks;
			else
			{
				cpmarks;
				data[datai].set=2;
				data[datai++].priority=2;
				++marks[0],++marks[1];
			}
		else if (dna[0][i] == dna[2][i])
		{
			cpmarks;
			data[datai].set=1;
			data[datai++].priority=2;
			++marks[0],++marks[2];
		}
		else if (dna[1][i] == dna[2][i])
		{
			cpmarks;
			data[datai].set=0;
			data[datai++].priority=2;
			++marks[1],++marks[2];
		}
		else
		{
			cpmarks;
			data[datai].set=-1;
			data[datai++].priority=1;
		}
	sort(data,data+datai,compare);
	
	int i=0;
	for (; data[i].priority==1; i++)
		marks[min3()]++;
	
	int best=marks[min3()];
	for (;i<datai; i++)
	{
		decmarks;
		marks[data[i].set] += 2;
		if (marks[min3()] <= best) break;
		else best = marks[min3()];
	}
	
	fprintf(fout,"%d\n",best);
	return 0;
}

