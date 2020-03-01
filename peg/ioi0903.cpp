#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;

int n;
string s[2005];

int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		bitset<12> temp(i);
		s[i] = temp.to_string();
		reverse(s[i].begin(),s[i].end());
	}
	sort(s+1,s+n+1);
	for (int i=1; i<=n; i++)
	{
		reverse(s[i].begin(),s[i].end());
		bitset<12> temp(s[i]);
		cout << temp.to_ulong() << endl;
	}
}
