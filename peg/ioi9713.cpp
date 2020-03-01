#include <cstdio>
#include <algorithm>
using namespace std;

int dim[3],pos[3],p[3],dir,best;
bool eaten[35][35][35];



int main()
{
	for (int i=0; i<3; i++)
	{
		scanf("%d",&dim[i]);
		p[i] = i;
	}
	x = y = z = dir = 1;
	while (true)
	{
		best = max(best,compute());
		if (!next_permutation(p,p+3)) break;
	}
}
