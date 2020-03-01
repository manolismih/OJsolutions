#include <cstdio>

struct node{
	bool isword;
	node *next[10];
};
node tree, *curr;
int t,n;
char c;

void reset(node *curr)
{
	curr->isword = false;
	for (int i=0; i<10; i++)
		if (curr->next[i]) 
		{
			reset(curr->next[i]);
			delete curr->next[i];
			curr->next[i] = 0;
		}
}

int main()
{
	scanf("%i",&t);
	for (int i=1; i<=t; i++)
	{
		scanf("%i%*c",&n);
		reset(&tree);
		bool apantisi=true;
		for (int i=0; i<n; i++)
		{
			if (apantisi)
			{
				curr = &tree;
				while (scanf("%c",&c) && c!='\n')
				{
					if (!curr->next[c-'0']) curr->next[c-'0'] = new node{0};
					curr = curr->next[c-'0'];
					if (curr->isword)
					{
						apantisi = false;
						break;
					}		
				}
				if (!apantisi)
				{
					while (scanf("%c",&c) && c!='\n');
					continue;
				}
				curr->isword = true;
				for (int i=0; i<10; i++)
					if (curr->next[i])
					{
						apantisi = false;
						break;
					}
			}
			else scanf(" %*s");
		}
		printf(apantisi ? "Case %i: YES\n" : "Case %i: NO\n",i);
	}
	return 0;
}

