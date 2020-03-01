/*
ID:manolis2
PROG:window
LANG:C++11
*/
#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

struct part	 {	int x1,y1,x2,y2;		};
struct window{	int x1,y1,x2,y2,entoli;	};
struct node  {	char id; int entoli;	};

list<part> visible;
window windows[256];
list<node> screen;

void cover(char id)
{
	int size = visible.size();
	auto it = visible.begin();
	bool up,down,left,right; // true αν μια πλευρά window βρίσκεται ανάμεσα σε δυο πλευρές part
	for (int i=0; i<size; i++)
	{
		if (windows[id].x2 <= it->x1 || windows[id].x1 >= it->x2
		||	windows[id].y2 <= it->y1 || windows[id].y1 >= it->y2)
		{
			it++;
			continue;
		}
		up    = windows[id].y2 < it->y2 && windows[id].y2 > it->y1;
		down  = windows[id].y1 < it->y2 && windows[id].y1 > it->y1;
		left  = windows[id].x1 < it->x2 && windows[id].x1 > it->x1;
		right = windows[id].x2 < it->x2 && windows[id].x2 > it->x1;
		if (up)
		{
			visible.push_back({it->x1,windows[id].y2,it->x2,it->y2});
			it->y2 = windows[id].y2;
		}
		if (down)
		{
			visible.push_back({it->x1,it->y1,it->x2,windows[id].y1});
			it->y1 = windows[id].y1;
		}
		if (left)
		{
			visible.push_back({it->x1,it->y1,windows[id].x1,it->y2});
			it->x1 = windows[id].x1;
		}
		if (right)
		{
			visible.push_back({windows[id].x2,it->y1,it->x2,it->y2});
			it->x2 = windows[id].x2;
		}
		it = visible.erase(it);
	}
}

double area()
{
	double ret=0;
	for (auto it:visible) ret += (it.x2 - it.x1)*(it.y2 - it.y1);
	return ret;
}

int main()
{
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	char c, id;
	while (scanf(" %c(",&c) && !feof(stdin))
	{
		scanf("%c,",&id);
		if (c=='w')
		{
			scanf("%d,%d,%d,%d",&windows[id].x1,&windows[id].y1,&windows[id].x2,&windows[id].y2);
			if (windows[id].x1 > windows[id].x2) swap(windows[id].x1,windows[id].x2);
			if (windows[id].y1 > windows[id].y2) swap(windows[id].y1,windows[id].y2);
			screen.push_front({id,++windows[id].entoli});
		}
		else if (c=='t') screen.push_front({id,++windows[id].entoli});
		else if (c=='b') screen.push_back ({id,++windows[id].entoli});
		else if (c=='d') ++windows[id].entoli;
		else
		{
			visible.clear();
			visible.push_back({windows[id].x1,windows[id].y1,windows[id].x2,windows[id].y2});
			for (auto it=screen.begin(); !visible.empty();	)
			{
				while (it->entoli != windows[it->id].entoli) it=screen.erase(it);
				if (it->id == id) break;
				cover(it->id);	
				it++;
			}
			printf("%.3f\n",area()/(windows[id].x2 - windows[id].x1)/(windows[id].y2 - windows[id].y1)*100);
		}
		scanf(")");
	}
	return 0;
}

