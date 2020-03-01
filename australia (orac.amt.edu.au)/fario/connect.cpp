#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>
using namespace std;

//general
int n, pista[200005], emf[2][100005], connected[200005], up[200005], down[200005], upi, downi;

//segment tree
int val[900000];

void set(int pos, int x, int i=1, int beg=1, int end=2*n)
{
	if (beg==end) val[i]=x;
	else
	{
		int middle = (beg+end)/2;
		if (pos<=middle) set(pos,x,2*i,beg,middle);
		else set(pos,x,2*i+1,middle+1,end);
		val[i] = max(val[2*i],val[2*i+1]);
	}
}

int query(int from, int to, int x, int i=1, int beg=1, int end=2*n)
{
	if (from>to) return 0;
	if (from == to)
		if (from == emf[0][pista[from]] && emf[1][pista[from]] > x) return from;
		else return 0;
	if (from==beg && to==end && val[i]<=x) return 0;
	
	int middle = (beg+end)/2;
	int ret1 = query(from,min(middle,to) ,x,2*i,beg,middle);
	if (ret1) return ret1;
	else return query(max(middle+1,from),to,x,2*i+1,middle+1,end);
}

void impossible()
{
	printf("0\n");
	exit(0);
}

void connect(int pos, int way)
{
	while (upi && up[upi]<=pos) upi--;
	while (downi && down[downi]<=pos) downi--;
	int pos2 = emf[1][pista[pos]];
	if (way==1) // up
		if (upi && up[upi]<pos2) impossible();
		else up[++upi] = pos2;
	if (way==2) // down
		if (downi && down[downi]<pos2) impossible();
		else down[++downi] = pos2;
	connected[pos] = connected[pos2] = way;
}

void fix(int from, int to, int outway)
{
	int next = query(from,to,to+1);
	if (next)
	{
		if (outway==1) up[++upi] = next;
		else down[++downi] = next;
		connected[next] = outway+2;
	}
	else connect(from,1);
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=2*n; i++)
	{
		scanf("%d",&pista[i]);
		if (!emf[0][pista[i]]) emf[0][pista[i]] = i;
		else
		{
			emf[1][pista[i]] = i;
			set(emf[0][pista[i]],emf[1][pista[i]]);
		}	
	}
	for (int i=1; i<=2*n; i++)
		while (connected[i] != 1 && connected[i] != 2)
			if (!connected[i])
			{
				while (upi && up[upi]<=i) upi--;
				while (downi && down[downi]<=i) downi--;
				if (!upi && !downi) connect(i,1);
				else if (!upi) fix(i,down[downi]-1,1);
				else if (!downi) fix(i,up[upi]-1,2);
				else if (up[upi] < down[downi]) fix(i,up[upi]-1,2);
				else fix(i,down[downi]-1,1);
			}
			else if (connected[i] > 2) connect(i,connected[i]-2);
	for (int i=1; i<=2*n; i++) printf("%d\n",connected[i]);		
	return 0;
}
