#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
#define size 30000000

//2d segment tree
int l[size], r[size], tree[size], num[size], cnt=1;

int safe(int &x)
{
	if (x) return x;
	return x=++cnt;
}

void add(int x, int y, bool d=0, int i=1, int beg=0, int end=1e9)
{
	if (d) num[i]++;
	else add(y,-1,1,safe(tree[i]));
	if (beg==end) return;
	int mid=(beg+end)/2;
	if (x <= mid) add(x,y,d,safe(l[i]),beg,mid);
	else add(x,y,d,safe(r[i]),mid+1,end);
}

int sum(int left, int right, int down, int up, bool d=0, int i=1, int beg=0, int end=1e9)
{
	if (left>right || !i) return 0;
	if (left==beg && right==end)
		return d ? num[i] : sum(down,up,-1,-1,1,tree[i]);
	int mid = (beg+end)/2;
	return  sum(left,min(mid,right),down,up,d,l[i],beg,mid)
		+	sum(max(mid+1,left),right,down,up,d,r[i],mid+1,end);
}

int kthx(int down, int up, int k)
{
	int i=1, left=0, right=1e9, mid, s;
	while (left<right)
	{
		mid = (left+right)/2;
		s = sum(left,mid,down,up,0,l[i],left,mid);
		if (s<k)
		{
			k -= s;
			left = mid+1;
			i = r[i];
		}
		else
		{
			right=mid;
			i = l[i];
		}
	}
	return left;
}

int trees[20];
void findsegs(int left, int right, int i=1, int beg=0, int end=1e9)
{
	if (left>right || !i) return;
	if (left==beg && right==end) trees[cnt++]=tree[i];
	else
	{
		int mid=(beg+end)/2;
		findsegs(left,min(mid,right),l[i],beg,mid);
		findsegs(max(mid+1,left),right,r[i],mid+1,end);
	}
}

int kthy(int left, int right, int k)
{
	cnt=0;
	findsegs(left,right);
	int down=0, up=1e9, mid, s;
	while (down<up)
	{
		mid = (down+up)/2, s=0;
		for (int i=0; i<cnt; i++) s += num[l[trees[i]]];
		if (s<k)
		{
			k -= s;
			down = mid+1;
			for (int i=0; i<cnt; i++) trees[i] = r[trees[i]];
		}
		else
		{
			up = mid;
			for (int i=0; i<cnt; i++) trees[i] = l[trees[i]];
		}
	}
	return down;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,q;
	scanf("%d%d",&n,&q);
	for (int y,x,i=0; i<n; i++)
	{
		scanf("%d%d",&y,&x);
		add(x,y);
	}
	
	for (int down,left,up,right,i=0; i<q; i++)
	{
		scanf("%d%d%d%d",&down,&left,&up,&right);
		int s1=sum(left,right,0,down-1), s2=sum(left,right,0,up), s3=s2-s1;
		printf("%d ",kthy(left,right,s1+(s3+1)/2));
		s1=sum(0,left-1,down,up);
		printf("%d\n",kthx(down,up,s1+(s3+1)/2));
	}
}
