#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,low,high, ans, seq[15], t,emf[1000];
bool print;

void check()
{
	t++;
	int sum;
	for (int i=0; i<n; i++) seq[i+n] = seq[i];
	for (int len=1; len<n; len++)
	{
		sum=0;
		for (int i=0; i<len-1; i++) sum+=seq[i];
		for (int i=0; i<n; i++)
		{
			sum += seq[i+len-1];
			emf[sum] = t;
			sum -= seq[i];
		}
	}
	sum=0;
	for (int i=0; i<n; i++) sum+=seq[i];
	emf[sum]=t;
	
	int last;
	for (last=m; emf[last]==t; last++);
	last--;
	
	if (print && last==ans)
	{
		for (int i=0; i<n; i++) printf("%d ",seq[i]);
		printf("\n");
	}
	else ans=max(ans,last);
}

int lim(int digit)
{
	int sum, rem = (n-digit-1)*(n-1) + 1;
	digit--, t++;
	for (int len=1; len<=digit; len++)
	{
		sum=0;
		for (int i=0; i<len-1; i++) sum+=seq[i];
		for (int i=0; i<n; i++)
		{
			sum += seq[i+len-1];
			emf[sum] = t;
			sum -= seq[i];
		}
	}
	int i;
	for (i=m; rem && i<=high; i++)
		if (emf[i] != t) rem--;
	while (emf[i]==t) i++;
	return i;
}

void dfs(int digit)
{
	int stop=lim(digit);
	for (seq[digit]=(digit ? seq[0] : low); seq[digit]<=stop; seq[digit]++)
		if (digit==n-1) check();
		else dfs(digit+1);
}

int main()
{
	scanf("%d%d%d",&n,&m,&low);
	high = m + (n-1)*n + 1;
	dfs(0);
	printf("%d\n",ans);
	print = true;
	dfs(0);
}
