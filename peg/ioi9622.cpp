#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m, dp[200005];
string small[205];
string s;

int main()
{
	while (1)
	{
		cin >> small[m];
		if (small[m] == ".") break;
		m++;
	}
	for (string temp; cin >> temp; s += temp);
	n = s.length();
	s+="00000000000000";
	for (int i=n-1; i>=0; i--)
		for (int j=0; j<m; j++)
		{
			int l = small[j].length();
			if (s.compare(i,l,small[j],0,l) == 0) dp[i] = max(dp[i], l + dp[i+l]);
		}
	cout << dp[0] << endl;
}
