#include <cstdio>
#include <algorithm>
#define ipsos first
#define platos second
using namespace std;

int w,h,n, memo[605][605];
bool examined[605][605];
pair<int,int> sizes[205];

int wasted(int y, int x)
{
	if (examined[y][x]) return memo[y][x];
	examined[y][x] = 1;
	memo[y][x] = y*x;
	for (int i=0; i<n; i++)
		if (sizes[i].ipsos<=y && sizes[i].platos<=x)
		{
			if (wasted(y-sizes[i].ipsos,x) + wasted(sizes[i].ipsos,x) < memo[y][x])
				memo[y][x] = wasted(y-sizes[i].ipsos,x) + wasted(sizes[i].ipsos,x);
			if (wasted(y,x-sizes[i].platos) + wasted(y,sizes[i].platos) < memo[y][x])
				memo[y][x] = wasted(y,x-sizes[i].platos) + wasted(y,sizes[i].platos);
		}
	return memo[y][x];
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&w,&h,&n);
	for (int i=0; i<n; i++)
	{
		scanf("%d%d",&sizes[i].platos,&sizes[i].ipsos);
		examined[sizes[i].ipsos][sizes[i].platos] = 1;
	} 
	printf("%d\n",wasted(h,w));
	return 0;
}

