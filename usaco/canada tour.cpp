/*
ID:manolis2
PROG:tour
LANG:C++11
*/
#include <fstream>
#include <map>
#include <list>
#include <string>
using namespace std;
#define inf 200

int n,m, dp[105][105];
map<string,int> id;
list<int> alist[105];

int main()
{
	ifstream in("tour.in");
	ofstream out("tour.out");
	in >> n >> m;
	string s1, s2;
	int v1, v2;
	for (int i=0; i<n; i++)
	{
		in >> s1;
		id[s1] = i;
	}
	for (int i=0; i<m; i++)
	{
		in >> s1 >> s2;
		v1 = id[s1], v2 = id[s2];
		if (v1 < v2) alist[v1].push_back(v2);
		else alist[v2].push_back(v1);
	}
	
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			dp[i][j] = -inf;
	dp[n-1][n-1] = 0;
	
	for (int i=n-1; i>=0; i--)
		for (int j=n-1; j>=0; j--)
		{
			if (i==n-1 && j==n-1) continue;
			if (i<j)
				for (auto next:alist[i])
					if ((next==n-1 || next != j) && 1+dp[next][j] > dp[i][j]) dp[i][j] = 1+dp[next][j];
					else;
			else for (auto next:alist[j])
				if ((next==n-1 || 
				next != i) && 1+dp[i][next] > dp[i][j]) dp[i][j] = 1+dp[i][next];
		}
		
	out << (dp[0][0] > 0 ? dp[0][0] : 1) << endl;
	return 0;
}

