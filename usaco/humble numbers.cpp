/*
ID:manolis2
PROG:humble
LANG:C++11
*/

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

FILE *fin = fopen("humble.in","r"), *fout = fopen("humble.out","w");
struct node{
	int number,biggest;
};

inline node tonode(int a, int b)
{
	node ret={a,b};
	return ret;
}

inline bool compare(node a, node b)
{
	return a.number>b.number;
}

priority_queue<node,vector<node>,bool(*)(node,node)> oura(compare);
int primes[100];

int main()
{
	int n, k;
	fscanf(fin,"%i%i",&k,&n);
	for (int i=0; i<k; i++)
		fscanf(fin,"%i",&primes[i]);
	oura.push(tonode(1,0));
	long long number,from,biggest=0;
	for (int i=0; i<n; i++)
	{
		number = oura.top().number;
		from = oura.top().biggest;
		oura.pop();
		for (int j=from; j<k; j++)
		{
			if (oura.size() > n-i && number*primes[j] > biggest) break;	
			oura.push(tonode(number*primes[j],j));
			if (number*primes[j] > biggest)
				biggest = number*primes[j];
		}
			
	}
	fprintf(fout,"%i\n",oura.top().number);
	return 0;
}
