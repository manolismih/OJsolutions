#include <cstdio>
#include <cstring>

int n,m;
char hay[100000000], needle[100000000];
unsigned long long target, source, pow;

int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf("%d%s%s",&m,needle,hay) && !feof(stdin))
	{
		n = strlen(hay);
		if (m>n)
		{
			printf("\n");
			continue;
		}
		pow = 1;
		target = source = 0;
		for (int i=1; i<m; i++) pow *= 131;
		for (int i=0; i<m; i++)
		{
			source = source*131 + hay[i];
			target = target*131 + needle[i];
		}
		if (source==target) printf("0\n");
		for (int i=m; i<n; i++)
		{
			source -= hay[i-m]*pow;
			source = source*131 + hay[i];
			if (source==target) printf("%d\n",i-m+1);
		}
		printf("\n");
	}
	return 0;
}

