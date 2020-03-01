#include <cstdio>
#include <cstring>

int r,c,h,w,half, lessequal[3005], pista[3005][3005];

bool check(int val)
{
	for (int y=0; y<h; y++)
		for (int x=0; x<c; x++)
			if (pista[y][x] <= val) lessequal[x]++;
	int curr=0;
	
	for (int x=0; x<w; x++) curr += lessequal[x];
	if (curr > half) return 1;
	for (int x=w; x<c; x++)
	{
		curr += lessequal[x];
		curr -= lessequal[x-w];
		if (curr > half) return 1;
	}
	
	for (int y=h; y<r; y++)
	{
		curr=0;
		for (int x=0; x<w; x++)
		{
			if (pista[y][x] <= val) lessequal[x]++;
			if (pista[y-h][x] <= val) lessequal[x]--;
			curr += lessequal[x];
		}
		if (curr > half) return 1;
		for (int x=w; x<c; x++)
		{
			if (pista[y][x] <= val) lessequal[x]++;
			if (pista[y-h][x] <= val) lessequal[x]--;
			curr += lessequal[x];
			curr -= lessequal[x-w];
			if (curr > half) return 1;
		}
	}
	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d%d",&r,&c,&h,&w);
	half = h*w/2;
	for (int y=0; y<r; y++)
		for (int x=0; x<c; x++) 
			scanf("%d",&pista[y][x]);
	int from=1,to=r*c, middle;
	while (from != to)
	{
		middle = (from+to)/2;
		memset(lessequal,0,12020);
		if (check(middle)) to = middle;
		else from = middle+1;
	}
	printf("%d\n",from);
	return 0;
}

