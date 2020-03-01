#include <cstdio>
#include <algorithm>
using namespace std;

int n,x,y,left,right,from,to,size;

bool examine(int x, int y)
{
	if (x>n || x<1 || y<1 || y>n) return 0;
	else printf("examine %i %i\n",x,y);
 	char c;
 	scanf(" %c%*s",&c);
 	return c=='t';
}

int main()
{
	scanf("%i%i%i",&n,&x,&y);
	
	from=1, to=x; // lower bound x
	while (from != to && !examine((from+to)/2,y))
		from = (from+to)/2 + 1;
	if (from != to)
		if (!examine((from+3*to)/4,y)) from = (from+3*to)/4 + 1;
		else if (!examine((from+7*to)/8,y)) from = (from+7*to)/8 + 1;
	while (from != to)
		if (!examine((from+to)/2,y)) from = (from+to)/2 + 1;
		else to = (from+to)/2;
	left = from;
	
	from=x,to=n; // upper bound x
	while (from != to && !examine((from+to)/2,y))
		to = (from+to)/2 - 1;
	if (from != to)
		if (!examine((3*from+to)/4,y)) to = (3*from+to)/4;
		else if (!examine((7*from+to)/8,y)) to = (7*from+to)/8; 
	while (from != to)
		if (!examine((from+to)/2 + 1,y)) to = (from+to)/2;
		else from = (from+to)/2 + 1;
	right = from;
	
	size = right-left+1;
	x = (right+left)/2;
	
	from=y, to=n; // upper bound y
	while (from != to && !examine(x,(from+to)/2))
		to = (from+to)/2 - 1;
	if (from != to)
		if (!examine(x,(3*from+to)/4)) to = (3*from+to)/4;
		else if (!examine(x,(7*from+to)/8)) to = (7*from+to)/8;
	while (from != to)
		if (!examine(x,(from+to)/2 + 1)) to = (from+to)/2;
		else from = (from+to)/2 + 1;
	y = from - size/2;	 
	
	while (examine(x-2*size,y)) x -= 2*size;
	while (examine(x,y-2*size)) y -= 2*size;
	if (examine(x-size,y-size)) x-=size, y-=size;
	printf("solution %i %i\n",x+2*size,y+2*size);
	return 0;
}

