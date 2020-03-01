#include <cstdio>

int t, n, m, sinola[20];

int main()
{
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		int a,b, max=0;
		scanf("%d%d",&n,&m);
		for (int i=0; i<m; i++)
		{
			scanf("%d%d",&a,&b);
			sinola[a]++, sinola[b]++;
			if (max < sinola[a]) max = sinola[a];
			if (max < sinola[b]) max = sinola[b];
		}
		if (max==2)
			printf("%d\n",2*n+1);
		else 
			printf("%d\n",2*n-1);
	}
	return 0;
}

