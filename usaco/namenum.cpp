/*
ID: manolis2
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

string names[5000], cowname, letters[10];
int oknames, cowdigits, cownum[12];
ofstream output("namenum.out");
bool found = false;


void checkname(int8_t letter, string name)
{
    if (letter>cowdigits)
    {
        if (binary_search(names,names+oknames,name))
        {
            output << name << endl;
            found=true;
        }

    }
    else
        for (int i=0; i<=2; i++)
        {
           checkname(letter+1,name + letters[cownum[letter-1]][i]);
        }

}

int main()
{
    ifstream input("namenum.in");
    ifstream dict("dict.txt");
    oknames = 0;
    while (dict)
    {
        oknames++;
        dict >> names[oknames];
    }
    oknames--;
    input >> cowname;
    cowdigits = cowname.length();
    for (int i=0; i< cowdigits; i++)
        cownum[i] = int(cowname[i]) - 48;
    letters[2] = "ABC";
    letters[3] = "DEF";
    letters[4] = "GHI";
    letters[5] = "JKL";
    letters[6] = "MNO";
    letters[7] = "PRS";
    letters[8] = "TUV";
    letters[9] = "WXY";
    checkname(1,"");
    if (!found)
        output << "NONE" << endl;
    return 0;
}
