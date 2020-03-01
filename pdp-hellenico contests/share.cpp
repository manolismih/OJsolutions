#include <cstdio>
#include <algorithm>
using namespace std;

int n,num,s[1000005];

int main()
{
	freopen("share.in","r",stdin);
	freopen("share.out","w",stdout);
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&s[i]);
		s[i] += s[i-1]; //s[i] ������� �� �������� ���� ��� ������� �� ��� ��� i
	}
	
	int from=s[n]/3, to=s[n], middle, *prev, i;
	while (from != to) //������� ��������� ��� �������� [from,to] ��� �� ����� ��� ��� ����������
	{
		middle = (from+to)/2;
		for (prev=s, i=0; i<3 && prev!=s+n; i++) //�� prev==s+n, ������� ��� ����� ��� ������ i=0; i<3 : ��� ���� ������
			prev = upper_bound(prev,s+n+1,middle+*prev)-1;	//upper_bound ���������� �� ���� ��'�� ������ ���������� � end(s+n+1) �� ��� ����� ���������
		if (prev == s+n) to = middle;
		else from = middle+1;
	}
	printf("%d\n",from);
	return 0;
}
