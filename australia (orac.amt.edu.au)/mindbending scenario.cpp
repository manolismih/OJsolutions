#include <cstdio>
#include <algorithm>
using namespace std;

int commonx(int x1, int x2, int x3, int x4)
{
	if (x1>x3)
	{
		swap(x1,x3);
		swap(x2,x4);
	}
	if (x2<=x3) return 0;
	else if (x2<=x4) return x2-x3;
	else return x4-x3;
}

int main()
{
	freopen("bendin.txt","r",stdin);
	freopen("bendout.txt","w",stdout);
	int x1,x2,x3,x4,y1,y2,y3,y4;
	scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	int area1 = (x2-x1)*(y2-y1);
	int area2 = (x4-x3)*(y4-y3);
	printf("%d", area1+area2-commonx(x1,x2,x3,x4)*commonx(y1,y2,y3,y4) );

}
