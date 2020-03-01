/*
ID:manolis2
PROG:buylow
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
#include <algorithm>
#define base 100000000000000000
using namespace std;

ifstream fin("buylow.in");
ofstream fout("buylow.out");

class bigint
{
	public :
		list<unsigned long long> digits;
		bigint() : digits(1,0)
		{
		}
		void operator+=(bigint plus)
		{
			digits.resize(max(plus.digits.size(),digits.size()) + 1,0);
			auto itp = plus.digits.begin(), itc = digits.begin();
			for (; itp!=plus.digits.end(); itp++, itc++)
			{
				*itc += *itp;
				if (*itc >= base)
				{
					++*next(itc);
					*itc %= base;
				}
			}
			for (; itc!=digits.end() && *itc >= base; itc++)
			{
				++*next(itc);
				*itc %= base;
			}
			if (digits.back() == 0)
				digits.pop_back();
		}
		void operator=(bigint &num)
		{
			digits = num.digits;
		}
		void print()
		{
			fout << digits.back();
			if (digits.size() > 1)
				for (auto it = prev(prev(digits.end())); ; it--)
				{
					for (long long j = base/10; j>1 && *it/j == 0; j/=10)
						fout << 0;
					fout << *it;
					if (it == digits.begin()) return;
				}
		}
};
int n, prices[5005], memo[5005], best=1;
bigint tropoi[5005], totaltropoi;

int main()
{
	fin >> n;
	for (int i=0; i<n; i++)
	{
		fin >> prices[i];
		memo[i] = 1;
		tropoi[i].digits.front() = 1;
		for (int j=0; j<i; j++)
			if (prices[j] == prices[i])
			{
				prices[j] = -1;
				memo[j] = 0;
			}	
			else if (prices[j] > prices[i] && memo[j]+1 > memo[i])
			{
				memo[i] = memo[j]+1;
				tropoi[i] = tropoi[j];
				if (memo[i] > best) best = memo[i];
			}
			else if (prices[j] > prices[i] && memo[j]+1 == memo[i])
				tropoi[i] += tropoi[j];
	}
	for (int i=0; i<n; i++)
		if (memo[i] == best)
			totaltropoi += tropoi[i];
	fout << best << ' ';
	totaltropoi.print();
	fout << endl;
	return 0;
}
