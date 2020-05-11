#include <cstdio>
#include <vector>

int N, data[101][101];

//dfs
std::vector<int> child[101];
int visit[101]; // 0 = no visit, 1 = visit, 2 = added stocks

void sum(int owner, int company)
{
	visit[company] = 2;
	for (int i=1; i<=100; i++)
	{
		if (data[owner][i]<=50 && data[owner][i]+data[company][i]>50)
			child[owner].push_back(i);
		data[owner][i] += data[company][i];
	}
}

int dfs(int owner)
{
	if (visit[owner]) return visit[owner];
	visit[owner] = 1;
	for (int i=0; i<child[owner].size(); i++)
	{
		int company = child[owner][i];
		if (dfs(company) != 2) sum(owner,company);
	}
	return 1;
}

int main()
{
	freopen("companies.in","r",stdin);
	freopen("companies.out","w",stdout);
	scanf("%d",&N);
	for (int owner,company,percent, i=0; i<N; i++)
	{
		scanf("%d%d%d",&owner,&company,&percent);
		if (data[owner][company]<=50 && data[owner][company]+percent>50)
			child[owner].push_back(company);
		data[owner][company] += percent;
	}
	for (int i=1; i<=100; i++) dfs(i);
	
	for (int owner=1; owner<=100; owner++)
		for (int company=1; company<=100; company++)
			if (owner!=company && data[owner][company]>50) 
				printf("%d %d\n",owner,company);
}
