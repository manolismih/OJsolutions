#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define inf 2e9
#define pb push_back

//general
int r,c,k;
vector<vector<int>> pista, dp;

//sparse segment tree
vector<int> left,right,val;

int safenode (int &i)
{
	if (i) return i;
	i = left.size();
	left.pb(0);
	right.pb(0);
	val.pb(inf);
	return left.size()-1;
}

void set(int pos, int x, int i, int beg=0, int end=c-1)
{
	if (beg==end) val[i] = x;
	else
	{
		int middle = (beg+end)/2;
		if (pos <= middle) set(pos,x,safenode(left[i]),beg,middle);
		if (pos > middle)  set(pos,x,safenode(right[i]),middle+1,end);
		val[i] = min(val[left[i]],val[right[i]]);
	}
}

int query(int from, int to, int i, int beg=0, int end=c-1)
{
	if (!i) return inf;
	if (from==beg && to==end) return val[i];
	int middle = (beg+end)/2;
	return min(from<=middle ? query(from,min(middle,to),left[i],beg,middle) : inf,
				to > middle ? query(max(middle+1,from),to,right[i],middle+1,end) : inf);
}

int main()
{
	scanf("%d%d%d",&r,&c,&k);
	vector<int> tmp(c+5,0);
	pista.insert(pista.begin(),r+5,tmp);
	dp.insert(dp.begin(),r+5,tmp);
	left.insert(left.begin(),k+1,0);
	right.insert(right.begin(),k+1,0);
	val.insert(val.begin(),k+1,inf);
	for (int y=0; y<r; y++)
		for (int x=0; x<c; x++)
			scanf("%d",&pista[y][x]);
	
	for (int y=0; y<r; y++) dp[y][c] = inf;
	for (int x=0; x<c; x++) dp[r][x] = inf;
	pista[r][c-1] = pista[r-1][c-1];
	dp[r][c-1] = 0;
	
	for (int y=r-1; y>=0; y--)
		for (int x=c-1; x>=0; x--)
		{
			dp[y][x] = min({dp[y+1][x] + (pista[y][x] != pista[y+1][x]),
							dp[y][x+1] + (pista[y][x] != pista[y][x+1]),
							query(x,c-1,pista[y][x]) -x-y-1});
			set(x,dp[y][x]+y+x,pista[y][x]);
		}
	printf("%d\n",dp[0][0]);
}
