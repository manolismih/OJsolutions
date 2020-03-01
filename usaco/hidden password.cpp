/*
ID:manolis2
PROG:hidden
LANG:C++11
*/
#include <fstream>
#include <string>
using namespace std;
#define ull unsigned long// long
#define p 131

int n, k=-1, pow2[20]={1};
string s;
ull hsh[100005][20];

bool comp(int i, int j) // true an <=
{
	int pow=k, add=0;
	while (pow-->=0)
		if (hsh[i%n][pow]==hsh[j%n][pow]) 
			if (add + pow2[pow] < n) add += pow2[pow], i+=pow2[pow], j+=pow2[pow];
			else return true;
	return s[i%n]<=s[j%n];
}

int main()
{
	ifstream fin("hidden.in");
	ofstream fout("hidden.out");
	fin >> n;
	string temp;
	while (fin >> temp && !temp.empty()) s += temp;
	s += s;
	for (int i=1; i<20; i++) pow2[i] = pow2[i-1]*2;
	
	for (int len=1; len<=n; len*=2)
	{
		k++;
		ull pow=1, curr=0;
		for (int i=1; i<len; i++) pow *= p;
		
		for (int i=0; i<len-1; i++) curr = (curr*p + s[i]);
		for (int i=0; i<n; i++)
		{
			curr = (curr*p) + s[i+len-1];
			hsh[i][k] = curr;
			curr -= s[i]*pow;
		}
	}
	
	int i=0, j=1;
	while (j<n)
		if (comp(i,j)) j++;
		else i=j++;
	fout << i << endl;
	return 0;
}

