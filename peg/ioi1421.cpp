#include <cstdio>

int n,seq[100005];

bool valid()
{
	bool *emf = new bool[250005]();
	int start, next;
	for (start=0; start<n && seq[start]>=n; start++);
	if (start==n) return 1;
	
	next = (seq[start]+1)%n;
	for (int i=(start+1)%n; i!=start; i=(i+1)%n, next=(next+1)%n)
		if (seq[i] != next)
			if (seq[i]<n || orig[seq[i]]) return 0;
			else orig[seq[i]] = 1;
	return true;
}

int main()
{
	int task;
	scanf("%d%d",&task,&n);
	for (int i=0; i<n; i++) scanf("%d",&seq[i]);
	for (int i=0; i<n; i++) seq[i]--;
	if (task<4) printf("%d\n",valid());
}
