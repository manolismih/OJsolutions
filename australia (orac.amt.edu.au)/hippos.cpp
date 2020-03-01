#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("hippoin.txt");
ofstream fout("hippoout.txt");
int n, hippo[3], fences[6], apantisi;

int main()
{
	fin >> n >> hippo[0] >> hippo[1] >> hippo[2];
	sort(hippo,hippo+3);
	for (int i=0; i<3; i++)
	{
		fences[2*i] = hippo[i]-1;
		fences[2*i+1] = hippo[i];
	}
	
	for (int f1=0; f1<6; f1++)
		for (int f2=f1+1; f2<6; f2++)
			for (int f3=f2+1; f3<6; f3++)
			{
				int saved=0;
				if (fences[f1] < hippo[0]) saved += fences[f1];
				if (fences[f3] == hippo[2]) saved += n-fences[f3];
				bool clear=true;
				for (int i=0; i<3; i++)
					if (hippo[i]>fences[f1] && hippo[i]<=fences[f2])
					{
						clear = false;
						break;
					}
				if (clear) saved += fences[f2]-fences[f1];
				clear = true;
				for (int i=0; i<3; i++)
					if (hippo[i]>fences[f2] && hippo[i]<=fences[f3])
					{
						clear = false;
						break;
					}
				if (clear) saved += fences[f3]-fences[f2];
				if (saved > apantisi)
					apantisi = saved;
			}
	fout << apantisi << endl;
	return 0;
}

