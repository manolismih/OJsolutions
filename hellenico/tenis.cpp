#include <fstream>

using namespace std;

int total, helpar[100000], n, temp, minus[100000][2], minusf, minusl, helpari;
ifstream input("tennis.in");
ofstream output("tennis.out");

void examine()
{
	
}

int main()
{

	int t;
	input >> t;
	bool ok;
	
	for (int i=0; i<t; i++)
	{
		input >> n;
		for (int j=0; j<n; j++)
			helpar[j] = 0;
		total=0; ok=true;
		for (int j=0; j<n; j++)
		{
			input >> temp;
			helpar[temp]++;
			total+=temp;
		}
		if ((total%2 != 0) || (total>(n*n-n)/2))
		{
			output << "Not Possible" << endl;
			continue;
		}
		for (int j=n-1; i>-1; i--)
			if (helpar[j]!=0)
			{
				if (j>n-1)
					ok=false;
				break;
			}
		if (!ok)
		{
			output << "Not possible" << endl;
			continue;
		}
		helpari=0;
		minusf=0;
		minusl=0;
		examine();
	}
	return 0;
}

