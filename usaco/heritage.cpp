/*
ID:manolis2
PROG:heritage
LANG:C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("heritage.in");
ofstream fout("heritage.out");
string lrootr, rootlr;
struct node{
	char c;
	node *parent,*left,*right;
};
node root;
int pos=0;

void make_tree(node &curr, int left, int right)
{
	curr.c = rootlr[pos++];
	if (left == right) return;
	for (int i=left; i<=right; i++)
		if (lrootr[i] == rootlr[pos-1])
		{
			if (i==left)
			{
				curr.right = new node{0,&curr,0,0};
				make_tree(*curr.right,i+1,right);
			}
			else if (i==right)
			{
				curr.left = new node{0,&curr,0,0};
				make_tree(*curr.left,left,i-1);
			}
			else
			{
				curr.left = new node{0,&curr,0,0};
				curr.right = new node{0,&curr,0,0};
				make_tree(*curr.left,left,i-1);
				make_tree(*curr.right,i+1,right);
			}
			return;
		}	
}

void traverse(node &curr)
{
	if (curr.left) traverse(*curr.left);
	if (curr.right) traverse(*curr.right);
	fout << curr.c;
}

int main()
{
	fin >> lrootr >> rootlr;
	make_tree(root,0,lrootr.length()-1);
	traverse(root);
	fout << endl;
	return 0;
}

