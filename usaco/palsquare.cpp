/*
ID: manolis2
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string convert(int number, int base)
{
    string s = "";
    while (number/base != 0)
    {
        if (number%base < 10)
            s += 48+number%base;
        else
            s += (char)(65+(number%base)%10);
        number /= base;
    }

    if (number%base < 10)
        s += 48+number%base;
    else
        s += (char)(65+(number%base)%10);
    string snew = string(s.rbegin(),s.rend());
    return snew;
}

bool ispalindrome(string s)
{
    string newstring = string(s.rbegin(),s.rend());
    if (s == newstring)
        return true;
    else return false;
}

int main()
{
    ifstream input("palsquare.in");
    ofstream output("palsquare.out");
    int base;
    input >> base;
    for (int i=1; i<=300; i++)
        if (ispalindrome(convert(i*i,base)))
            output << convert(i,base) << ' ' << convert(i*i,base) << endl;

    return 0;
}
