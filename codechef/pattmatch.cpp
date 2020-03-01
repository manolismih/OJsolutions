#include <cstdio>
#include <cstring>
#define p 131
#define ull unsigned long long

int t,n,m, nwords;
ull hsh[505], power[100005];
int len[505], emf[505];
char s[100005], wild[100005];

void findwords()
{
	int i;
	for (nwords=0, i=0; i<m; nwords++)
	{
		while (i<m && wild[i]=='*') i++;
		while (i<m && wild[i]!='*')
		{
			len[nwords]++;
			hsh[nwords] *= p;
			hsh[nwords] += wild[i];
			i++;
		}
	}
	if (wild[m-1]=='*') nwords--;
}

bool adv(int word, int i)
{
	if (i+len[word]>n) return false;
	ull temp=0, pow = power[len[word]-1];
	int stop = i+len[word];
	for (; i<stop; i++)
	{
		temp *= p;
		temp += s[i];
	}
	if (temp==hsh[word])
	{
		emf[word]=i-len[word];
		return true;
	}
	for (; i<n; i++)
	{
		temp -= s[i-len[word]]*pow;
		temp *= p;
		temp += s[i];
		if (temp == hsh[word])
		{
			emf[word] = i-len[word]+1;
			return true;
		}
	}
	return false;
}

int main()
{
	//freopen("in.txt","r",stdin);
	power[0]=1;
	for (int i=1; i<100005; i++) power[i] = power[i-1]*p;
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%s%s",wild,s);
		n = strlen(s);
		m = strlen(wild);
		bool stop = false;
		memset(hsh,0,505*8);
		memset(len,0,505*4);
		memset(emf,0,505*4);
		findwords();
		
		if (nwords==0)
		{
			for (int i=1; i<=n; i++) printf("%d ",i);
			printf("\n");
			continue;
		}
		
		stop = !adv(0,0);
		for (int i=1; !stop && i<nwords; i++)
			stop = !adv(i,emf[i-1]+len[i-1]);
		
		for (int i=0; i<n; i++)
			if (stop) printf("-1 ");
			else if (emf[0]>=i) printf("%d ",emf[nwords-1]+len[nwords-1]);
			else 
			{
				stop = !adv(0,i);
				for (int j=1; !stop && j<nwords && emf[j]<emf[j-1]+len[j-1]; j++)
					stop = !adv(j,emf[j-1]+len[j-1]);
				if (stop) printf("-1 ");
				else printf("%d ",emf[nwords-1]+len[nwords-1]);
			}
		printf("\n");
	}
	return 0;
}

