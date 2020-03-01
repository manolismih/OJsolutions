#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <cstdio>
using namespace std;

int n, ora=0, memo[160][160][160][2], vis[160][160][160][2];
string s,abbr, words[160];
unordered_set<string> mapa;
int nwords;

int dp(int i, int word, int j, bool took)
{
	if (vis[i][word][j][took]==ora) return memo[i][word][j][took];
	if (j==words[word].length()) return took ? dp(i,word+1,0,0) : 0;
	if (i==abbr.length()) return (word==nwords) || (word==nwords-1 && took);
	if (word==nwords) return 0;
	
	vis[i][word][j][took] = ora;
	return memo[i][word][j][took] = dp(i,word,j+1,took) + (abbr[i]+32==words[word][j] ? dp(i+1,word,j+1,1) : 0);
}

bool scanline()
{
	nwords=0;
	while (cin >> words[nwords] && words[nwords][0] > 'Z')
		if (mapa.count(words[nwords])==0) nwords++;
		
	if (!nwords) return 0;
	ora++;
	int ans = dp(0,0,0,0);
	if (ans) cout << abbr << " can be formed in " << ans << " ways" << endl;
	else cout << abbr << " is not a valid abbreviation" << endl;
	abbr = words[nwords];
	return 1;
}

int main()
{
	//freopen("in","r",stdin);
	while (cin >> n && n)
	{
		mapa.clear();
		for (int i=0; i<n; i++)
		{
			cin >> s;
			mapa.insert(s);
		}
		cin >> abbr;
		while (scanline()) ;
	}
}
