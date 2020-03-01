/*
ID:manolis2
PROG:milk4
LANG:C++11
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define inf 200

short q,n,cap[105], dp[20005][105][2]; //dp[poso][pail][(bool)taken once] 

void read()
{
	freopen("milk4.in","r",stdin);
	freopen("milk4.out","w",stdout);
	scanf("%hd%hd",&q,&n);
	bool helpar[10005]={0};
	for (int num,i=0; i<n; i++)
	{
		scanf("%d",&num);
		helpar[num]=1;
	}
	n=0;
	bool add;
	for (int i=1; i<10005; i++)
		if (helpar[i])
		{
			add=1;
			for (int j=0; add && j<n; j++)
				if (!(i%cap[j])) add=0;
			if (add) cap[n++] = i;
		}	
}

int main()
{
	read();
	for (int poso=1; poso<=q; poso++)
		for (int pail=0; pail<=n; pail++)
			dp[poso][pail][0] = dp[poso][pail][1] = inf;
	dp[0][n][0] = dp[0][n][1] = inf;
		
	for (int poso=cap[0]; poso<=q; poso++)
		for (int pail=n-1; pail>=0; pail--)
		{
			if (cap[pail] > poso) continue;
			dp[poso][pail][1] = min(        dp[poso-cap[pail]][pail][1],  dp[poso][pail+1][0]);
			dp[poso][pail][0] = min(short(1+dp[poso-cap[pail]][pail][1]), dp[poso][pail+1][0]);
		}	
	int best = dp[q][0][0];
	printf("%d",best);
	
	bool p1[20005]={0}, p2[20005]={0}, mod[10005]={0}, *master=p1, *temp=p2, found=0;
	master[q]=1;
	for (int pail=0; pail<n; pail++)
	{
		for (int i=q; i>=cap[pail]; i--)
			if (master[i] && dp[i-cap[pail]][pail][1]==best-1 && !mod[i%cap[pail]])
			{
				found = 1;
				mod[i%cap[pail]] = 1;
				for (int j=i-cap[pail]; j>-1 && dp[j][pail][1]==best-1; j-=cap[pail])
					temp[j]=1;
			}
		if (found)
		{
			best--;
			found=0;
			printf(" %d",cap[pail]);
			if (temp[0]) break;
			swap(master,temp);
			memset(temp,0,20005), memset(mod,0,cap[pail]);
		}
	}
	printf("\n");
	return 0;
}
