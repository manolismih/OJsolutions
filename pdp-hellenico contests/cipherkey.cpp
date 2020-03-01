#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1000005],curr[2000005];
int n,m,nol, z[1000005], z2[1000005], ans;

int main()
{
	scanf("%s%s",s,curr);
	n = strlen(s);
	m = strlen(curr);
	curr[m]='#';
	strcpy(curr+m+1,s);
	nol = n+m+1;
	curr[nol]='#';
	
	int l=0, r=0;
	for (int i=1; i<nol; i++)
	{
		z[i]=0;
		if (i<=r) z[i]=min(z[i-l], r-i+1);
		while (curr[z[i]] == curr[i+z[i]]) z[i]++;
		if (i+z[i] > r)
		{
			l = i;
			r = i+z[i]-1;
		}
	}
	reverse(curr,curr+m);
	reverse(curr+m+1,curr+nol);
	l=0, r=0;
	for (int i=1; i<nol; i++)
	{
		z2[i]=0;
		if (i<=r) z2[i]=min(z2[i-l], r-i+1);
		while (curr[z2[i]] == curr[i+z2[i]]) z2[i]++;
		if (i+z2[i] > r)
		{
			l = i;
			r = i+z2[i]-1;
		}
	}
	
	reverse(z2+m+1,z2+nol);
	for (int i=m+1; i<n+2; i++)
		if (z[i] + z2[i+m-1] >= m-1)
			ans++;
	printf("%d\n",ans);
	return 0;
}
