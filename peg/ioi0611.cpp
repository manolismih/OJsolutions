#include <cstdio>

int m,n, source[256], target[256], vlakeies, apantisi;
char c, s[3000005];

int main()
{
	scanf("%d%d",&m,&n);
	for (int i=0; i<m; i++)
	{
		scanf(" %c",&c);
		target[c]++;
	}
	for (int i=0; i<m; i++)
	{
		scanf(" %c",&s[i]);
		if (++source[s[i]] > target[s[i]]) vlakeies++;
	}
	if (!vlakeies) apantisi++;
	for (int i=m; i<n; i++)
	{
		if (--source[s[i-m]] >= target[s[i-m]]) vlakeies--;
		scanf("%c",&s[i]);
		if (++source[s[i]] > target[s[i]]) vlakeies++;
		if (!vlakeies) apantisi++;
	}
	printf("%d\n",apantisi);
	return 0;
}

