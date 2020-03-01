#include <cstdio>
#include <cmath>
#include <list>

int n;
double p[15], dp[10000][15][15];
bool memo[10000][15];

void add(double *dest, double factor, double *val)
{
	for (int i=0; i<n; i++) dest[i] += factor*val[i];
}

int all()
{
	int ret=pow(2,n)-1;
	return ret;
}

int fnext(int state, int i)
{
	for (int j=(i+1)%n; j!=i; j=(j+1)%n)
		if (state & 1<<j) return j;
}

bool eq(double a, double b)
{
	return std::abs(a-b)<1e-9;
}

double *surv(int state, int shooter);
std::list<int> ftarget(int state, int shooter)
{
	std::list<int> ret;
	int next = fnext(state,shooter);
	int next2 = fnext(state,next);
	ret.push_back(next);
	double chance = surv(state-(1<<next),next2)[shooter];
	
	for (int i=next2; i!=shooter; i=fnext(state,i))
		if ( eq(surv(state-(1<<i),next)[shooter], chance) )
			ret.push_back(i);
		else if (surv(state-(1<<i),next)[shooter] > chance)
		{
			chance = surv(state-(1<<i),next)[shooter];
			ret.clear();
			ret.push_back(i);
		}
	return ret;
}

double *surv(int state, int shooter)
{
	if (memo[state][shooter]) return dp[state][shooter];
	memo[state][shooter] = true;
	if (__builtin_popcount(state)==1)
	{
		dp[state][shooter][shooter] = 1.0;
		return dp[state][shooter];
	}
	
	double factor=1.0;
	int i=shooter, next, nextshooter;
	do
	{
		std::list<int> target = ftarget(state,i);
		next = fnext(state,i);
		for (std::list<int>::iterator it=target.begin(); it!=target.end(); it++)
		{
			if (next != *it) nextshooter = next;
			else nextshooter = fnext(state,next);
			add(dp[state][shooter],factor*p[i]/target.size(),surv(state-(1<<*it),nextshooter));
		}
		factor *= (1-p[i]);
		i = next;
	}
	while (i!=shooter);
	
	factor = 1-factor;
	for (int i=0; i<n; i++) dp[state][shooter][i] /= factor;
	return dp[state][shooter];
}

int main()
{
	freopen("shootout.in","r",stdin);
	freopen("shootout.out","w",stdout);
	scanf("%d",&n);
	for (int i=0; i<n; i++)
	{
		scanf("%lf",&p[i]);
		p[i] /= 100;
	}
	double *ans = surv(all(),0);
	for (int i=0; i<n; i++) printf("%.2lf\n",ans[i]*100);
}
