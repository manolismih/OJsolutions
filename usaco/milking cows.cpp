/*
ID: manolis2
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int times[1000000] = {0};

int main()
{
    ifstream input("milk2.in");
    ofstream output("milk2.out");
    int n, a, b;
    input >> n;

    for (int i=1; i<=n; i++)
    {
        input >> a >> b;
        times[a]++;
        times[b]--;
    }

    n = 0;
    while (times[n] == 0)
        n++;

    int last=999999;
    while (times[last] == 0)
        last--;

   int cows=0, tempmaxmilk=0, maxmilk=0, tempmaxgap=0, maxgap=0;

   for (int i=n; i<=last; i++)
   {
       cows += times[i];
       if (cows==0)
       {
           if (tempmaxmilk>maxmilk)
                maxmilk=tempmaxmilk;
           tempmaxmilk = 0;
           i++;
           if (i<last)
           {
            tempmaxgap=1;
            while (times[i]==0)
           {
               tempmaxgap++;
               i++;
           }
           i--;
           if (tempmaxgap>maxgap)
                maxgap = tempmaxgap;
           }
       }
       else
           tempmaxmilk++;
   }

   output << maxmilk << " " << maxgap << endl;


    return 0;
}
