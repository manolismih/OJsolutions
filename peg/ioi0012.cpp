#include <list>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node{	int marka, area, pos; bool vis;};

int n,m,w,rounds, pin[20005];
list<node> lista;
list<node>::iterator arxi[55], stack[55];

int nalages, ansi;
char alages[1000];

list<node>::iterator del(list<node>::iterator it)
{
	if (it != arxi[it->area]) return lista.erase(it);
	else return arxi[it->area] = lista.erase(it);
}

void circle(int &i) // to stack exei i+1 stoixeia, apo 0 os i kai stack[i]==stack[j], j<i
{
	int last = i;
	for (i--; stack[i] != stack[last]; i--)
	{
		ansi += sprintf(alages+ansi,"%d %d ",stack[i]->pos,stack[i+1]->pos);
		nalages++;
	}	
	ansi += sprintf(alages+ansi,"%d %d ",stack[i]->pos,stack[i+1]->pos);
	nalages++;
	
	if (stack[last-1]->marka == stack[last]->area) del(stack[last]);
	else
	{
		 stack[last]->marka = stack[last-1]->marka;
		 stack[last]->vis = 0;
	}
	for (int j=i+1; j<last; j++) del(stack[j]);
}

int main()
{
	//freopen("out.txt","w",stdout);
	printf("      ");
	scanf("%d%d%d",&n,&m,&w);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&pin[i]);
		lista.push_back({pin[i],0,i,0});
	}
	sort(pin+1,pin+n+1);
	auto it = lista.begin();
	for (int i=1; i<=n; i++,it++)
	{
		it->area = pin[i];
		if (pin[i] != pin[i-1]) arxi[pin[i]] = it;
	}
	for (auto it=lista.begin(); it!=lista.end();)
		if (it->marka == it->area) it = del(it);
		else it++;
	
	while (!lista.empty())
	{
		rounds++, ansi=0, nalages=0;
		int stacki=0, rem=w;
		while (!lista.empty() && rem)
		{
			if (stacki==0) stack[stacki] = lista.begin();
			else stack[stacki] = arxi[stack[stacki-1]->marka];
			
			if (stack[stacki]->vis) circle(stacki);
			else stack[stacki++]->vis=1, rem--;
		}
		if (stacki>1)
		{
			stack[stacki] = stack[0];
			circle(stacki);
		}
		else for (int i=0; i<stacki; i++) stack[i]->vis = 0;
		printf("%d %s\n",nalages,alages);
	}
	rewind(stdout);
	printf("%d\n",rounds);
}
