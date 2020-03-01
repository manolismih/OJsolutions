#include <cstdio>
#include <algorithm>
using namespace std;

int p1[400005], p2[400005], all[400005];
int n,a,b,puta,putb,ans;

bool comp(int a, int b){	return p1[a]-p2[a] < p1[b]-p2[b];}

int main()
{
	freopen("restin.txt","r",stdin);
	freopen("restout.txt","w",stdout);
	scanf("%d%d%d",&n,&a,&b);
	for (int i=0; i<n; i++)
	{
		all[i]=i;
		scanf("%d%d",&p1[i],&p2[i]);
		if (p1[i]<=0 && p2[i]<=0) n--,i--;
		else if (p1[i]<=0) p1[i]=0;
		else
		{
			if (p2[i]<=0) p2[i]=0;
			puta++;
			ans += p1[i];
		}
	}
	sort(all,all+n,comp);
	
	for (int i=0; i<n; i++)
		if (puta>a || (p2[all[i]]>p1[all[i]] && putb<b) )
		{
			ans = ans - p1[all[i]] + p2[all[i]];
			if (p1[all[i]]) puta--;
			if (p2[all[i]]) putb++;
		}
	printf("%d\n",ans);
}
