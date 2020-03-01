/*
ID:manolis2
PROG:sprime
LANG:C++
*/

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

FILE *input = fopen("sprime.in","r");
FILE *output = fopen("sprime.out","w");
int n;

bool check(int number)
{
	if ((number%2 == 0) || (number<2)) return false;
	int max = static_cast<int>(sqrt(number));
	for (int i=3; i<=max; i+=2)
		if (number%i == 0) return false;
	return true;
}

void findsprime(int digit, int number)
{
	if (digit==n)
	{
		fprintf(output,"%i\n",number);
		return;
	}
	for (int i=1; i<10; i+=2)
		if (check(number*10+i))
			findsprime(digit+1,number*10+i);
	return;
}

int main()
{
	fscanf(input,"%i",&n);
	findsprime(1,2);
	findsprime(1,3);
	findsprime(1,5);
	findsprime(1,7);
	return 0;
}

