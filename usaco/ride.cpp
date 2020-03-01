/*
USER: manolis2
PROG: ride
LANG: C++
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    FILE *input = fopen ("ride.in","r");
    FILE *output = fopen ("ride.out","w");
    char c;
    int64_t planet, crew;
    planet = 1;
    crew = 1;
    while (1)
    {
        fscanf(input,"%c",&c);
        if (c=='\n')
            break;
        planet *= ((int)c) - 64;
    }
    while (1)
    {
        fscanf(input,"%c",&c);
        if (c == '\n')
            break;
        crew *= ((int)c) - 64;
    }
    if ((planet % 47) == (crew % 47))
        fprintf(output,"%s\n","GO");
    else
        fprintf(output,"%s\n","STAY");
    return 0;
}
