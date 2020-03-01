/*
ID:manolis2
PROG:
LANG:C++
*/

#include <cstdio>
#include <algorithm>
#include <list>

using namespace std;

int n, mindelete=0, data[3][100000], helparn[3][1000001];
list<int> helparl[3][1000001], problem;
bool deleted[100001]={0}, problembool[100001]={0};

int main()
{
	FILE *input = fopen("physics.in","r");
	FILE *output = fopen("physics.out","w");
	fscanf(input,"%i",&n);
	for (int i=0; i<3; i++)
		for (int j=0; j<n; j++)
		{
			fscanf(input,"%i",&data[i][j]);
			helparl[i][data[i][j]].push_back(j);
		}
	for (int i=0; i<3; i++)
		for (int j=1; j<=n; j++)
		{
			helparn[i][j]=helparl[i][j].size();
			if ((helparn[i][j]==0) && (!problembool[j]))
			{
				problem.push_back(j);
				problembool[j]=true;
			}
								
		}
	
	list<int>::iterator it;
	while (!problem.empty())
	{
		printf("%i\n",problem.front());
		for (int i=0; i<3; i++)
			for (it=helparl[i][problem.front()].begin(); it!=helparl[i][problem.front()].end(); it++)
				if (!deleted[*it])
				{
					deleted[*it]=true;
					for (int j=0; j<3; j++)
					{
						helparn[j][data[j][*it]]--;
						if ((helparn[j][data[j][*it]] == 0) && (!problembool[data[j][*it]]))
						{
							problem.push_back(data[j][*it]);
							problembool[data[j][*it]]=true;
						}
						
					}
				}
		problem.pop_front();				
	}	
	
	for (int i=0; i<n; i++)
		if (deleted[i])
			mindelete++;
	fprintf(output,"%i\n",mindelete);
	return 0;
}

