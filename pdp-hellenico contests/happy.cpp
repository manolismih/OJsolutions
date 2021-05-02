#include <cstdio>

int Q, bucket[100005], emf[325];
int happy[730]={0,1}; //0 false, 1 true, -1 not examined yet

int digit2sum(int x)
{
  int ans=0;
  while (x)
  {
    ans+=(x%10)*(x%10);
    x/=10;
  }
  return ans;
}

int dfs(int x)
{
  if (happy[x]!=-1) return happy[x];
  happy[x]=0;
  return happy[x] = dfs(digit2sum(x));
}

int main()
{
  for (int num=2; num<730; num++) happy[num]=-1;
  for (int num=2; num<730; num++) dfs(num);
  for (int num=0; num<10000; num++) emf[digit2sum(num)]++;
  for (int kouvas=0; kouvas<100000; kouvas++)
  {
    int extra = digit2sum(kouvas);
    for (int sum=0; sum<325; sum++)
      bucket[kouvas] += happy[sum+extra]*emf[sum];
  }

  scanf("%d",&Q);
  for (int from,to, i=0; i<Q; i++)
  {
    scanf("%d%d",&from,&to);
    const int bucketFrom = (from-1)/10000 +1;
    const int bucketTo = (to+1)/10000 -1;
    int ans=0;
    for (int kouvas=bucketFrom; kouvas<=bucketTo; kouvas++) ans+=bucket[kouvas];
    if (ans==0)
      for (int num=from; num<=to; num++) ans += happy[digit2sum(num)];
    else
    {
      for (int num=from; num<bucketFrom*10000; num++) ans += happy[digit2sum(num)];
      for (int num=(bucketTo+1)*10000; num<=to; num++) ans += happy[digit2sum(num)];
    }
    printf("%d\n",ans);
  }
}
