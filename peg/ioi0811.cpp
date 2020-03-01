#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	bool isword;
	node *next[26];
};

int n,moves;
string apantisi,s,best;
node tree, *curr;

void print(node *curr, int watch)
{
	if (watch == best.length())
	{
		cout << moves+1 << '\n' << apantisi << 'P' << endl;
		exit(0);
	}
	if (curr->isword) apantisi+="P\n", moves++;
	int stop = watch>-1 ? best[watch]-'a' : 26, i=0;
	for (int count=0; count<2; count++)
	{
		for (; i<stop; i++)
			if (curr->next[i])
			{
				apantisi += 'a'+i;
				apantisi += '\n';
				moves += 2;
				print(curr->next[i],-1);
				apantisi += "-\n";
			}
		if (watch==-1) return;
		stop = 26, i++;
	}
	apantisi += best[watch];
	apantisi += '\n';
	moves++;
	print(curr->next[best[watch]-'a'],watch+1);
}

int main()
{
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> s;
		if (s.length() > best.length()) best=s;
		curr = &tree;
		for (int i=0; i<s.length(); i++)
		{
			if (!curr->next[s[i]-'a']) curr->next[s[i]-'a'] = new node{0};
			curr = curr->next[s[i]-'a'];
		}
		curr->isword = true;
	}
	print(&tree,0);
	return 0;
}
