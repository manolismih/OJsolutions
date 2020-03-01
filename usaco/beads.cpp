/*
ID: manolis2
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

char kolie[351];
int maximum=0, i, n;

void best()
{
    int taken=0, first, last;
    char color1, color2;

    color1 = kolie[i];
    color2 = kolie[i+1];
    first = i+n;
    last = i+1+n;
findprev:
    while (((kolie[first%n] == color1) || (kolie[first%n] == 'w')) && (first%n != last%n))
    {
        taken++;
        first--;
    }
    if (first%n == last%n)
    {
        maximum = n;
        return;
    }
    if (color1 == 'w')
    {
        color1 = kolie[first%n];
        goto findprev;
    }


findnext:
    while (((kolie[last%n] == color2) || (kolie[last%n] == 'w')) && (first%n != last%n))
    {
        taken++;
        last++;
    }
    if (first%n == last%n)
    {
        maximum = n;
        return;
    }
    if (color2 == 'w')
    {
        color2 = kolie[last%n];
        goto findnext;
    }
    if (taken > maximum)
        maximum = taken;
}

int main()
{

    ifstream input("beads.in");
    ofstream output("beads.out");
    input >> n;
    input >> kolie;

    for (i=0; i<n; i++)
        best();

    output << maximum << endl;

    return 0;
}
