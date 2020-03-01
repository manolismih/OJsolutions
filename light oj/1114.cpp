#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int t,n,m,apantisi;
char helpar[128],c,pr;
string s;
map<string,int> combos;

void readword()
{
	bool islongerthan1=false;
	memset(helpar+'A',0,26), memset(helpar+'a',0,26);
	s = pr;
	while (scanf("%c",&c) && c!=' ' && c!='\n')
	{
		islongerthan1=true;
		helpar[c]++;
		pr = c;
	}	
	if (!islongerthan1) return;
	helpar[pr]--;
	for (int i='A'; i<='Z'; i++)
		s.append(helpar[i],i);
	for (int i='a'; i<='z'; i++)
		s.append(helpar[i],i);
	s += pr;
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%i",&t);
	for (int i=1; i<=t; i++)
	{
		combos.clear();
		printf("Case %i:\n",i);
		
		scanf("%i%*c",&n);
		for (int i=0; i<n; i++)
		{
			scanf("%c",&pr);
			readword();
			combos[s]++;
		}
		
		scanf("%i%*c",&m);
		for (int i=0; i<m; i++)
		{
			apantisi=1;
			while (1)
			{
				while (scanf("%c",&pr) && pr==' ');
				if (apantisi && pr!='\n')
				{
					readword();
					apantisi *= combos[s];
				}
				if (pr=='\n' || c=='\n')
				{
					printf("%i\n",apantisi);
					break;
				}
			}	
		}
	}
	return 0;
}

