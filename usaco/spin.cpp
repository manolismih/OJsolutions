/*
ID:manolis2
PROG:spin
LANG:C++11
*/
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("spin.in");
ofstream fout("spin.out");
int speed[5];
bool holes[5][360];

int main()
{
	for (int wedges, wheel=0; wheel<5; wheel++)
	{
		fin >> speed[wheel] >> wedges;
		for (int start, count, wedge=0; wedge<wedges; wedge++)
		{
			fin >> start >> count;
			for (int i = start, metritis=0; metritis<=count; metritis++, i=(i+1)%360)
				holes[wheel][i] = true;
		}
	}
	for (int time=0; time<360; time++)
		for (int pos=0; pos<360; pos++)
			if (holes[0][(pos+360-speed[0]*time%360)%360] 
			&&  holes[1][(pos+360-speed[1]*time%360)%360] 
			&&  holes[2][(pos+360-speed[2]*time%360)%360] 
			&&  holes[3][(pos+360-speed[3]*time%360)%360] 
			&&  holes[4][(pos+360-speed[4]*time%360)%360])
			{
				fout << time << endl;
				return 0;
			}
	fout << "none" << endl;
	return 0;
}

