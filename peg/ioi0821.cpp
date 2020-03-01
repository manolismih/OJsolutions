#include <cstdio> 

int n,m,apantisi=1,arxizei,next,prev;
int memo[1000005][2][3][2]; // memo[mikos][arxizei apo][epomemno diplo][to proigoumeno htan]
// l,ll = 0; P,PP = 1; XX = 2;

int main()
{
	char c;
	scanf("%i%i%c",&n,&m,&c);
	if (n==1)
	{
		scanf("%c",&c);
		printf("%i\n",c=='L'?1:2);
		return 0;
	}
	for (arxizei=0; arxizei<2; arxizei++)
		for (next=0; next<3; next++)
			for (prev=0; prev<2; prev++)
				if (arxizei==prev)
					if (arxizei==next)
						memo[1][arxizei][next][prev] = 1;
					else; // else me ; simainei oti den kanei tipota epeidi einai idi initialized me 0
				else
					if (next==2)
						memo[1][arxizei][next][prev] = 1;

	for (int i=2; i<n; i++)
		for (arxizei=0; arxizei<2; arxizei++)
			for (next=0; next<3; next++)
				for (prev=0; prev<2; prev++)
					if (arxizei==prev)
						if (arxizei==next)
							memo[i][arxizei][next][prev] = (memo[i-1][arxizei==0 ? 1 : 0][next==0 ? 1 : 0][arxizei] + memo[i-1][arxizei==0 ? 1 : 0][2][arxizei]) % m;
						else;
					else
						memo[i][arxizei][next][prev] = (memo[i-1][0][next][arxizei] + memo[i-1][1][next][arxizei]) % m;
						
	int me_n = 0;
	arxizei = 0;
	for (next=0; next<3; next++)
		for (prev=0; prev<2; prev++)
			me_n += memo[n-1][arxizei][next][prev];
	me_n %= m;
	
	char cprev;
	int no=3; //den apokleioume kanena me to no gia arxi
	scanf("%c",&c);
	if (c=='P') apantisi += me_n;
	for (int i=n-1; i>0; i--)
	{
		if (cprev==c)
		{
			cprev = c;
			scanf("%c",&c);
			continue;
		}
		cprev = c;
		scanf("%c",&c);
		if (c=='P')
		{
			if (no!=0)
				apantisi += memo[i][0][0][cprev=='L'?0:1];
			if (no!=1)
				apantisi += memo[i][0][1][cprev=='L'?0:1];
			apantisi += memo[i][0][2][cprev=='L'?0:1];
			apantisi %= m;
		}
		if (c==cprev)
			no = c=='L'?0:1;	
	}
	printf("%i\n",apantisi);
	return 0;
}

