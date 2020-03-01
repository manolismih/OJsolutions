#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,dim[3], x,y,z,q, tree[400005][3];
bool lazy[400005][3]; //x,y,z

void flip(int from, int to, int type, int i, int posfrom, int posto)
{
	if (from==posfrom && to==posto)
	{
		lazy[i][type] = !lazy[i][type];
		tree[i][type] = (to-from+1) - tree[i][type];
		return;
	}
	int middle = (posfrom+posto)/2;
	if (lazy[i][type])
	{
		flip(posfrom,middle,type,2*i,posfrom,middle);
		flip(middle+1,posto,type,2*i+1,middle+1,posto);
		lazy[i][type] = 0;
	}
	if (from<=middle) flip(from,min(middle,to),type,2*i,posfrom,middle);
	if (to>middle) flip(max(middle+1,from),to,type,2*i+1,middle+1,posto);
	tree[i][type] = tree[2*i][type] + tree[2*i+1][type];
}

int query(int from, int to, int type, int i, int posfrom, int posto)
{
	if (from==posfrom && to==posto) return tree[i][type];
	int middle = (posfrom+posto)/2;
	if (lazy[i][type])
	{
		flip(posfrom,middle,type,2*i,posfrom,middle);
		flip(middle+1,posto,type,2*i+1,middle+1,posto);
		lazy[i][type] = 0;
	}
	return (from<=middle ? query(from,min(middle,to),type,2*i,posfrom,middle) : 0)
		+  (to>middle ? query(max(middle+1,from),to,type,2*i+1,middle+1,posto) : 0);
}

int main()
{
	freopen("starwars.in","r",stdin);
	freopen("starwars.out","w",stdout);
	scanf("%d",&n);
	for (int test=0; test<n; test++)
	{
		scanf("%d%d%d%d",&x,&y,&z,&q);
		dim[0] = x-1;
		dim[1] = y-1;
		dim[2] = z-1;
		for (int i=0; i<400005; i++)
			for (int j=0; j<3; j++)
				tree[i][j] = lazy[i][j] = 0;
				
		for (int type,from,to,x1,y1,z1,x2,y2,z2, i=0; i<q; i++)
		{
			scanf("%d",&type);
			if (type<3)
			{
				scanf("%d%d",&from,&to);
				flip(from,to,type,1,0,dim[type]);
			}
			else
			{
				scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
				long long xs=query(x1,x2,0,1,0,dim[0]), ys=query(y1,y2,1,1,0,dim[1]), zs=query(z1,z2,2,1,0,dim[2]);
				long long x=x2-x1+1, y=y2-y1+1, z=z2-z1+1;
				printf("%lld\n",xs*y*z + ys*x*z + zs*x*y - 2*xs*ys*z - 2*xs*zs*y - 2*ys*zs*x + 4*xs*ys*zs);
			}
		}
	}
}
