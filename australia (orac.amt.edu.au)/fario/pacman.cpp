#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back

//general (info: num of fruits till next mountain or -1 for fruit cell)
int r,c,b,f, posy[500005], posx[500005], inforow[500005], infocol[500005], cnt;
vector<int> grami[100005], stili[100005];

//segment tree
int val[400000];

class comp
{
	const int *pos;
	public:
		comp(int *x) : pos(x){}
		bool operator()(int a, int b){	return pos[a]<pos[b];}
};

void put(int y, int x, bool fruit)
{
	grami[y].pb(cnt);
	stili[x].pb(cnt);
	posy[cnt] = y;
	posx[cnt] = x;
	if (fruit) infocol[cnt] = inforow[cnt] = -1;
	cnt++;
}

void preprocess(vector<int> &line, int *info)
{
	int sum=0, prv=line[0];
	for (int i=1; i<line.size(); i++)
		if (info[line[i]] == -1) sum++;
		else
		{
			info[prv] = sum;
			sum = 0;
			prv = line[i];
		}		
}

void add(int pos, int x, int i=1, int beg=1, int end=r)
{
	if (beg==end) val[i] += x;
	else
	{
		int middle = (beg+end)/2;
		if (pos<=middle) add(pos,x,2*i,beg,middle);
		else add(pos,x,2*i+1,middle+1,end);
		val[i] = max(val[2*i],val[2*i+1]);
	}
}

void set(int pos, int x, int i=1, int beg=1, int end=r)
{
	if (beg==end) val[i] = x;
	else
	{
		int middle = (beg+end)/2;
		if (pos<=middle) set(pos,x,2*i,beg,middle);
		else set(pos,x,2*i+1,middle+1,end);
		val[i] = max(val[2*i],val[2*i+1]);
	}
}

int query(int from, int to, int i=1, int beg=1, int end=r)
{
	if (from > to) return 0;
	if (from==beg && to==end) return val[i];
	int middle = (beg+end)/2;
	return max(from<=middle ? query(from,min(middle,to),2*i,beg,middle) : 0,
				to>middle ? query(max(middle+1,from),to,2*i+1,middle+1,end) : 0);
}

int main()
{
	scanf("%d%d%d%d",&r,&c,&b,&f);
	for (int y,x,i=0; i<b+f; i++)
	{
		scanf("%d%d",&y,&x);
		put(y,x,i>=b);
	}
	put(0,0,0);
	for (int y=1; y<=r; y++)
	{
		put(y,0,0);
		put(y,c+1,0);
	}
	for (int x=1; x<=c; x++)
	{
		put(0,x,0);
		put(r+1,x,0);
	}
	put(r+1,0,0);
	for (int y=1; y<=r; y++)
	{
		sort(grami[y].begin(),grami[y].end(),comp(posx));
		preprocess(grami[y],inforow);
	}
	for (int x=1; x<=c; x++)
	{
		sort(stili[x].begin(),stili[x].end(),comp(posy));
		preprocess(stili[x],infocol);
	}
	
	int ans=0;
	for (int x=0; x<=c; x++)
	{
		if (stili[x].size()==2) continue;
		for (auto i:stili[x])
			if (infocol[i] == -1) add(posy[i],-1);
		int prv=stili[x][0];
		for (auto it=next(stili[x].begin()); it!=stili[x].end(); it++)
			if (infocol[*it] >= 0) //mountain
			{
				ans = max(ans,infocol[prv]+query(posy[prv]+1,posy[*it]-1));
				prv = *it;
			}
		for (auto it=next(stili[x].begin()); it!=prev(stili[x].end()); it++)
			if (infocol[*it] == -1) add(posy[*it],1);
			else set(posy[*it],inforow[*it]);
	}
	printf("%d\n",ans);
}
