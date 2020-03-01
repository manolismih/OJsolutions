#include <cstdio>
#include <algorithm>

int t,n,q, rep[150005], rank[150005], eats[150005], eaten[150005], apantisi;

int find(int v)
{
	if (rep[v]==v) return v;
	return rep[v] = find(rep[v]);
}

int join(int v1, int v2)
{
	if (rank[v2]>rank[v1]) std::swap(v1,v2);
	if (rank[v1]==rank[v2]) rank[v1]++;
	rep[v2]=v1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d%d",&n,&q);
		for (int i=1; i<=3*n; i++)
		{
			rep[i] = i;
			rank[i]= 1;
			eats[i] = (n+i)%(3*n);
			eaten[eats[i]] = i;
		}
		apantisi = 0;
		
		for (int type,v1,v2,i=0; i<q; i++)
		{
			scanf("%d%d%d",&type,&v1,&v2);
			if (v1>n || v2>n)
			{
				apantisi++;
				continue;
			} 
			int f1=find(v1), f2=find(v2);
			if (f1==f2)
			{
				if (type==2) apantisi++;
				continue;
			}
			if (type==1)
				if (eats[f1]==f2 || eats[f2]==f1) apantisi++;
				else join(f1,f2), join(eats[f1],eats[f2]), join(eaten[f1],eaten[f2]);
			else
				if (eats[f2]==f1) apantisi++;
				else if (eats[f1] != f2) join(f2,eats[f1]), join(eats[f2],eaten[f1]), join(eaten[f2],f1);
		}
		printf("%d\n",apantisi);
	}
}
