#include <cstdio>

int affect[9][6]={	{3,0,1,3},//A
					{4,0,1,2,4},//B
					{3,1,2,5},//C
					{4,0,3,4,6},//D
					{5,0,2,4,6,8},//E
					{4,2,4,5,8},//F
					{3,3,6,7},//G
					{4,4,6,7,8},//H
					{3,5,7,8}};//I
int init[9];
unsigned int ans=0, nMoves=200;

int extractKthButton(unsigned int buttons, int k) {	
	return (buttons & 3<<2*k) >> 2*k;
}

int countMoves(unsigned int buttons) {
	return __builtin_popcount(buttons&0x15555) //01 01 01 01 01 01 01 01 01
	   + 2*__builtin_popcount(buttons&0x2aaaa);//10 10 10 10 10 10 10 10 10
}

bool valid(unsigned int buttons)
{
	for (int clock=0; clock<9; clock++)
	{
		int switched=0;
		for (int move=1; move<=affect[clock][0]; move++)
			switched += extractKthButton(buttons,affect[clock][move]);
		if ((switched+init[clock])%4 !=0) return false;
	}
	return true;
}

int main()
{
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);
	for (int i=0; i<9; i++) scanf("%d",&init[i]);
	
	for (unsigned int buttons=0; buttons<262144; buttons++)
		if (valid(buttons) && countMoves(buttons)<nMoves)
		{
			ans = buttons;
			nMoves = countMoves(buttons);
		}
		
	for (int i=0; i<9; i++)
	{
		int fores = extractKthButton(ans,i);
		for (int j=0; j<fores; j++) printf("%d ",i+1); 
	}
}
