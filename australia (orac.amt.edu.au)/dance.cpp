#include <cstdio>

int n,m,apantisi;
int hoops[100005];

int main()
{
	freopen("dancein.txt","r",stdin);
	freopen("danceout.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (int from,to,i=0; i<m; i++)
	{
		scanf("%d%d",&from,&to);
		if (!hoops[from]) apantisi++;
		else hoops[from]--;
		hoops[to]++;
	}
	printf("%d\n",apantisi);
	return 0;
}

