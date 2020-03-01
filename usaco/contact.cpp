/*
ID:manolis2
PROG:contact
LANG:C++11
*/
#include <fstream>
#include <string>
#include <bitset>
#include <list>
#include <iostream>

using namespace std;

ifstream fin("contact.in");
ofstream fout("contact.out");

struct motivo{
	int decimal, digits, freq; 
};

inline motivo tomotivo(int decimal, int digits, int freq)
{
	motivo ret={decimal,digits,freq};
	return ret;
}

inline bool mcompare(motivo a, motivo b)
{
	if (a.freq != b.freq) return a.freq > b.freq;
	if (a.digits != b.digits) return a.digits < b.digits;
	return a.decimal < b.decimal;
}
string bits;
int a, b, n, freq[13][4096];
list<motivo> flist;

int main()
{
	fin >> a >> b >> n;
	string s;
	while (fin >> s)
		bits += s;
	int index;
	for (int i=0; i<=bits.length()-a; i++)
	{
		index=0;
		int j;
		for (j=i; j<i+a-1; j++)
			index = index*2 + (bits[j]=='0' ? 0 : 1);
		j--;
		while (j-i+1 < b && j+1<bits.length())
		{
			j++;
			index = index*2 + (bits[j]=='0' ? 0 : 1);
			freq[j-i+1][index]++;
		}
	}
	
	for (int i=a; i<=b; i++)
		for (int j=0; j<4096; j++)
			if (freq[i][j])
				flist.push_back(tomotivo(j,i,freq[i][j]));
	flist.sort(mcompare);
	
	int fprinted, printed=0, lprinted=0;
	for (int i=0; i<n && !flist.empty(); i++)
	{
		string apantisi;
		fprinted = flist.front().freq;
		lprinted=0;
		fout << fprinted << endl;
		while (flist.front().freq == fprinted)
		{
			printed++, lprinted++;
			motivo temp = flist.front();
			bitset<12> tb(flist.front().decimal);
			string ts = tb.to_string();
			apantisi += ts.substr(12-flist.front().digits);
			if (lprinted%6 == 0)
				apantisi += '\n';
			else
				apantisi += ' ';
			flist.pop_front();
		}
		apantisi.pop_back();
		fout << apantisi << endl;
	}
	return 0;
}

