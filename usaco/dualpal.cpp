/*
ID: manolis2
PROG: dualpal
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
    ifstream input("dualpal.in");
    ofstream output("dualpal.out");
    int n, s, i=0, found;
    input >> n >> s;
    do
    {
        s++;
        found=0;
        for (int base=2; base <= 10; base++)
        {
            if (ispalindrome(convert(s,base)))
                found++;
            if (found==2)
            {
                output << s << endl;
                i++;
                break;
            }
        }
    }
    while (i<n);

}
