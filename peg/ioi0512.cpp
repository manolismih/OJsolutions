#include <cstdio>
#include <cstdlib>

int n, init, new1, new2, maxchange = 2100000000;
void print0() {	printf("0\n"); exit(0);}

int main()
{
	scanf("%d%d",&n,&init);
	new1 = new2 = init;
	for (int i=2; i<=n; i++)
	{
		scanf("%d",&init);
		new1 = new2;
		new2 = init+init-new1;
		if (i%2) // ����������
			if (new1 > init) // ��� ������ �� �������
				if (new1-init > maxchange) print0();
				else maxchange -= new1-init, new1 = new2 = init;
			else;
		else /*���������*/ if (new1 > init) print0(); //��� ����� ��� ������
		else if (init-new1 < maxchange) maxchange = init-new1;
	}
	printf("%d\n",maxchange+1);
}
