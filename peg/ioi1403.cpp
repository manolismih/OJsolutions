#include <cstdio>
#include <cmath>

int n,x,y;

void solve(int x1, int y1, int x2, int y2, int x, int y)
{
	if (x1==x2) return;
	int xmid = (x1+x2)/2, ymid = (y1+y2)/2, pos=0;
	char s[600];
	
	if (x<=xmid && y<=ymid) solve(x1,y1,xmid,ymid,x,y);
	else
	{
		 solve(x1,y1,xmid,ymid,xmid,ymid);
		 pos += sprintf(s+pos,"%d %d ",xmid,ymid);
	}
	if (x<=xmid && y>ymid) solve(x1,ymid+1,xmid,y2,x,y);
	else
	{
		solve(x1,ymid+1,xmid,y2,xmid,ymid+1);
		pos += sprintf(s+pos,"%d %d ",xmid,ymid+1);
	}
	if (x>xmid && y<=ymid) solve(xmid+1,y1,x2,ymid,x,y);
	else
	{
		solve(xmid+1,y1,x2,ymid,xmid+1,ymid);
		pos += sprintf(s+pos,"%d %d ",xmid+1,ymid);
	}
	if (x>xmid && y>ymid) solve(xmid+1,ymid+1,x2,y2,x,y);
	else
	{
		solve(xmid+1,ymid+1,x2,y2,xmid+1,ymid+1);
		sprintf(s+pos,"%d %d",xmid+1,ymid+1);
	}
	printf("%s\n",s);
}

int main()
{
	scanf("%d%d%d",&n,&x,&y);
	n = exp2(n);
	solve(0,0,n-1,n-1,x,y);
}
