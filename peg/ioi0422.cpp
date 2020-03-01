#include <cstdio>
#include <algorithm>

int n,k,sumk,a, count[155], strips[2005], rem[150005]; 
bool make[150005]={1};

int main()
{
	scanf("%d%d%d",&n,&k,&a);
	for (int num,i=0; i<k; i++)
	{
		scanf("%d",&num);
		sumk += num;
		count[num]++;
	}
	if (n >= sumk)
	{
		int apantisi = n, i = a-1;
		n -= sumk;
		for (int i=0; i<a; i++)
			scanf("%d",&strips[i]);
		std::sort(strips,strips+a);
		while (n > 0)
		{
			n -= strips[i--];
			apantisi--;
		}
		printf("%d\n",apantisi);
		return 0;
	}
	rem[0]=count[3];
	for (int i=3; i<=150; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (make[j] && rem[j] && !make[j+i]) make[j+i] = 1, rem[j+i] = rem[j]-1;
			rem[j] = count[i+1];
		}
		if (make[n])
		{
			printf("%d\n",n);
			return 0;
		}
	}
	printf("%d\n",n-1);
	return 0;
}

