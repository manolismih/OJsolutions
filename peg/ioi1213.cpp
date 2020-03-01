#include <cstdio>

struct node{
	char letter;
	int depth;
	node *next[26], *par[21];
};
node tree={0,-1}, *curr= &tree, *map[1000005]={&tree};
int n,entoli;

void type(char c)
{
	if (!curr->next[c-'a']) curr->next[c-'a'] = new node{0};
	curr->next[c-'a']->par[0] = curr;
	map[entoli] = curr = curr->next[c-'a'];
	curr->letter = c;
	curr->depth = curr->par[0]->depth +1;
	for (int i=1; curr->par[i-1] && i<21; i++)
		curr->par[i] = curr->par[i-1]->par[i-1];
}

void undo(int num)
{
	curr = map[entoli] = map[entoli-num-1];
}

char letter(int depth)
{
	node *temp = curr;
	int i;
	while (temp->depth > depth)
	{
		for (i=0; temp->par[i] && temp->par[i]->depth >= depth; i++);
		temp = temp->par[i-1];
	}
	return temp->letter;
}

int main()
{
	scanf("%d",&n);
	char c; int num;
	for (int i=0; i<n; i++)
	{
		scanf(" %c",&c);
		if (c=='T')
		{
			scanf(" %c",&c);
			entoli++;
			type(c);
		}
		else
		{
			scanf("%d",&num);
			if (c=='P') printf("%c\n",letter(num));
			else
			{
				entoli++;
				undo(num);
			}
		}
	}
	return 0;
}

