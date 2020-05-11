#include <cstdio>
#include <cstring>
#include <algorithm>

int N, len[1000], minR, minC;
char name[1000][50];

bool compare(int r1, int c1, int r2, int c2)
{
	int res=strncmp(&name[r1][c1], &name[r2][c2], std::min(len[r1],len[r2]));
	if (res!=0) return res<0;
	else return len[r1]<len[r2];
}

int main()
{
	freopen("names.in","r",stdin);
	freopen("names.out","w",stdout);
	scanf("%d",&N);
	for (int i=0; i<N; i++)
	{
		scanf("%s",name[i]);
		len[i] = strlen(name[i]);
		strncat(name[i],name[i],len[i]);
	}
	for (int row=0; row<N; row++)
		for (int col=0; col<len[row]; col++)
			if (compare(row,col,minR,minC))
				minR=row, minC=col;
	name[minR][len[minR]] = 0;
	printf("%s\n",name[minR]);
}
