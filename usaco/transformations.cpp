/*
ID: manolis2
PROG: transform
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream input("transform.in");
ofstream output("transform.out");
int n;
char arxiko[11][11] = {0};
string teliko = "", line;

bool move1(char board[11][11])
{
    string s="";
    for (int j=0; j<n; j++)
        for (int i=n-1; i>-1; i--)
            s += board[i][j];
    return (s==teliko);
}

bool move2(char board[11][11])
{
    string s="";
    for (int i=n-1; i>-1; i--)
        for (int j=n-1; j>-1; j--)
            s+= board[i][j];
    return (s==teliko);
}

bool move3(char board[11][11])
{
    string s="";
    for (int j=n-1; j>-1; j--)
        for (int i=0; i<n; i++)
            s+= board[i][j];
    return (s==teliko);
}

bool move4(char board[11][11])
{
    string s="";
    for (int i=0; i<n; i++)
        for (int j=n-1; j>-1; j--)
            s+= board[i][j];
    return (s==teliko);

}

bool move5(char board[11][11])
{
    string s="";
    for (int i=0; i<n; i++)
        for (int j=n-1; j>-1; j--)
            s+= board[i][j];
    int k=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            {
                board[i][j] = s[k];
                k++;
            }
    if (move1(board) || move2(board) || move3(board))
        return true;
    else return false;
}

bool move6(char board[11][11])
{
    string s="";
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            s+= board[i][j];
    return (s==teliko);
}

int main()
{
    input >> n;
    for (int i=0; i<n; i++)
        input >> arxiko[i];
    for (int i=0; i<n; i++)
    {
        input >> line;
        teliko += line;
    }
    if (move1(arxiko))
    {
        output << 1 << endl;
        return 0;
    }

   if (move2(arxiko))
    {
        output << 2 << endl;
        return 0;
    }

    if (move3(arxiko))
    {
        output << 3 << endl;
        return 0;
    }

    if (move4(arxiko))
    {
        output << 4 << endl;
        return 0;
    }
    if (move5(arxiko))
    {
        output << 5 << endl;
        return 0;
    }
    if (move6(arxiko))
    {
        output << 6 << endl;
        return 0;
    }
    output << 7 << endl;
    return 0;
}
