/*
ID: manolis2
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

bool examined[21][21] = {0}, possible[21] = {0};
int A,B,C;

void examine(int a, int b, int c)
{
    if (examined[a][b])
        return;
    examined[a][b] = true;
    if (a==0)
        possible[c] = true;

    if (B-b < a) examine(a-B+b,B,c);
    else examine (0,b+a,c);

    if (C-c < a) examine(a-C+c,b,C);
    else examine(0,b,c+a);

    if (A-a < b) examine(A,b-A+a,c);
    else examine(a+b,0,c);

    if (C-c < b) examine(a,b-C+c,C);
    else examine(a,0,c+b);

    if (A-a < c) examine(A,b,c-A+a);
    else examine(a+c,b,0);

    return;
}

int main()
{
    ifstream input("milk3.in");
    ofstream output("milk3.out");
    input >> A >> B >> C;
    examine(0,0,C);
    int i;
    for (i=0; i<=20; i++)
        if (possible[i])
        {
            output << i;
            break;
        }
    for (i++; i<=20; i++)
        if (possible[i])
            output << " " << i;
    output << endl;
    return 0;
}
