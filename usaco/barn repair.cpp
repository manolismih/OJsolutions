/*
ID: manolis2
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

struct compare1 {
    bool operator() (const pair<int,int> &g1, const pair<int,int> &g2) const{
         return (g1.second-g1.first+1 > g2.second-g2.first+1);
    }
};

bool compare(int x, int y)
{
    return (x < y);
}

int main()
{
    ifstream input("barn1.in");
    ofstream output("barn1.out");
    int maxboards, stalls, noccupied;
    input >> maxboards >> stalls >> noccupied;
    if (maxboards >= noccupied)
    {
        output << noccupied << endl;
        return 0;
    }
    int stallminus;
    multiset <pair<int,int>,compare1> gaps;
    pair <int,int> gap;

    int occupied[200];
    for (int i=0; i<noccupied; i++)
        input >> occupied[i];
    sort(occupied,occupied+noccupied,compare);

    stallminus = occupied[0]-1+stalls-occupied[noccupied-1];
    for (int i=1; i<noccupied; i++)
        if (occupied[i] != occupied[i-1]+1)
        {
            gap = make_pair(occupied[i-1]+1,occupied[i]-1);
            gaps.insert(gap);
           // cout << gaps.size() << endl;
        }

    multiset<pair<int,int> >::iterator pos = gaps.begin();
 /*   while (pos != gaps.end())
    {
        cout << (*pos).first << " " << (*pos).second << endl;
        pos++;
    }
    cout << (*pos).first << " " << (*pos).second << endl;
*/
    for (int i=1; i<maxboards; i++)
    {
        stalls -= (*pos).second - (*pos).first + 1;
        pos++;
    }
    output << stalls-stallminus << endl;
    return 0;
}
