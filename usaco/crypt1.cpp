/*
ID: manolis2
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

bool ballowed[10] = {0};
int nallowed[10], solutions=0;

bool valid(int number, int digits)
{
    if (ballowed[number%10])
        if (ballowed[(number%100)/10])
            if (ballowed[(number%1000)/100])
            {
                if ((digits==4) && (!ballowed[number/1000]))
                    return false;
                return true;
            }
    return false;
}

void check(int x, int y)
{
    if ((x*y < 1111) || (x*y > 9999))
        return;
    int part1 = (y%10)*x, part2 = (y/10)*x;
    if ((part1 > 999) || (part2 > 999))
        return;
    if ((valid(part1,3)) && (valid(part2,3)) && (valid(x*y,4)))
        solutions++;
    return;
}

int main()
{
    ifstream input("crypt1.in");
    ofstream output("crypt1.out");
    int n;
    input >> n;
    for (int i=0; i<n; i++)
    {
        input >> nallowed[i];
        ballowed[nallowed[i]] = true;
    }
    int a[3], b[2];
    for (a[0]=0; a[0]<n; a[0]++)
        for (a[1]=0; a[1]<n; a[1]++)
            for (a[2]=0; a[2]<n; a[2]++)
                for (b[0]=0; b[0]<n; b[0]++)
                    for (b[1]=0; b[1]<n; b[1]++)
                        {
                            check(nallowed[a[0]]*100+nallowed[a[1]]*10+nallowed[a[2]],nallowed[b[0]]*10+nallowed[b[1]]);
                        }
    output << solutions << endl;
    return 0;
}
