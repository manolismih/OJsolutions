#include <cstdio>

int n,moves,pos,a,b;

int main()
{
	freopen("handin.txt","r",stdin);
	freopen("handout.txt","w",stdout);
	scanf("%d%d%d",&n,&pos,&moves);
	for (int i=0; i<moves; i++)
	{
		scanf("%d%d",&a,&b);
		if (pos==a)
			pos=b;
		else if (a<pos && b>=pos)
			pos--;
		else if (a>pos && b<=pos)
			pos++;
	}
	printf("%d\n",pos);
	return 0;
}

