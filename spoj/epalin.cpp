#include <cstdio>
#include <cstring>
#define ull unsigned long long
#define b 131

int n;
char s[200005];
ull hsh1[200005], hsh2[200005], p[200005]={1};

bool check(int add)
{
	int len = (n-add)/2;
	int right = add+len+1 + (n-add)%2;
	ull h1 = hsh1[add+len] - hsh1[add]*p[len];
	return h1==hsh2[right];
}

int main()
{
	for (int i=1; i<=200000; i++) p[i] = p[i-1]*b;
	while (scanf("%s",s+1) != EOF)
	{
		n = strlen(s+1);
		hsh1[0] = hsh2[n+1] = 0;
		for (int i=1; i<=n; i++) hsh1[i] = hsh1[i-1]*b + s[i];
		for (int i=n; i>0; i--) hsh2[i] = hsh2[i+1]*b + s[i];
		
		for (int add=0; ; add++)
			if (check(add))
			{
				printf("%s",s+1);
				for (int i=add; i>0; i--) printf("%c",s[i]);
				printf("\n");
				break;
			}
	}
}
