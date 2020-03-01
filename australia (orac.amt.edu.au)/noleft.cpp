#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define x first
#define y second

struct stili{	int x,ymin,ymax;};
vector<stili> col;
pair<int,int> spot[100005];
int n,dp[2][2]; //dp[2][0=low, 1=high]

int main()
{
	freopen("leftin.txt","r",stdin);
	freopen("leftout.txt","w",stdout);
	scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%d%d",&spot[i].x,&spot[i].y);
	sort(spot,spot+n);
	for (int j,i=0; i<n;)
	{
		for (j=i+1; j<n && spot[j].x==spot[i].x; j++);
		j--;
		col.push_back({spot[i].x,spot[i].y,spot[j].y});
		i = j+1;
	}
	n = col.size();
	dp[(n-1)%2][0] = dp[(n-1)%2][1] = 0;
	for (int i=n-2; i>=0; i--)
	{
		int platos = col[i+1].ymax-col[i+1].ymin, mikos = col[i+1].x-col[i].x;
		dp[i%2][0] = min(abs(col[i].ymin-col[i+1].ymax)+platos+dp[(i+1)%2][0],
		abs(col[i].ymin-col[i+1].ymin)+platos+dp[(i+1)%2][1]) + mikos;
		dp[i%2][1] = min(abs(col[i].ymax-col[i+1].ymax)+platos+dp[(i+1)%2][0],
		abs(col[i].ymax-col[i+1].ymin)+platos+dp[(i+1)%2][1]) + mikos;
	}
	int platos = col[0].ymax - col[0].ymin;
	printf("%d\n",min(dp[0][0],dp[0][1])+platos);
	return 0;
}

