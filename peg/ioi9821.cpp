#include <cstdio>
#include <algorithm>
using namespace std;

//sweep line
struct Event{	int x,y1,y2,type;};
Event data[10005];
int n, event[10005];

//segment tree + lazy (without propagation!)
int segs[80000], miden[80000], lazy[80000], left[80000], right[80000];

bool comp(int a, int b)
{
	if (data[a].x != data[b].x) return data[a].x < data[b].x;
	return data[a].type > data[b].type;
}

void init(int i=1, int begin=0, int end=19999)
{
	if (begin==end) miden[i] = 1;
	else
	{
		init(2*i,begin,(begin+end)/2);
		init(2*i+1,(begin+end)/2+1,end);
		miden[i] = end-begin+1;
	}
}

int add(int from, int to, int val, int i=1, int begin=0, int end=19999)
{
	int middle = (begin+end)/2, ret=0;
	if (from==begin && to==end)
	{
		lazy[i] += val;
		if (lazy[i]) 
		{
			ret = (lazy[i]==1 && val==1 ? miden[i] : 0);
			miden[i] = 0;
			segs[i] = left[i] = right[i] = 1;
			return ret;
		}
		else if (from==to)
		{
			segs[i] = left[i] = right[i] = 0;
			return miden[i] = 1;
		}
		else
		{
			ret = miden[2*i] + miden[2*i+1];
			goto calculations;
		}
	}
	if (from <= middle) ret += add(from,min(middle,to),val,2*i,begin,middle);
	if (to > middle) ret += add(max(middle+1,from),to,val,2*i+1,middle+1,end);
	
	calculations:
		left[i] = left[2*i];
		right[i] = right[2*i+1];
		segs[i] = segs[2*i] + segs[2*i+1] - (right[2*i]&&left[2*i+1]);
		miden[i] = miden[2*i] + miden[2*i+1];
		return ret;
}

int main()
{
	init();
	scanf("%d",&n);
	for (int i=0; i<2*n; i++) event[i] = i;
	for (int x1,y1,x2,y2,i=0; i<n; i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		data[2*i]   = {x1+10000,y1+10000,y2+10000,1};
		data[2*i+1] = {x2+10000,y1+10000,y2+10000,-1};
	}
	
	sort(event,event+2*n,comp);
	int prev,ans=0;
	for (int i=0; i<2*n; i++)
	{
		Event &curr=data[event[i]];
		ans += 2*segs[1]*(curr.x-prev);
		printf("%d\n",ans);
		ans += add(curr.y1,curr.y2-1,curr.type);
		printf("%d\n",ans);
		prev = curr.x;
	}
	//printf("%d\n",ans);
}
