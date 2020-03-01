#include <iostream>
#include <string>
#include <forward_list>
using namespace std;
#define c first
#define ptr second

struct node{forward_list<pair<char,node*>> children; bool word;};

int longest;
string s, last;
node trie;

void insert()
{
	node *curr = &trie;
	int words=0;
	for (int i=0, stop=s.length(); i<stop; i++)
	{
		if (curr->word) words++;
		if (curr->children.empty() || curr->children.front().c != s[i]) curr->children.push_front({s[i],new node()});
		curr = curr->children.front().ptr;
	}
	curr->word = 1;
	words++;
	if (words>longest)
	{
		longest = words;
		last = s;
	}
}

void backtrack()
{
	s="";
	node *curr = &trie;
	for (int i=0, stop=last.length(); i<stop; i++)
	{
		if (curr->word) cout << s << endl;
		for (auto it:curr->children)
			if (it.c == last[i])
			{
				s += last[i];
				curr = it.ptr;
				break;
			}
	}
	cout << last << endl;
}

int main()
{
	while (cin >> s && s != ".")
		insert();
	backtrack();
}
