#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;
#define inf 9000000000000000000

int t,n,k,d,par, bytes[5005];
long long dp[5005][5005], bouri[5005][5005], s[5005];
struct mqueue{
    long long plus=0;
    list<pair<long long,int>> lista;
    void insert(long long val, int pos)
    {
        val -= plus;
		while (!lista.empty() && lista.back().first<=val) lista.pop_back();
        lista.push_back({val,pos});
        plus += bytes[pos-1]*par;
    }
    long long best(int pos)
    {
        while (lista.front().second > pos+d) lista.pop_front();
        return lista.front().first + plus;
    }
    void reset()
    {
        plus = 0;
        lista.clear();
    }
};
mqueue oura;

int main() 
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    for (int i=0; i<t; i++)
    {
        scanf("%d%d%d%d",&n,&k,&d,&par);
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&bytes[i]);
            s[i] = s[i-1]+bytes[i];
        }
        
        // 0 καφέδες‚
        for (int i=1; i<=n; i++)
        {
            dp[i][0] = s[n]-s[i-1];
            bouri[i][0] = (s[min(i+d-1,n)]-s[i-1])*par + s[n]-s[min(i+d-1,n)];
        }
        dp[n+1][0] = bouri[n+1][0] = 0;
        
        // n+1 μέρα
        for (int caf=1; caf<=k; caf++) dp[n+1][caf] = bouri[n+1][caf] = -inf;
        bytes[n+1] = 0;
        
        for (int caf=1; caf<=k; caf++)
        {
            oura.reset();
            for (int i=n; i>0; i--)
            {
                oura.insert(bouri[i+1][caf-1]-bytes[i]*par,i+1);
                dp[i][caf] = max(dp[i+1][caf]+bytes[i], bouri[i+1][caf-1]);
                bouri[i][caf] = oura.best(i);
                if (i+d<=n) bouri[i][caf] = max(bouri[i][caf], par*(s[i+d-1]-s[i-1]) + dp[i+d][caf]);
            }
        }
        printf("%lld\n",dp[1][k]);
    }
	return 0;
}
