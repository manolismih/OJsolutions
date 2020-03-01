#include <string>
#include <iostream>
#define mod 1800119903481583ll

int n;
std::string s;
long long s1, s2[100005], power[50005]={1};
bool plus;

int main()
{
	std::cin >> n >> s;
	int from = 0, to = n/2, curr, i;
	for (int i=1; i<=to; i++)
		power[i] = (power[i-1]*125) % mod;
		
	while (from != to)
	{
		bool found = false;
		curr = (from+to)/2 + 1;
		s1 = s2[n-curr] = 0;
		
		for (i=n-1; i>=n-curr; i--)
			s2[n-curr] = (s2[n-curr]*125 + s[i]) % mod;
		for (; i>=curr; i--)
		{
			s2[i] = (s2[i+1] - s[i+curr]*power[curr-1]) % mod;
			if (s2[i] < 0) s2[i] += mod;
			s2[i] = (s2[i]*125 + s[i]) % mod;
		}
		
		for (i=0; i<curr; i++)
			s1 = (s1*125 + s[i]) % mod;
		if (s1 == s2[i+1])
			found = plus = true;
		else if (s1==s2[i])
			found=true, plus=false;
			
		for (; !(plus&&found) && i<n-curr; i++)
		{
			s1 = (s1 - s[i-curr]*power[curr-1]) % mod;
			if (s1<0) s1 += mod;
			s1 = (s1*125 + s[i]) % mod;
			if (s1 == s2[i+2])
				found = plus = true;
			else if (s1==s2[i+1])
				found=true, plus=false;
		}
		
		if (found) from = curr;
		else to = curr-1;
	}
	
	if (from == 0)
	{
		for (int i=0; i<n-1; i++)
			if (s[i] == s[i+1])
			{
				std::cout << 2 << std::endl;
				return 0;
			}
		std::cout << 1 << std::endl;
	}
	else
		std::cout << (plus ? 2*from+1 : 2*from) << std::endl;
	return 0;
}

