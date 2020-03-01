/*
ID:manolis2
PROG:spin
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

ifstream fin("spin.in");
ofstream fout("spin.out");
struct wheel{
	int speed;
	list<pair<int,int> > wedges;
};
wheel wheels[5];
list<pair<int,int> > common;

void check(list<pair<int,int> > &x)
{
	auto itc=common.begin(), itx=x.begin();
	while (itc != common.end() && itx != x.end())
	{
		if (itc->first <= itx->first) // to common einai proto
		{
			if (itc->second < itx->first) // to commmon einai olo prin apo to x
			{
				itc = common.erase(itc);
				break;
			}
			else // to common einai proto kai exei koina me to x
			{
				if (itc->second <= itx -> second)
				{
					itc = common.insert(itc,make_pair(itx->first,itc->second));
					itc++;
					break;
				}	
				else // to x einai olo mesa sto common
				{
					common.insert(itc,make_pair(itx->first,itx->second));
					itc->first = itx->second+1;
					itx++;
					break;
				}
			}
		}
		else // to x einai proto
		{
			if (itx->second < itc->first) // to x einai olo prin apo to common
			{
				itx++;
				break;
			}
			else // to x einai proto kai exei koina me to common
			{
				if (itx->second <= itc->second)
				{
					common.insert(itc,make_pair(itc->first,itx->second));
					itc->first = itx->second+1;
					itx++;
				}
				else // to common einai olo mesa sto x
					itc++;
			}
		}
	}
	return ;
}

int main()
{
	for (int i=0, nwedges; i<5; i++)
	{
		fin >> wheels[i].speed >> nwedges;
		for (int j=0, start, end; j<nwedges; j++)
		{
			fin >> start >> end;
			end += start;
			if (end > 359)
			{
				wheels[i].wedges.push_back(make_pair(start,359));
				wheels[i].wedges.push_back(make_pair(0,end-360));
			}
			else
				wheels[i].wedges.push_back(make_pair(start,end));
		}
		wheels[i].wedges.sort();
	}
	
	for (int i=0; i<360; i++)
	{
		common = wheels[0].wedges;
		for (int j=1; j<5 && !common.empty(); j++)
			check(wheels[j].wedges);
		if (!common.empty())
		{
			fout << i << endl;
			return 0;
		}
	}
	fout << "none" << endl;
	return 0;
}

