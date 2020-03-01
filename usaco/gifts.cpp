/*
USER: manolis2
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char names[16][11];
int gifters;

int match(char matched[16])
{
    for (int i=1; i<=gifters; i++)
        if (!strcmp(matched,names[i]))
            return(i);
}

int main()
{
    ifstream input("gift1.in");
    ofstream output("gift1.out");

    input >> gifters;
    for (int i = 1; i<=gifters; i++)
        input >> names[i];

    char name[16];
    int finalmoney[11] = {0};
    int initmoney[11];
    int givemoney, people, matchcode;

    while (input)
    {
        input >> name;
        if (input)
        {


            input >> givemoney >> people;
            matchcode = match(name);
            initmoney[matchcode] = givemoney;
            finalmoney[matchcode] += givemoney;
            if ((givemoney != 0) && (people != 0) )
            {
                finalmoney[matchcode] -= givemoney-givemoney%people;
                for (int i=1; i <= people; i++)
                {
                    input >> name;
                    finalmoney[match(name)] += givemoney/people;
                }
            }
            else if (people != 0)
                for (int i=1; i<=people; i++)
                    input >> name;
        }


    }

    for (int i=1; i<=gifters; i++)
        output << names[i] << " " << finalmoney[i]-initmoney[i] << endl;

    return 0;
}
