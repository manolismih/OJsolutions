#include <cstdio>
#include <cstring>

struct node{
	int freq;
	node *next[4];
};
node trie, *curr;

int t,n,best[55],iii,apantisi;
char c;

void reset(node *curr)
{
	curr->freq = 0;
	for (int i=0; i<4; i++)
		if (curr->next[i])
		{
			reset(curr->next[i]);
			delete curr->next[i];
		}
}

void init()
{
	reset(&trie);
	for (int i=0; i<4; i++)
		trie.next[i] = 0;
	memset(best,0,55*4);
	curr = &trie;
	apantisi=0;
}

inline int convert(char c)
{
	if (c=='A') return 0;
	else if (c=='C') return 1;
	else if (c=='G') return 2;
	else if (c=='T') return 3;
}

//FILE *f=fopen("in.txt","r");

int main()
{
	scanf("%i",&t);
	for (int i=1; i<=t; i++)
	{
		init();
		scanf("%i%*c",&n);
		for (int i=0; i<n; i++,curr=&trie)
			for (int i=1; scanf("%c",&c) && c!='\n'; i++)
			{
				iii = convert(c);
				if (!curr->next[iii]) curr->next[iii] = new node{0};
				curr = curr->next[iii];
				if (++curr->freq > best[i]) best[i] = curr->freq;	
			}
		for (int i=1; i<51; i++)
			if (i*best[i] > apantisi) apantisi = i*best[i];
		
		printf("Case %i: %i\n",i,apantisi);
	}
	return 0;
}

