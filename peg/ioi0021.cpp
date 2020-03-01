#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//general
int n,m,l, pos[35], dist[205][205];
vector<int> area[255];

//create dist
set<pair<int,int>> akmes[205];

int check(int a, int b)
{
	auto i=akmes[a].begin(), j=akmes[b].begin();
	while (i!=akmes[a].end() && j!=akmes[b].end())
		if (*i == *j) return 1;
		else if (*i < *j) i++;
		else if (*j < *i) j++;
	return 2000000;
}

int main()
{
	//freopen("in","r",stdin);
	scanf("%d%d%d",&m,&n,&l);
	for (int i=0; i<l; i++) scanf("%d",&pos[i]);
	
	for (int num,first,prev,curr, i=1; i<=m; i++)
	{
		scanf("%d%d",&num,&first);
		area[first].push_back(i);
		prev = first;
		for (int j=1; j<num; j++)
		{
			scanf("%d",&curr);
			area[curr].push_back(i);
			akmes[i].insert({min(prev,curr),max(prev,curr)});
			prev = curr;
		}
		akmes[i].insert({min(first,curr),max(first,curr)});
	}

	for (int i=1; i<=m; i++)
		for (int j=i+1; j<=m; j++)
			dist[i][j] = dist[j][i] = check(i,j);
			
	for (int k=1; k<=m; k++)
		for (int i=1; i<=m; i++)
			for (int j=1; j<=m; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				
	int ans=2000000, bestarea;
	for (int i=1; i<=m; i++)
	{
		int curr=0;
		for (int j=0; j<l; j++)
		{
			int mindist=2000000;
			for (auto k:area[pos[j]])
				mindist = min(mindist,dist[k][i]);
			curr += mindist;
		}
		ans = min(ans,curr);
		if (ans==curr) bestarea=i;
	}
	printf("%d\n%d\n",ans,bestarea);
}
