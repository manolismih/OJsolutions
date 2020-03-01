#include <cstdio>
#define mod 1000000007

struct node{
	node *child[10];
	int count;
};

int k,n,q;
node root;
char number[105];

int insert(int actual)
{
	node *curr = &root, *next;
	int i=k-1;
	long long pow=1, money=0;
	while (i>=0)
	{
		next = curr->child[number[i]-'0'];
		if (next==NULL) next = curr->child[number[i]-'0'] = new node{{},0};
		
		money = (money + (pow-1)*(curr->count-next->count)) % mod;
		
		curr = next;
		curr->count += actual;
		i--;
		pow = (pow*2)%mod;
	}
	money = (money + (pow-1)*curr->count) % mod;
	return money;
}

int main()
{
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	scanf("%d%d%d",&k,&n,&q);
	root.count=n;
	for (int i=0; i<n+q; i++)
	{
		scanf("%s",number);
		if (i>=n) printf("%d %d\n",root.child[number[k-1]-'0']->count,insert(0));
		else insert(1);
	}
}
