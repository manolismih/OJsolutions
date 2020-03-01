#include <iostream>
#include <string>
#define mod 18014398509481981
using namespace std;

int t, apantisi;
long long prints[1000005], power[500005]={1};
string s;

int main()
{
	for (int i=1; i<500005; i++)
		power[i] = (power[i-1]*125) % mod;
	cin >> t;
	for (int test=1; test<=t; test++)
	{
		cin >> s;
		int n=s.length(),i;
		prints[n] = 0;
		for (i=0; i<n/2; i++)
			prints[n] = (prints[n]*125 + s[i]) % mod;
		if (n%2)
		{
			n--;
			prints[n] = (prints[n+1] - s[0]*power[n/2 - 1]) % mod;
			if (prints[n]<0) prints[n] += mod;
			prints[n] = (prints[n]*125 + s[i]) % mod;
			i++;
		}
		
		for (n--; n>1; i++,n--)
		{
			prints[n] = (prints[n+1] - s[i - (n+1)/2]*power[n/2]) % mod;
			if (prints[n] < 0) prints[n] += mod;
			n--;
			prints[n] = (prints[n+1] - s[i -n/2]*power[n/2 -1]) % mod;
			if (prints[n] < 0) prints[n] += mod;
			prints[n] = (prints[n]*125 + s[i]) % mod;
		}
		
		int best=1;
		long long target=0;
		n = s.length();
		for (i=1; i<n/2; i++)
		{
			target = (target*125 +s[n-i]) % mod;
			if (target==prints[2*i +1]) best = 2*i +1;
			else if (target==prints[2*i]) best = 2*i;
		}
		target = (target*125 +s[n-i]) % mod;
		if (n%2 && target==prints[2*i +1]) best = 2*i +1;
		else if (target==prints[2*i]) best = 2*i;
		
		cout << "Case " << test << ": " << 2*n - best << endl;	
	}
	return 0;
}

