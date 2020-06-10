#include <cstdio>
#include <deque>
#include <cstring>

int N, vis[50], order[50];
std::deque<int> alist[50], path, unavoidable, seperation;

bool addToPath(int v, int count)
{
	path.push_front(v);
	order[v]=count;
	return true;
}

void clearSeperation(int stop)
{
	while (!seperation.empty() && order[seperation.back()]>stop )
		seperation.pop_back();
}

bool findPath(int v, int count)
{
	if (v==N) return addToPath(v,count);
	vis[v]=1;
	for (unsigned int i=0; i<alist[v].size(); i++)
		if (!vis[alist[v][i]] && findPath(alist[v][i],count+1) ) 
			return addToPath(v,count);
	return false;
}

void dfs(int v, int& furthest, int area)
{
	vis[v] = area;
	for (int unsigned i=0; i<alist[v].size(); i++)
	{
		int next = alist[v][i];
		if (vis[next]) 		  clearSeperation(vis[next]);
		else if (order[next]) furthest = std::max(furthest,order[next]);
		else 				  dfs(next,furthest,area);
	}	
}

int main()
{
	//reading
	freopen("race.in","r",stdin);
	freopen("race.out","w",stdout);
	int v;
	for (N=0; scanf("%d",&v) && v!=-1; N++)
		for (; v!=-2; scanf("%d",&v)) alist[N].push_back(v);
	N--;
	
	findPath(0,1);
	
	/* Furthest point in main path reachable from a deviation.
	 * Numbering follows the order in main path ie 1,2,...,path.size() */
	int furthest=1;
	memset(vis,0,sizeof(vis));
	for (unsigned int i=0; i<path.size()-1; i++)
	{
		int v = path[i];
		if (furthest <= order[v])
		{
			unavoidable.push_back(v);
			seperation.push_back(v);
		}
		dfs(v,furthest,order[unavoidable.back()]);
	}
	
	printf("%lu ",unavoidable.size()-1);
	for (unsigned int i=1; i<unavoidable.size(); i++) printf("%d ",unavoidable[i]);
	printf("\n%lu ",seperation.size()-1);
	for (unsigned int i=1; i<seperation.size(); i++) printf("%d ",seperation[i]);
}
