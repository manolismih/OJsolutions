#include <cstdio>

int n,m, people[5005], seats[5005];

int main()
{
	freopen("restin.txt","r",stdin);
	freopen("restout.txt","w",stdout);
	scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%d",&people[i]);
	scanf("%d",&m);
	for (int i=0; i<m; i++) scanf("%d",&seats[i]);
	
	int ans=0;
	for (int i=0; i<n; i++)
	{
		for (int j=0; people[i] && j<m; j++)
			if (seats[j]) seats[j]--, people[i]--;
		ans += people[i];
	}
	printf("%d\n",ans);	
	return 0;
}

