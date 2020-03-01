/*
ID:manolis2
PROG:lgame
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

ifstream fin("lgame.in"), dict("lgame.dict");
ofstream fout("lgame.out");
string init, curr;
int lettonum[200], nletters[8], letterpoints[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7}, bestscore=0;
list<string> bestwords, words3, words4;

int findscore(string word)
{
	int ret=0, letcount[8]={0};
	bool ok=true;
	for (int i=0; i<word.length(); i++)
	{
		if (!lettonum[word[i]] || ++letcount[lettonum[word[i]]] > nletters[lettonum[word[i]]])
		{
			ok = false;
			break;
		}
		ret += letterpoints[word[i]-97];
	}
	return ok ? ret : 0;
}

int main()
{
	fin >> init;
	sort(init.begin(),init.end());
	lettonum[init[0]] = 1;
	nletters[1]++;
	for (int i=1,j=2; i<init.length(); i++)
	{
		if (init[i] != init[i-1])
			lettonum[init[i]] = j++;
		nletters[j-1]++;	
	}
		
	while (dict >> curr && curr != ".")
	{
		int score = findscore(curr);
		if (!score) continue;
		if (curr.length() == 3)
		{
			words3.push_back(curr);
			words4.push_back(curr);
		}
		if (curr.length() == 4)
			words4.push_back(curr);
		if (score >= bestscore)
		{
			if (score > bestscore)
			{
				bestscore = score;
				bestwords.clear();
			}
			bestwords.push_back(curr);
		}
	}
	
	for (auto it3 = words3.begin(); it3 != words3.end(); it3++)
		for (auto it4 = words4.begin(); it4 != words4.end(); it4++)
		{
			int score = findscore(*it3 + *it4);
			if (score > bestscore) 
			{
				bestwords.clear();
				bestscore = score;
			}
			if (score == bestscore)
				bestwords.push_back(min(*it3,*it4) + ' ' + max(*it3,*it4));
		}
	bestwords.sort();
	fout << bestscore << endl;
	if (bestscore == 0) return 0;
	auto it=bestwords.begin();
	fout << *it << endl;
	it++;
	for (; it !=bestwords.end(); it++)
		if (*it != *(prev(it)))
			fout << *it << endl;
	return 0;
}

