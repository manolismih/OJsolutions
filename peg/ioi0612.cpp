#include <cstdio>
#include <list>

struct minlist{
		int maxdiff, time=0;
		std::list<std::pair<int,int>> lista;

		void push(int val)
		{
			while (!lista.empty() && lista.back().first >= val) lista.pop_back();
			lista.push_back({val,++time});
		}
		int min()
		{
			while (lista.front().second <= time-maxdiff) lista.pop_front();
			return lista.front().first;
		}
};

int c,r,W,H,w,h, pista[1005][1005], SUM[1005][1005], sum[1005][1005], min[1005][1005];

void findmin(int platos, int ipsos)
{
	minlist stiles[1005];
	for (int i=0; i<1005; i++) stiles[i].maxdiff=ipsos;
	for (int y=1; y<ipsos; y++)
		for (int x=1; x<=c; x++)
			stiles[x].push(sum[y][x]);
	
	minlist lista;
	lista.maxdiff = platos;
	for (int y=ipsos; y<=r; y++)
	{
		lista.lista.clear();
		for (int x=1; x<platos; x++)
		{
			stiles[x].push(sum[y][x]);
			lista.push(stiles[x].min());
		}
		for (int x=platos; x<=c; x++)
		{
			stiles[x].push(sum[y][x]);
			lista.push(stiles[x].min());
			min[y-ipsos+1][x-platos+1] = lista.min();
		}
	}
}

void findsum(int platos, int ipsos, int s[1005][1005])
{
	int stiles[1005] = {0};
	for (int y=1; y<ipsos; y++)
		for (int x=1; x<=c; x++)
			stiles[x] += pista[y][x];
			
	for (int y=ipsos; y<=r; y++)
	{
		int sum=0;
		for (int x=1; x<platos; x++)
		{
			stiles[x] += pista[y][x] - pista[y-ipsos][x];
			sum += stiles[x];
		}
		for (int x=platos; x<=c; x++)
		{
			stiles[x] += pista[y][x] - pista[y-ipsos][x];
			sum += stiles[x] - stiles[x-platos];
			s[y-ipsos+1][x-platos+1] = sum;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d%d%d%d",&c,&r,&W,&H,&w,&h);
	for (int y=1; y<=r; y++)
		for (int x=1; x<=c; x++)
			scanf("%d",&pista[y][x]);
			
	findsum(W,H,SUM);
	findsum(w,h,sum);
	// για καθε y,x ψάχνουμε στον πίνακα sum το min σε ορθογώνιο μεγέθους W-w-1 X H-h-1
	findmin(W-w-1,H-h-1);
	
	int best=0, xbest, ybest;
	for (int y=1; y<=r-H+1; y++)
		for (int x=1; x<=c-W+1; x++)
			if (SUM[y][x] - min[y+1][x+1] > best)
			{
				best = SUM[y][x] - min[y+1][x+1];
				xbest = x;
				ybest = y;
			}
	int target = SUM[ybest][xbest] - best;
	for (int y=ybest+1; y<ybest+H-h; y++)
		for (int x=xbest+1; x<xbest+W-w; x++)
			if (sum[y][x] == target)
			{
				printf("%d %d\n%d %d\n",xbest,ybest,x,y);
				return 0;
			}
}

