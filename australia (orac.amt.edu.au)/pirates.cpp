#include <cstdio>
#include <algorithm>
using namespace std;

int l, d1, d2;
int main()
{
	freopen("piratein.txt","r",stdin);
	freopen("pirateout.txt","w",stdout);
	scanf("%d%d%d",&l,&d1,&d2);
	printf("%i\n",min(d1+d2,l-d1+l-d2));
	return 0;
}

