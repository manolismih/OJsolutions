/*
ID: manolis2
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int monthdays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days[8] = {0};
int n, weekday, month = 1, year = 1900;

bool disekto()
{
    if (year % 100 == 0)
        if (year % 400 == 0)
            return(1);
        else return(0);
    else
        if (year % 4 == 0)
            return(1);
        else return(0);
}

void next13()
{
    int plusdays;
    if (month == 2)
        if (disekto())
            plusdays = 29;
        else plusdays = 28;
    else
        plusdays = monthdays[month];

    month++;
    if (month > 12)
    {
        month=1;
        year++;
    }
    weekday += plusdays%7;
    if (weekday > 7)
        weekday %= 7;
}


int main()
{
    ifstream input("friday.in");
    ofstream output ("friday.out");
    input >> n;
    weekday = 6;
    days[6]++;
    while (year < 1900+n)
    {
        next13();
        days[weekday]++;
    }
    days[weekday]--;
    output << days[6] << " " << days[7];
    for (int i=1; i <= 5; i++)
        output << " " << days[i];
    output << endl;
    return 0;
}
