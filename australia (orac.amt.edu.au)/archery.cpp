#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("archin.txt");
ofstream fout("archout.txt");
int n, a, b;

int main()
{
	fin >> n >> a >> b;
	if (b<a) swap(a,b);
	fout << (a-n+b>0 ? a-n+b : 1) << ' ' << (b+a-1<=n ? b+a-1 : n) << endl;
	return 0;
}

