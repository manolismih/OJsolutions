/*
ID:manolis2
PROG:picture
LANG:C++11
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int lazy[80000], assoi[80000], tmimata[80000];
bool arxi[80000], telos[80000];

int add(int from, int to, int i=1, int posfrom=0, int posto=20000)
{
	int ret=0;
	if (from==posfrom && to==posto)
	{
		lazy[i]++;
		if (lazy[i]==1)
		{
			ret = posto-posfrom+1-assoi[i];
			assoi[i] = posto-posfrom+1;
			tmimata[i] = arxi[i] = telos[i] = 1;
		} 
		return ret;
	}
	int middle = (posfrom+posto)/2;
	if (from<=middle) ret += add(from,min(to,middle),2*i,posfrom,middle);
	if (to>middle) ret += add(max(middle+1,from),to,2*i+1,middle+1,posto);
	if (lazy[i]) return 0;
	assoi[i] = assoi[2*i]+assoi[2*i+1];
	tmimata[i] = tmimata[2*i]+tmimata[2*i+1] - (telos[2*i]&&arxi[2*i+1]);
	arxi[i] = arxi[2*i];
	telos[i] = telos[2*i+1];
	return ret;
}

int remove(int from, int to, int i=1, int posfrom=0, int posto=20000)
{
	int ret=0;
	if (from==posfrom && to==posto) lazy[i]--;
	else
	{
		int middle = (posfrom+posto)/2;
		if (from<=middle) ret += remove(from,min(to,middle),2*i,posfrom,middle);
		if (to>middle) ret += remove(max(middle+1,from),to,2*i+1,middle+1,posto);
	}
	if (lazy[i]) return 0;
	assoi[i] = assoi[2*i]+assoi[2*i+1];
	tmimata[i] = tmimata[2*i]+tmimata[2*i+1] - (telos[2*i]&&arxi[2*i+1]);
	arxi[i] = arxi[2*i];
	telos[i] = telos[2*i+1];
	if (from==posfrom && to==posto) return posto-posfrom+1-assoi[i];
	else return ret;
}

struct tmima{	int x,y1,y2; bool add;};
int n, nevents, ans;
tmima event[20005];
bool comp(tmima a, tmima b)
{
	if (a.x != b.x) return a.x<b.x;
	else return a.add>b.add;
}

int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d",&n);
	for (int x1,x2,y1,y2, i=0; i<n; i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		event[nevents++] = {x1,y1+10000,y2+10000,1};
		event[nevents++] = {x2,y1+10000,y2+10000,0};
	}
	
	sort(event,event+nevents,comp);
	ans += add(event[0].y1,event[0].y2-1,1);
	for (int i=1; i<nevents; i++)
	{
		ans += 2*(event[i].x-event[i-1].x)*tmimata[1];
		if (event[i].add) ans += add(event[i].y1,event[i].y2-1);
		else ans += remove(event[i].y1,event[i].y2-1);
	}
	printf("%d\n",ans);
	return 0;
}

