#include <cstdio>
#include <algorithm>

int N, M, K, comb[10][5], correct[10], wrong[10];
int tested[5], ans=0;

bool check_comb(int c)
{
	int cor=0, wro=0, emf[10]={0};
	for (int i=0; i<K; i++)
		if (tested[i]==comb[c][i]) cor++;
		else emf[tested[i]]++;
	
	for (int i=0; i<K; i++)
		if (tested[i]!=comb[c][i] && emf[comb[c][i]]>0)
		{
			emf[comb[c][i]]--;
			wro++;
		}
	return cor==correct[c] && wro==wrong[c];
}

int check_tested()
{
	for (int i=0; i<N; i++)
		if (!check_comb(i)) return 0;
	return 1;
}

int main()
{
	freopen("mastermind.in","r",stdin);
	freopen("mastermind.out","w",stdout);
	scanf("%d%d%d",&N,&M,&K);
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<K; j++)
		{ 	
			scanf("%d",&comb[i][j]);
			comb[i][j]--;
		}
		scanf("%d%d",&correct[i],&wrong[i]);
	}
	
	int stop3 = K>3 ? M : 1; 
	int stop4 = K>4 ? M : 1; 
	for (tested[0]=0; tested[0]<M; tested[0]++)
		for (tested[1]=0; tested[1]<M; tested[1]++)
			for (tested[2]=0; tested[2]<M; tested[2]++)
				for (tested[3]=0; tested[3]<stop3; tested[3]++)
					for (tested[4]=0; tested[4]<stop4; tested[4]++)
						ans += check_tested();
	printf("%d",ans);
}
