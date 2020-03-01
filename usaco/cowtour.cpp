/*
ID:manolis2
PROG:cowtour
LANG:C++11
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

FILE *fin = fopen("cowtour.in","r"), *fout = fopen("cowtour.out","w");
int n, pos[150][2];
double dist[150][150], biggest[150], fielddiam[150];
vector<vector<int> > components;
vector<int> stin_sinistosa;
bool visited[150];

void floodfill(int komvos)
{
	visited[komvos] = true;
	stin_sinistosa.push_back(komvos);
	for (int i=0; i<n; i++)
		if (dist[komvos][i] != 2000000000 && !visited[i])
			floodfill(i);
}

void finddist()
{
	for (int k=0; k<stin_sinistosa.size(); k++)
		for (int i=0; i<stin_sinistosa.size(); i++)
			for (int j=0; j<stin_sinistosa.size(); j++)
				if (dist[stin_sinistosa[i]][stin_sinistosa[k]] + dist[stin_sinistosa[k]][stin_sinistosa[j]] < dist[stin_sinistosa[i]][stin_sinistosa[j]])
					dist[stin_sinistosa[i]][stin_sinistosa[j]] = dist[stin_sinistosa[i]][stin_sinistosa[k]]+dist[stin_sinistosa[k]][stin_sinistosa[j]];
}

int main()
{	
	fscanf(fin,"%i",&n);
	for (int i=0; i<n; i++)
		fscanf(fin,"%i%i",&pos[i][0],&pos[i][1]);
	char connected;
	for (int i=0; i<n; i++)
	{
		fscanf(fin,"%c",&connected); // reads the newline character
		for (int j=0; j<n; j++)
		{
			fscanf(fin,"%c",&connected);
			if (connected=='1')
				dist[i][j] = sqrt(pow(pos[i][0]-pos[j][0],2) + pow(pos[i][1]-pos[j][1],2));
			else
				dist[i][j] = 2000000000;
		}
	}
			
	int sinistosa=0;
	for (int i=0; i<n; i++)
		if (!visited[i])
		{
			stin_sinistosa.clear();
			floodfill(i);
			finddist();
			components.push_back(stin_sinistosa);
			sinistosa++;
		}
	for (int i=0; i<n; i++)
		dist[i][i] = 0;
		
	for (int component=0; component<components.size(); component++)
		for (int i=0; i<components[component].size(); i++)
		{
			for (int j=0; j<components[component].size(); j++)
				if (dist[components[component][i]] [components[component][j]] > biggest[components[component][i]])
					biggest[components[component][i]] = dist[components[component][i]] [components[component][j]];
			if (biggest[components[component][i]] > fielddiam[component])
				fielddiam[component] = biggest[components[component][i]];
		}			
			
	double mindiam = 2000000000;
	for (int c1=0; c1<components.size(); c1++)
		for (int i=0; i<components[c1].size(); i++)
			for (int c2 = c1 +1; c2<components.size(); c2++)
				for (int j=0; j<components[c2].size(); j++)
					if (mindiam > max(biggest[components[c1][i]] + sqrt(pow(pos[components[c1][i]][0]-pos[components[c2][j]][0],2) + pow(pos[components[c1][i]][1]-pos[components[c2][j]][1],2)) + biggest[components[c2][j]] , max(fielddiam[c1],fielddiam[c2])))
						mindiam = max(biggest[components[c1][i]] + sqrt(pow(pos[components[c1][i]][0]-pos[components[c2][j]][0],2) + pow(pos[components[c1][i]][1]-pos[components[c2][j]][1],2)) + biggest[components[c2][j]] , max(fielddiam[c1],fielddiam[c2]));
	fprintf(fout,"%f\n",mindiam);
	return 0;
}

