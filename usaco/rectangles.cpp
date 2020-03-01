/*
ID: manolis2
PROG: packrec 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

struct rect
{
	int x,y;
};
int rects[4][2], best=9999, nbest;
bool compare (rect a, rect b)
{
	return a.x<b.x;
}
set<rect,bool(*)(rect,rect)> rbest(compare);

int biggest(int a, int b, int c, int d)
{
	int biggest=0;
	if (a>biggest) biggest=a;
	if (b>biggest) biggest=b;
	if (c>biggest) biggest=c;
	if (d>biggest) biggest=d;
	return biggest;
}

void check(int x, int y)
{
	if (x*y<=best)
	{
		rect temp;
		if (x<y)
		{
			temp.x=x;
			temp.y=y;
		}
		else
		{
			temp.x=y;
			temp.y=x;
		}
		if (x*y<best)
		{
			rbest.clear();
			best=x*y;
		}
			
		rbest.insert(temp);	
	}
	return;
}

void l1()
{
	int w,h;
	for (int w1=0, h1=1; w1<2; w1++, h1--)
		for (int w2=0, h2=1; w2<2; w2++, h2--)
			for (int w3=0, h3=1; w3<2; w3++, h3--)
				for (int w4=0, h4=1; w4<2; w4++, h4--)
				{
					w=rects[0][w1]+rects[1][w2]+rects[2][w3]+rects[3][w4];
					h=biggest(rects[0][h1],rects[1][h2],rects[2][h3],rects[3][h4]);
					check (w,h);
				}
	return;
}

void l2(int a, int b, int c, int d)
{
    int w,h;
	for (int w1=0, h1=1; w1<2; w1++, h1--)
		for (int w2=0, h2=1; w2<2; w2++, h2--)
			for (int w3=0, h3=1; w3<2; w3++, h3--)
				for (int w4=0, h4=1; w4<2; w4++, h4--)
				{
                    w=biggest(rects[a][w1]+rects[b][w2]+rects[c][w3], rects[d][w4], 0, 0);
                    h=biggest(rects[a][h1], rects[b][h2], rects[c][h3], 0) + rects[d][h4];
                    check (w,h);
                }
    return;
}

void l3(int a, int b, int c, int d)
{
    int w,h;
	for (int w1=0, h1=1; w1<2; w1++, h1--)
		for (int w2=0, h2=1; w2<2; w2++, h2--)
			for (int w3=0, h3=1; w3<2; w3++, h3--)
				for (int w4=0, h4=1; w4<2; w4++, h4--)
				{
                    w=biggest(rects[a][w1]+rects[b][w2]+rects[c][w3], rects[c][w3]+rects[d][w4], 0, 0);
                    h=biggest(rects[c][h3], biggest(rects[a][h1], rects[b][h2], 0, 0) + rects[d][h4], 0, 0);
                    check (w,h);
                }
    return;
}

void l4_5(int a, int b, int c, int d)
{
    int w,h;
	for (int w1=0, h1=1; w1<2; w1++, h1--)
		for (int w2=0, h2=1; w2<2; w2++, h2--)
			for (int w3=0, h3=1; w3<2; w3++, h3--)
				for (int w4=0, h4=1; w4<2; w4++, h4--)
				{
                    w=biggest(rects[a][w1], rects[b][w2], 0, 0) + rects[c][w3] + rects[d][w4];
                    h=biggest(rects[a][h1]+rects[b][h2], rects[c][h3], rects[d][h4], 0);
                    check (w,h);
                }
    return;
}

void l6(int a, int b, int c, int d)
{
    int w,h;
	for (int w1=0, h1=1; w1<2; w1++, h1--)
		for (int w2=0, h2=1; w2<2; w2++, h2--)
			for (int w3=0, h3=1; w3<2; w3++, h3--)
				for (int w4=0, h4=1; w4<2; w4++, h4--)
				{
					if (rects[a][h1] < rects[b][h2])
						w=biggest(rects[a][w1]+rects[b][w2], rects[c][w3]+rects[b][w2], rects[c][w3]+rects[d][w4], 0);
					else if (rects[a][h1] > rects[b][h2])
						w=biggest(rects[a][w1]+rects[b][w2], rects[a][w1]+rects[d][w4], rects[c][w3]+rects[d][w4], 0);
					else
						w=biggest(rects[a][w1]+rects[b][w2], rects[c][w3]+rects[d][w4], 0, 0);
						
					if (rects[a][w1] < rects[c][w3])
						h=biggest(rects[a][h1]+rects[c][h3], rects[c][h3]+rects[b][h2], rects[b][h2]+rects[d][h4], 0);
					else if (rects[a][w1] > rects[c][w3])
						h=biggest(rects[a][h1]+rects[c][h3], rects[a][h1]+rects[d][h4], rects[b][h2]+rects[d][h4], 0);
					else
						h=biggest(rects[a][h1]+rects[c][h3], rects[b][h2]+rects[d][h4], 0, 0);
					check(w,h);
				}
    return;
}

void debug(int layout)
{
     cout << "best after layout: " << layout << endl;
     for (set<rect>::iterator i=rbest.begin(); i!=rbest.end(); i++)
		cout << i->x << " " << i->y << endl << endl;
}

int main()
{
	ifstream input("packrec.in");
	ofstream output("packrec.out");
	for (int i=0; i<4; i++)
		for (int j=0; j<2; j++)
			input >> rects[i][j];
			
	l1();
	debug(1);
	l2(3,2,1,0); l2(0,2,3,1); l2(0,1,3,2); l2(0,1,2,3);
	debug(2);
	l3(3,2,0,1); l3(3,1,0,2); l3(1,2,0,3); l3(3,2,1,0); l3(3,0,1,2); l3(0,2,1,3); l3(3,1,2,0); l3(3,0,2,1); l3(0,1,2,3); l3(1,2,3,0); l3(0,2,3,1); l3(0,1,3,2);
	debug(3);
    l4_5(3,2,0,1); l4_5(3,1,0,2); l4_5(1,2,0,3); l4_5(3,2,1,0); l4_5(3,0,1,2); l4_5(0,2,1,3); l4_5(3,1,2,0); l4_5(3,0,2,1); l4_5(0,1,2,3); l4_5(1,2,3,0); l4_5(0,2,3,1); l4_5(0,1,3,2);
	debug(45);
    for (int i1=0; i1<4; i1++)
	    for (int i2=0; i2<4; i2++)
	        if (i2!=i1)
	           for (int i3=0; i3<4; i3++)
	               if ((i3!=i1) && (i3!=i2))
	                  for (int i4=0; i4<4; i4++)
	                      if ((i4!=i1) && (i4!=i2) && (i4!=i3))
	                         l6(i1,i2,i3,i4);
	
	debug(6);
	output << best << endl;
	for (set<rect>::iterator i=rbest.begin(); i!=rbest.end(); i++)
		output << i->x << " " << i->y << endl;
	return 0;
	
}

