#include <cstdio>
#include <cstring>
#include <algorithm>

int N, C, on[3], off[3], nOn=-1, nOff=-1, nAns;
char ans[16][105];
int order[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

void swap(char* c) {	*c= *c=='0'?'1':'0' 	;}
bool compare(int a, int b) {	return strcmp(&ans[a][1],&ans[b][1])<0	;}

int main()
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	scanf("%d%d",&N,&C);
	
	do {
		nOn++;
		scanf("%d",&on[nOn]);
	} while (on[nOn] != -1);
	do {
		nOff++;
		scanf("%d",&off[nOff]);
	} while (off[nOff] != -1);
	
	//check every button pressing combination
	for (unsigned int buttons=0; buttons<16; buttons++)
	{
		int bits = __builtin_popcount(buttons);
		if (bits>C || (C-bits)%2==1) continue;
		
		char* solution = ans[nAns];
		if (buttons&8) 	memset(&solution[1],'0',N);
		else 			memset(&solution[1],'1',N);
		if (buttons&4) 
			for (int i=1; i<=N; i+=2) swap(&solution[i]);
		if (buttons&2)
			for (int i=0; i<=N; i+=2) swap(&solution[i]);
		if (buttons&1)
			for (int i=1; i<=N; i+=3) swap(&solution[i]);
		
		if (nOn>0 && solution[on[0]]=='0') continue;
		if (nOn>1 && solution[on[1]]=='0') continue;
		if (nOff>0 && solution[off[0]]=='1') continue;
		if (nOff>1 && solution[off[1]]=='1') continue;
		
		nAns++;
	}
	std::sort(order,order+nAns,compare);
	for (int i=0; i<nAns; i++) printf("%s\n",&ans[order[i]][1]);
}
