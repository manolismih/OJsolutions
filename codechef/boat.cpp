#include <cstdio>
#include <cstring>
int t, n, m, akmes[25][2], max;
char sinola[25];
int main()
{
	scanf("%i",&t);
	for (int i=0; i<t; i++)
	{
		max=0, memset(sinola,0,25);
		scanf("%d%d",&n,&m);
		for (int i=0; i<m; i++)
		{
			scanf("%d%d",&akmes[i][0],&akmes[i][1]);
			sinola[akmes[i][0]]++, sinola[akmes[i][1]]++;
			if (max < sinola[akmes[i][0]]) max = sinola[akmes[i][0]];
			if (max < sinola[akmes[i][1]]) max = sinola[akmes[i][1]];
		}
		if (max>2 || max>1 && m>2 || max==1 && m>1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

