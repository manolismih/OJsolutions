/*
ID: manolis2
PROG: calfflac
LANG:C++
*/
#include <cstdio>
#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

string initial = "", simplified = "";
int bigger[2] = {1,0}, helpar[30000];
int simpchars=0,allchars=0;

void check(int left, int right)
{
    while ((left > 0) && (right < simpchars) && (simplified[left-1] == simplified[right+1]))
    {
        left--;
        right++;
    }
    if (right-left+1 > bigger[0])
    {
        bigger[0] = right-left+1;
        bigger[1] = left;
    }
    return;
}

int main()
{
    FILE *input = fopen("calfflac.in","r");
    FILE *output = fopen("calfflac.out","w");
    char c;
    while ((c = getc(input)) != EOF)
    {
        initial += c;
        if (isalpha(c))
        {
            simplified += toupper(c);
            helpar[simpchars] = allchars;
            simpchars++;
        }
        allchars++;

    }
    for (int i=1; i<simpchars; i++)
    {
        check(i,i);
        check(i+1,i);
    }
    fprintf(output,"%i\n",bigger[0]);
    for (int i=helpar[bigger[1]]; i<=helpar[bigger[1]+bigger[0]-1]; i++)
        fprintf(output,"%c",initial[i]);
    fprintf (output,"\n");
    return 0;

}
