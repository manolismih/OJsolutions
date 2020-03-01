#include <cstdio>
#include <list>
using namespace std;

FILE *fin = fopen("partyin.txt","r"), *fout = fopen("partyout.txt","w");
int n,m,k,nk,connections[1005], apantisi;
list<int> alist[1005];
bool deleted[1005];

int main()
{
	fscanf(fin,"%d%d%d%d",&n,&m,&k,&nk);
	for (int a,b, i=0; i<m; i++)
	{
		fscanf(fin,"%d%d",&a,&b);
		alist[a].push_back(b);
		alist[b].push_back(a);
		connections[a]++, connections[b]++;
	}
	apantisi = n;
	for (bool changed=true; changed;)
	{
		changed = false;
		for (int i=1; i<=n; i++)
			if (!deleted[i] && (connections[i] < k || connections[i] > apantisi-nk-1))
			{
				changed = true;
				deleted[i] = true;
				apantisi--;
				for (list<int>::iterator it = alist[i].begin(); it != alist[i].end(); it++)
					if (!deleted[*it])
						connections[*it]--;
			}
	}
	fprintf(fout,"%d\n",apantisi);
	return 0;
}

