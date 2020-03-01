#include <cstdio>
#include <list>
using namespace std;

FILE *fin=fopen("shufflein.txt","r"), *fout=fopen("shuffleout.txt","w");
int n, k;

struct node{
	int pos, id;
};
inline bool operator<(node a, node b)
{
	if (a.pos != b.pos) return a.pos < b.pos;
	else return a.id;
}
list<node> seats, ipourgoi;

inline list<node>::iterator next(list<node>::iterator curr)
{
	if (++curr == seats.end())
		curr = seats.begin();
	return curr;
}
inline list<node>::iterator prev(list<node>::iterator curr)
{
	if (curr == seats.begin())
		curr = seats.end();
	return --curr;
}

int main()
{
	fscanf(fin,"%d%d",&n,&k);
	node temp = {0,0};
	for (int i=0; i<k; i++)
	{
		fscanf(fin,"%i",&temp.pos);
		seats.push_back(temp);
	}
	int first = seats.front().pos;
	for (int i=1; i<k+2; i++)
	{
		fscanf(fin,"%i",&temp.pos);
		temp.id = i;
		ipourgoi.push_back(temp);
	}
	seats.merge(ipourgoi);
	
	list<node>::iterator it = seats.begin();
	for (int deleted=0; deleted<k; )
	{
		if (it->id && !next(it)->id)
		{
			if (next(it)->pos == first)
				fprintf(fout,"%i\n",it->id);
			seats.erase(next(it));
			it = prev(it);
			seats.erase(next(it));
			deleted++;
		}
		else it = next(it);
	}
	fprintf(fout,"%d\n",seats.front().id);
	return 0;
}
