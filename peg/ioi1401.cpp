#include <cstdio>
#include <cstring>

int n, pista[1005][1005], stiles[1005];

int ways(int size)
{
	memset(stiles,0,1005*4);
	int ret=0;
	for (int y=1; y<size; y++)
		for (int x=1; x<=n; x++)
			stiles[x] += pista[y][x];
			
	for (int y=size; y<=n; y++)
	{
		int bad=0;
		for (int x=1; x<size; x++)
		{
			stiles[x] += pista[y][x] - pista[y-size][x];
			bad += stiles[x];
		}
		for (int x=size; x<=n; x++)
		{
			stiles[x] += pista[y][x] - pista[y-size][x];
			bad += stiles[x] - stiles[x-size];
			if (!bad) ret++;
		}
	}
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		{
			scanf("%d",&pista[i][j]);
			pista[i][j] = !pista[i][j];
		}
			
			
	int from=1, to=n, middle;
	while (from != to)
	{
		middle = (from+to)/2 + 1;
		if (ways(middle)) from = middle;
		else to = middle-1;
	}
	printf("%d\n",to*ways(to));
	return 0;
}

