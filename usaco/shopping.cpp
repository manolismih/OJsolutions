/*
ID:manolis2
PROG:shopping
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

ifstream fin("shopping.in");
ofstream fout("shopping.out");
struct validitem{
	int quantity, price;
};
validitem needs[5] = {0,0};
int noffers, nwanted, memo[6][6][6][6][6];
struct prosfora{
	int ylika[5],price;
};
vector<prosfora> offers;
map<int,int> katalogos;

int main()
{
	fin >> noffers;
	for (int temp, i=0; i<noffers; i++)
	{
		fin >> temp;
		fin.ignore(500,'\n');
	}
	fin >> nwanted;
	for (int code, i=0; i<nwanted; i++)
	{
		fin >> code >> needs[i].quantity >> needs[i].price;
		katalogos[code] = i;
	}
	fin.seekg(0);
	
	fin >> noffers;
	for (int eidi, i=0; i<noffers; i++)
	{
		fin >> eidi;
		if (eidi > nwanted) 
		{
			fin.ignore(500,'\n');
			continue;
		}
		bool ok = true;
		prosfora temp = {0,0,0,0,0,0};
		for (int product, quantity, i=0; i<eidi; i++)
		{
			fin >> product >> quantity;
			if (katalogos.find(product) == katalogos.end())
			{
				ok = false;
				fin.ignore(500,'\n'); 
				break;
			}
			temp.ylika[katalogos[product]] = quantity;
		}
		if (ok)
		{
			fin >> temp.price;
			offers.push_back(temp);
		}
	}
	noffers = offers.size();
	
	//dp
	for (int p1=0; p1 <= needs[0].quantity; p1++)
		for (int p2=0; p2 <= needs[1].quantity; p2++)
			for (int p3=0; p3 <= needs[2].quantity; p3++)
				for (int p4=0; p4 <= needs[3].quantity; p4++)
					for (int p5=0; p5 <= needs[4].quantity; p5++)
					{
						memo[p1][p2][p3][p4][p5] = 2000000000;
						for (auto it=offers.begin(); it!=offers.end(); it++)
							if (p1 - it->ylika[0] > -1 
							&& p2 - it->ylika[1] > -1 
							&& p3 - it->ylika[2] > -1 
							&& p4 - it->ylika[3] > -1 
							&& p5 - it->ylika[4] > -1)
								if (it->price + memo[p1-it->ylika[0]][p2-it->ylika[1]][p3-it->ylika[2]][p4-it->ylika[3]][p5-it->ylika[4]] < memo[p1][p2][p3][p4][p5])
									memo[p1][p2][p3][p4][p5] = it->price + memo[p1-it->ylika[0]][p2-it->ylika[1]][p3-it->ylika[2]][p4-it->ylika[3]][p5-it->ylika[4]];
						if (p1*needs[0].price + p2*needs[1].price + p3*needs[2].price + p4*needs[3].price + p5*needs[4].price < memo[p1][p2][p3][p4][p5])
							memo[p1][p2][p3][p4][p5] = p1*needs[0].price + p2*needs[1].price + p3*needs[2].price + p4*needs[3].price + p5*needs[4].price;
					}
	fout << memo[needs[0].quantity][needs[1].quantity][needs[2].quantity][needs[3].quantity][needs[4].quantity] << endl;
	return 0;
}

