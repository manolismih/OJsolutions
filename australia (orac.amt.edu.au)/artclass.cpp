#include <cstdio>
#include <queue>
#include <cstring>

FILE *fin=fopen("artin.txt","r"), *fout=fopen("artout.txt","w");

int rows,cols,shapes,apantisi, max[1000005][2], min[1000005][2], moves[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char c, pista[1005][1005];

void floodfill(int row, int col)
{
	shapes++;
	max[shapes][0] = min[shapes][0] = row+col;
	max[shapes][1] = min[shapes][1] = cols-col+row;
	pista[row][col] = '.';
	std::queue<std::pair<int,int> > oura;
	oura.push(std::make_pair(row,col));
	while (!oura.empty())
	{
		int &y = oura.front().first, &x=oura.front().second;
		if (x+y < min[shapes][0]) min[shapes][0] = x+y;
		else if (x+y > max[shapes][0]) max[shapes][0] = x+y;
		if (cols-x + y < min[shapes][1]) min[shapes][1] = cols-x + y;
		else if (cols-x + y > max[shapes][1]) max[shapes][1] = cols-x + y;
		for (int i=0; i<4; i++)
			if (pista[y+moves[i][0]][x+moves[i][1]] == 'X')
			{
				oura.push(std::make_pair(y+moves[i][0],x+moves[i][1]));
				pista[y+moves[i][0]][x+moves[i][1]] = '.';
			}		
		oura.pop();
	}
}

int main()
{
	fscanf(fin,"%i%i",&rows,&cols);
	for (int y=1; y<=rows; y++)
		fscanf(fin," %s",pista[y]+1);
	
	for (int y=1; y<=rows; y++)
		for (int x=1; x<=cols; x++)
			if (pista[y][x]=='X') floodfill(y,x);					

	for (int i=1; i<=shapes; i++)
		for (int j=0; j<2; j++)
			if (max[i][j]-min[i][j] > apantisi) apantisi = max[i][j]-min[i][j];
	fprintf(fout,"%i\n",apantisi);
	return 0;
}

