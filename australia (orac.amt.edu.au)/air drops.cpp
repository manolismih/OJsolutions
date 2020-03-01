#include <cstdio>

int n, pos[1005], ans;
bool exist[10000005];

int main()
{
	freopen("dropin.txt","r",stdin);
	freopen("dropout.txt","w",stdout);
	scanf("%d",&n);
	if (n==1)
	{
		printf("1\n");
		return 0;
	}
	for (int i=0; i<n; i++)
	{
		scanf("%d",&pos[i]);
		exist[pos[i]] = true;
	}
	
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
		{
			int dist = pos[j]-pos[i], curr=2;
			for (int k=pos[j]+dist; k<=10000000 && exist[k]; k+=dist,curr++) ;
			if (curr>ans) ans=curr;
		}
	printf("%d\n",ans);
	return 0;
}

