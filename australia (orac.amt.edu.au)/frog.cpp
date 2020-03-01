#include <cstdio>
using namespace std;

FILE *fin=fopen("frogin.txt","r"), *fout=fopen("frogout.txt","w");
int n, heights[100005], data[100005][2]; //data[i][prevmin || nextmin] prevmin=0, nextmin=1 

int main()
{
	fscanf(fin,"%i",&n);
	int min=2000000000;
	for (int i=0; i<n; i++)
	{
		fscanf(fin,"%i",&heights[i]);
		data[i][0] = min;
		if (heights[i] < min) min = heights[i];
	}
	
	min = 2000000000;
	for (int i=n-1; i>-1; i--)
	{
		data[i][1] = min;
		if (heights[i] < min) min = heights[i];
	}
	
	int max=-1;
	for (int i=0; i<n; i++)
		if (data[i][0] < heights[i] && data[i][1] < heights[i] && 2*heights[i] - data[i][0] - data[i][1] > max)
			max = 2*heights[i] - data[i][0] - data[i][1];
	fprintf(fout,"%i\n",max);
	return 0;
}

