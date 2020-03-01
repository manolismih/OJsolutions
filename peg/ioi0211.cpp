#include <cstdio>
#include <algorithm>
#include <bitset>

#define x first
#define y second

int rows,cols,n,ans;
std::pair<int,int> pos[5005], next;
std::bitset<5005> dp[5005];

int main()
{
	scanf("%d%d%d",&rows,&cols,&n);
	for (int i=0; i<n; i++) scanf("%d%d",&pos[i].y,&pos[i].x);
	std::sort(pos,pos+n);
	for (int a=n-1; a>=0; a--)
	{
		int c=a;
		for (int b=a+1; b<n; b++)
		{
			int ydiff = pos[b].y-pos[a].y;
			int xdiff = pos[b].x-pos[a].x;
			next.y = pos[b].y + ydiff;
			next.x = pos[b].x + xdiff;
			if (next.y<1 || next.y>rows || next.x>cols)
			{
				dp[a][b] = 1;
				continue;
			}
			while (c<n && pos[c] < next) c++;
			if (pos[c]==next && dp[b][c])
			{
				dp[a][b] = 1;
				if (pos[a].x-xdiff > 0 && pos[a].y-ydiff > 0 && pos[a].y-ydiff <= rows) continue;
				int xbound = (xdiff ? 1+ (cols-pos[a].x)/xdiff : 5005);
				int ybound;
				if (ydiff>0) ybound = 1+ (rows-pos[a].y)/ydiff;
				else if (ydiff<0) ybound = 1+ (1-pos[a].y)/ydiff;
				else ybound = 5005;
				ans = std::max(ans, std::min(xbound,ybound));
			}
		}
	}
	printf("%d\n",ans);
}
