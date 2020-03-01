#include <cstdio>

int n,m;
bool amatrix[1005][1005], vis[1005][1005][2];

inline int prev(int x) {	return x>1 ? x-1 : n;}
inline int next(int x) {	return x<n ? x+1 : 1;}

bool test(int v1, int v2, bool city) //exoume visited v1,next(v1),...,prev(v2),v2. An city=0 eimaste sto v1
{
	if (prev(v1) == v2)
	{
		printf("%d\n",city ? v2 : v1);
		return 1;
	}
	if (vis[v1][v2][city]) return 0;
	vis[v1][v2][city]=1;
	int curr = city ? v2 : v1;
	if (amatrix[curr][prev(v1)] && test(prev(v1),v2,0) || amatrix[curr][next(v2)] && test(v1,next(v2),1))
	{
		printf("%d\n",curr);
		return 1;
	}
	return 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int a,b, i=0; i<m; i++)
	{
		scanf("%d%d",&a,&b);
		amatrix[a][b] = amatrix[b][a] = 1;
	}
	for (int i=1; i<=n; i++)
		if (test(i,i,0)) return 0;
	printf("-1\n");
}
