#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;
#define size 223

struct query {	int from,to,id;};
bool comp(query a, query b) {return a.to < b.to;}
list<query> bucket[230];
int n,q, sum[50005], ans[50005];

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&sum[i]);
		sum[i] += sum[i-1];
	}
	query temp;
	for (temp.id=1; temp.id<=q; temp.id++)
	{
		scanf("%d%d",&temp.from,&temp.to);
		bucket[(temp.from-1)/size +1].push_back(temp);
	}
	
	int buckets = n/size + 1;
	int *rightf = new int[100005]+50002, *rightl = new int[100005]+50002, *modright = new int[100005]()+50002;
	int *left  = new int[100005]+50002, *modleft  = new int[100005]()+50002;
	for (int b=1; b<=buckets; b++)
	{
		bucket[b].sort(comp);
		int bestr = 0, r = b*size+1; // η αρχή του επόμενου κουβά
		for (auto q:bucket[b])
		{
			for (; r<=q.to; r++)
			{
				if (modright[sum[r]] == b) bestr = max(bestr,r-rightf[sum[r]]);
				else modright[sum[r]] = b, rightf[sum[r]] = r;
				rightl[sum[r]] = r;
			}	
			ans[q.id] = bestr;
			for (int l=q.from-1, stop=min(q.to,b*size); l<=stop; l++)
			{
				if (modright[sum[l]] == b) ans[q.id] = max(ans[q.id],rightl[sum[l]]-l);
				if (modleft[sum[l]] == q.id) ans[q.id] = max(ans[q.id],l-left[sum[l]]);
				else modleft[sum[l]] = q.id, left[sum[l]]=l;
			}
		}
	}
	for (int i=1; i<=q; i++) printf("%d\n",ans[i]);
}
