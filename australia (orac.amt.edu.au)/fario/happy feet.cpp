#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
	int v[2], n, pos[2];
	long long dp[2];
};

int n,m;
vector<pair<int,int>> helpar[1000001];
vector<int> alist[1005];
Edge e[1001005];

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	pair<int,int> temp;
	for (int peng, i=0; i<m; i++)
	{
		scanf("%d%d%d",&temp.first,&temp.second,&peng);
		helpar[peng].push_back(temp);
	}
	int i=0;
	for (; i<n; i++)
	{
		e[i].v[1] = i+1;
		e[i].pos[0] = -1;
		alist[i+1].push_back(i);
	}
	for (int j=1; j<=1000000; j++)
		for (auto it:helpar[j])
		{
			e[i].v[0] = it.first;
			e[i].v[1]= it.second;
			e[i].n = j;
			e[i].pos[0] = alist[it.first].size();
			e[i].pos[1] = alist[it.second].size();
			alist[it.first].push_back(i);
			if (it.first != it.second) alist[it.second].push_back(i);
			i++;
		}
	m=i;
	
	for (i=m-1; i>=0; i--)
	{
		for (int j=0; j<2; j++)
			if (e[i].pos[j] == alist[e[i].v[j]].size()-1) e[i].dp[j]=0;
			else
			{
				int next = alist[e[i].v[j]][e[i].pos[j]+1], x = !(e[next].v[0] == e[i].v[j]);
				// το x είναι η άκρη της ακμής next που καταλήγει στον κόμβο που εξετάζουμε
				e[i].dp[j] = e[next].dp[x];
				if (e[i].n != e[next].n && e[next].n + e[next].dp[!x] > e[i].dp[j])
					e[i].dp[j] = e[next].n + e[next].dp[!x];	
			}
		//printf("%d %d %d : %lld %lld\n",e[i].v[0],e[i].v[1],e[i].n,e[i].dp[0],e[i].dp[1]);
	}
		
	
	long long ans=0;
	for (int i=0; i<n; i++)
		ans = max(ans,e[i].dp[1]);
	printf("%lld\n",ans);
	return 0;
}

