#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,target[1000005],ans;
bool meg[1000005];

void fix(int &strofes)
{
	if (strofes<0) strofes += n;
	if (strofes>=n) strofes -= n;
}

int solve()
{
	memset(meg,0,sizeof(meg));
	for (int i=0; i<n; i++)
	{
		int strofes = target[i]-1-i;
		strofes += n/2;
		fix(strofes);
		meg[strofes] = true;
		if (n%2)
		{
			strofes++;
			fix(strofes);
			meg[strofes] = true;
		}
	}
	
	int maxgap=0,prev=0,first;
	while (!meg[prev]) prev++;
	first = prev;
	for (int i=prev+1; i<n; i++)
		if (meg[i])
		{
			maxgap = max(maxgap,i-prev);
			prev = i;
		}
	int gapfl = first-prev;
	fix(gapfl);
	if (gapfl==0) gapfl=n;
	maxgap = max(maxgap,gapfl);
	ans = n/2 - maxgap/2;
}

int main()
{
	scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%d",&target[i]);
	solve();
	int ans1=ans;
	for (int i=0; i<n/2; i++) swap(target[i],target[n-1-i]);
	solve();
	printf("%d\n",min(ans1,ans));
}
