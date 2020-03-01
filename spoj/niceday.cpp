#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int tests, n, ans, c[100005], stand[100005][3];

bool comp(int a, int b) {return stand[a][0] < stand[b][0];}
bool comp2(int a, int b){return stand[a][1] < stand[b][1];}
set<int,bool(*)(int,int)> s(comp2);

int main()
{
	scanf("%d",&tests);
	for (int i=0; i<tests; i++)
	{
		scanf("%d",&n);
		s.clear();
		for (int i=0; i<n; i++)
		{
			scanf("%d%d%d",&stand[i][0],&stand[i][1],&stand[i][2]);
			c[i] = i;
		}
		sort(c,c+n,comp);

		ans = n;
		for (int i=0; i<n; i++)
		{
			auto it = s.insert(c[i]).first;
			if (it != s.begin() && stand[*prev(it)][2]<stand[c[i]][2])
			{
				ans--;
				s.erase(it);
			}
			else for (it=next(it); it!=s.end() && stand[c[i]][2]<stand[*it][2]; )
				it = s.erase(it);
		}
		printf("%d\n",ans);
	}
}
