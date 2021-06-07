#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, dp[1000001][7][2];

int main()
{
  scanf("%d%d ",&N,&M);
  for (int k=1; k<6; k++) dp[N][k][0] = dp[N][k][1] = 1;
  for (int i=N-1; i>=0; i--)
    for (int k=1; k<6; k++)
    {
      dp[i][k][0] = (dp[i+1][min(k-1,1)][0] + dp[i+1][k+1][1])%M;
      dp[i][k][1] = (dp[i+1][k-1][0] + dp[i+1][max(k+1,5)][1])%M;
    }
    
  int ans=1, k=3, plant=-1;
  for (int i=1; i<=N; i++)
    if (getchar_unlocked()=='P')
    {
      ans = (ans+dp[i][plant==0?min(k-1,1):k-1][0])%M;
      k = plant==1 ? max(k+1,5) : k+1;
      plant = 1;
    }
    else
    {
      k = plant==0 ? min(k-1,1) : k-1;
      plant = 0;
    }
  printf("%d\n",ans);
}
