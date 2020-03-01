#include <iostream>
#include <string>
#define mod 18014398509481981
using namespace std;

int tests, apantisi, i;
long long source, target, power[1000005]={1};
string s, t;

int main()
{
	cin >> tests;
	for (int i=1; i<1000005; i++)
		power[i] = (power[i-1]*125) % mod;
	for (int test=0; test<tests; test++)
	{
		cin >> s >> t;
		if (t.length() > s.length())
		{
			cout << "Case " << test+1 << ": 0" << endl;
			continue;
		}
		i = source = target = apantisi = 0;
		for (; i<t.length(); i++)
		{
			source = (source*125 + s[i]) % mod;
			target = (target*125 + t[i]) % mod;
		}
		if (source == target) apantisi++;
		for (; i<s.length(); i++)
		{
			source = (source - s[i-t.length()]*power[t.length()-1]) % mod;
			if (source<0) source += mod;
			source = (source*125 + s[i]) % mod;
			if (source==target) apantisi++;
		}
		cout << "Case " << test+1 << ": " << apantisi << endl;
	}
	return 0;
}

