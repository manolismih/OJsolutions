#include <cstdio>
#include <cstring>

int t, n;
char word[1000005], half1[1000005], half2[1000005];

bool check(int i1, int i2, int drop, char* storage)
{
	int count=0;
	while (count<n/2)
	{
		if (word[i1] == word[i2])
		{
			storage[count++]=word[i1];
			i1++, i2++;
		}
		else if (drop==0) return false;
		else if (drop==-1) i1++, drop=0;
		else i2++, drop=0;
	}
	return true;
}

int main()
{
	freopen("symstr.in","r",stdin);
	freopen("symstr.out","w",stdout);
	scanf("%d%d",&t,&n);
	while (t--)
	{
		scanf("%s",word);
		bool res1 = check(0,n/2,1,half1);
		bool res2 = check(0,n/2+1,-1,half2);
		if (res1 && res2)
			if (strcmp(half1,half2)==0) printf("%s\n",half1);
			else printf("1\n");
		else if (res1) printf("%s\n",half1);
		else if (res2) printf("%s\n",half2);
		else printf("0\n"); 
	}
}
