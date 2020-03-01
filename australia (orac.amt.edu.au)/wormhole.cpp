#include <cstdio>
#include <algorithm>

FILE *fin=fopen("wormin.txt","r"), *fout=fopen("wormout.txt","w");
int r, c, q, rows[305], cols[305], sol_rows, sol_cols; 
char pista[305][305];

int apantisi()
{
	if (sol_rows==r) 
		if (!sol_cols && c==2) return 2;
		else return !sol_cols;
	if (sol_cols==c) 
		if (!sol_rows && r==2) return 2;
		else return !sol_rows;	
	return std::min(r-sol_rows,c-sol_cols);
}

int main()
{
	fscanf(fin,"%i%i%i",&r,&c,&q);
	for (int y=1; y<=r; y++)
	{
		for (int x=1; x<=c; x++)
		{
			fscanf(fin," %c",&pista[y][x]);
			if (pista[y][x] == 'B') ++rows[y], ++cols[x];
		}
		if (rows[y]<c && rows[y]>0) sol_rows++;
	}
	for (int x=1; x<=c; x++)
		if (cols[x]>0 && cols[x]<r) sol_cols++;
		
	if (r==1) sol_cols=c;
	if (c==1) sol_rows=r;
				
	fprintf(fout,"%i\n",apantisi());
	int y, x;
	for (int i=0; i<q; i++)
	{
		fscanf(fin,"%i%i",&y,&x);
		if (pista[y][x] == 'O')
		{
			pista[y][x] = 'B';
			if (++rows[y]==1 && c>1) sol_rows++;
			else if (rows[y]==c && c>1) sol_rows--;
			if (++cols[x]==1 && r>1) sol_cols++;
			else if (cols[x]==r && r>1) sol_cols--;
		}
		else
		{
			pista[y][x] = 'O';
			if (!--rows[y] && c>1) sol_rows--;
			else if (rows[y]==c-1 && c>1) sol_rows++;
			if (!--cols[x] && r>1) sol_cols--;
			else if (cols[x]==r-1 && r>1) sol_cols++;
		}
		fprintf(fout,"%i\n",apantisi());
	}
	return 0;
}
