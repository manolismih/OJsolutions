/*
ID: manolis2
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct prosfora
    {
        int price, quantity;
    };

bool compare(prosfora x, prosfora y)
{
    return (x.price < y.price);
}

int main()
{
    ifstream input("milk.in");
    ofstream output("milk.out");
    int milkneed, farmers;
    input >> milkneed >> farmers;

    prosfora pricelist[5000] = {0};
    for (int i=0; i<farmers; i++)
        input >> pricelist[i].price >> pricelist[i].quantity;
    sort(pricelist,pricelist+farmers,compare);
    int i=0, totalprice = 0;
    while (milkneed-pricelist[i].quantity > 0)
    {
        milkneed -= pricelist[i].quantity;
        totalprice += pricelist[i].quantity * pricelist[i].price;
        i++;
    }
    totalprice += milkneed * pricelist[i].price;
    output << totalprice << endl;
    return 0;
}
