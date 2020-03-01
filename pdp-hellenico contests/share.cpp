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
		s[i] += s[i-1]; //s[i] κρατάει το άθροισμα όλων των αριθμών ως και τον i
	}
	
	int from=s[n]/3, to=s[n], middle, *prev, i;
	while (from != to) //δυαδική αναζήτηση στο διάστημα [from,to] για τα λεφτά του πιο ευνοημένου
	{
		middle = (from+to)/2;
		for (prev=s, i=0; i<3 && prev!=s+n; i++) //αν prev==s+n, φτάσαμε στο τέλος του πίνακα i=0; i<3 : για κάθε αδελφό
			prev = upper_bound(prev,s+n+1,middle+*prev)-1;	//upper_bound επιστρέφει τη θέση απ'το αμέσως μεγαλύτερο ή end(s+n+1) αν όλα είναι μικρότερα
		if (prev == s+n) to = middle;
		else from = middle+1;
	}
	printf("%d\n",from);
	return 0;
}
