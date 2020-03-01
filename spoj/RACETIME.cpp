#include <cstdio>
#include <algorithm>
using namespace std;
#define size 316

int n,q,buckets,last, proig[100005], sorted[101000];

void change(int pos, int val)
{
	int old = proig[pos], left = (pos/size)*size, right = left+size;
	proig[pos] = val;
	pos = lower_bound(sorted+left,sorted+right,old) - sorted;
	sorted[pos] = val;
	while (pos+1 < right && sorted[pos] > sorted[pos+1]) swap(sorted[pos],sorted[pos+1]), pos++;
	while (pos-1 >= left && sorted[pos] < sorted[pos-1]) swap(sorted[pos],sorted[pos-1]), pos--;
}

int query(int from, int to, int x)
{
	int ans=0, mid = min(to+1,(from/size+1)*size);
	for ( ; from<mid; from++) 
		if (proig[from]<=x) ans++;
	for ( ; from+size <= to+1; from+=size, mid+=size) 
		ans += upper_bound(sorted+mid,sorted+mid+size,x) - (sorted+mid);
	for ( ; from<=to; from++)
		if (proig[from]<=x) ans++;
	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);
	for (int i=0; i<n; i++) // ta kano apo 0 os n-1
	{
		scanf("%d",&proig[i]);
		sorted[i] = proig[i];
	}
	for (int i=n; i<101000; i++) sorted[i] = 2000000000;
	buckets = n/size + 1;
	for (int i=0; i<buckets; i++) sort(sorted+i*size,sorted+(i+1)*size);
	
	int n1,n2,n3;
	char c;
	for (int i=0; i<q; i++)
	{
		scanf(" %c",&c);
		if (c=='M')
		{
			scanf("%d%d",&n1,&n2);
			change(n1-1,n2);
		}
		else
		{
			scanf("%d%d%d",&n1,&n2,&n3);
			printf("%d\n",query(n1-1,n2-1,n3));
		}
	}
	return 0;
}
