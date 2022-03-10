#include <cstdio>
#include <algorithm>
#define inf 2e9

int T, N, num[100005];
int dp[100005][2][2][2][4][4][4];
//dp[i][used c][used r][is complmented][left][mid][right]
/* mid=0 : no elements in middle
 * mid=1 : the smaller from the two that are missing (ie not left or right)
 * mid=2 : the greatest 
 * mid=3 : both missing numbers are present in middle
 */

int main()
{
	//~ freopen("pcr.in","r",stdin);
	//~ freopen("pcr.out","w",stdout);
	scanf("%d%d",&T,&N);
	while (T--)
	{
		for (int i=0; i<N; i++) scanf("%d",&num[i]);
		
		for (int i=N-1; i>0; i--)
			for (int c=1; c>=0; c--)
				for (int r=1; r>=0; r--)
					for (int complemented=0; complemented<2; complemented++)
						for (int left=0; left<4; left++)
							for (int mid=0; mid<4; mid++)
								for (int right=0; right<4; right++)
								{									
									int do_c = c ? inf : 1+dp[i][1][r][!complemented][left][mid][right];
									int do_r = r ? inf : 1+dp[i][c][1][complemented][right][mid][left];
									int do_p = inf;
									int element = complemented ? 3-num[i] : num[i];
									int other = 6-left-right-element; //0+1+2+3 = 6
									
									/* To find if element exists in middle: suppose mid>0
									 * other>element gives 0 or 1 => adding 1 gives 1 or 2.
									 * No way to get 3 => if mid==3 then the element exists in middle
									 * and the boolen expression gives 0.
									 * If other>element, then mid should be 2 (so that other and not element
									 * is present in the middle. If not, then mid should be 1.
									 */
									if (element==right || element!=left && (mid==0||(other>element)+1==mid) )
									{
										int newmid = mid;
                    if (element!=right && left!=right)
                      newmid = mid==0 ? mid+1+(right>other) : 3;
										do_p = 1+dp[i+1][0][0][complemented][left][newmid][element];
									}									
									dp[i][c][r][complemented][left][mid][right] = std::min({do_c,do_r,do_p});
								}

		int i=1,c=0,r=0,complemented=0,left=num[0],mid=0,right=num[0];
		putchar('p');
		while (i<N)
		{
			int best = dp[i][c][r][complemented][left][mid][right];
			int element = complemented ? 3-num[i] : num[i];
			int other = 6-left-right-element;
			char move=0;
			
			if (!c && best==1+dp[i][1][r][!complemented][left][mid][right])
				move='c', c=1, complemented = !complemented;
			else if (element==right || element!=left && (mid==0||(other>element)+1==mid) )
      {
        int newmid = mid;
        if (element!=right && left!=right)
          newmid = mid==0 ? mid+1+(right>other) : 3;
        if (best==1+dp[i+1][0][0][complemented][left][newmid][element])
          move='p', c=r=0, mid=newmid, right=element, i++;
			}
			if (move==0) {
				move='r', r=1;
				std::swap(left,right); 
			}
			putchar(move);
		}
		putchar('\n');
	}
  return 0;
}
