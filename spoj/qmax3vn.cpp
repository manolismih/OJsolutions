#include <cstdio>
#include <algorithm>
using namespace std;
#define inf 2000000000

struct node{
	int num,seats,max;
	node *left ,*right;
};
int n,q,queries[100005][3];
node *tree;

void maketree(node *curr)
{
	if (curr->seats < 2) return;
	curr->left = new node{0,curr->seats/2,-inf,0,0};
	curr->right = new node{0,curr->seats/2 + (curr->seats%2 ? 1 : 0),-inf,0,0};
	maketree(curr->left);
	maketree(curr->right);
}

void add(int height, int pos, node *curr)
{
	if (!curr->left)
	{
		curr->max = height;
		curr->seats = 0;
		curr->num = 1;
		return;
	}
	if (curr->left->seats < pos) add(height,pos-curr->left->seats,curr->right);
	else add(height,pos,curr->left);
	if (height > curr->max) curr->max = height;
	--curr->seats;
	++curr->num;
}

void purge(int pos, node *curr)
{
	if (!curr->left)
	{
		curr->max = -inf;
		curr->num = 0;
		return;
	}
	if (curr->left->num < pos) purge(pos-curr->left->num,curr->right);
	else purge(pos,curr->left);
	--curr->num;
	curr->max = max(curr->left->max,curr->right->max);
}

int query(int skip, int length, node *curr)
{
	if (!skip && curr->num == length) return curr->max;
	int ret = -inf;
	if (skip < curr->left->num)
		if (skip+length <= curr->left->num) return query(skip,length,curr->left);
		else return max(query(skip,curr->left->num-skip,curr->left),
						query(0,length-curr->left->num+skip,curr->right));
	return query(skip-curr->left->num,length,curr->right);
}

void dfs(node *curr)
{
	if (!curr->left) 
		if (curr->max != -inf) printf("%d ",curr->max);
		else;
	else dfs(curr->left), dfs(curr->right);
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&q);
	char c;
	for (int i=0; i<q; i++)
	{
		scanf(" %c%d%d",&c,&queries[i][1],&queries[i][2]);
		queries[i][0] = (c=='A');
		if (queries[i][0]) n++;
	}
	tree = new node{0,n,-inf,0,0};
	maketree(tree);
	
	for (int i=q-1; i>-1; i--)
		if (queries[i][0]) add(queries[i][1],queries[i][2],tree);
		
	//dfs(tree), printf("\n");
		
	for (int i=q-1; i>-1; i--)
		if (queries[i][0])
		{
			purge(queries[i][2],tree);
			//dfs(tree), printf("\n");
		} 
		else queries[i][1] = query(queries[i][1]-1,queries[i][2]-queries[i][1]+1,tree);
		
	for (int i=0; i<q; i++)
		if (!queries[i][0]) printf("%d\n",queries[i][1]);
	return 0;
}
