#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,init[200005],x[600005],y[600005];
int seq[200005],emf[200005],dest[200005],start[200005]; // emf is f-1 of seq and start is f-1 of dest

void swp(int a, int b, bool player, bool write)
{
	if (write) printf("%d %d\n",a,b);
	swap(seq[a],seq[b]);
	swap(emf[seq[a]],emf[seq[b]]);
	if (player) return;
	swap(dest[a],dest[b]);
	swap(start[dest[a]],start[dest[b]]);
}

bool check(int t, bool write)
{
	for (int i=0; i<n; i++)
	{
		seq[i] = init[i];
		start[i] = i;
		emf[init[i]] = i;
	}
	for (int i=0; i<t; i++) swap(start[x[i]],start[y[i]]);
	for (int i=0; i<n; i++) dest[start[i]] = i;
	
	int curr=0;
	for (int i=0; i<t; i++)
	{
		swp(x[i],y[i],0,0);
		while (curr < n && emf[curr] == start[curr]) curr++;
		if (curr==n)
			if (write) printf("0 0\n");
			else return true;
		else swp(emf[curr],start[curr],1,write);
	}
	while (curr < n && emf[curr] == start[curr]) curr++;
	return curr==n;
}

int main()
{
	scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%d",&init[i]);
	scanf("%d",&m);
	for (int i=0; i<m; i++) scanf("%d%d",&x[i],&y[i]);
	
	int from=0,to=m,middle;
	while (from<to)
	{
		middle = (from+to)/2;
		if (check(middle,0)) to = middle;
		else from = middle+1;
	}
	printf("%d\n",from); 
	check(from,1); 
}
