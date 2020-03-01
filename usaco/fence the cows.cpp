/*
ID:manolis2
PROG:fc
LANG:C++11
*/
#include <cmath>
#include <algorithm>
#define x first
#define y second
using namespace std;

class stack{
	public:
		int data[10005], size=0;
		void push(int p) {	data[size++] = p;	}
		void pop() {	--size;	   }
		int operator-(int i) {	return data[size-1-i];	 }
};

int n, minloc;
double apantisi;
pair<double,double> points[10005], p0={2000000,0};

bool comp(pair<double,double> a, pair<double,double> b)
{	return atan2(a.y-p0.y,a.x-p0.x) < atan2(b.y-p0.y,b.x-p0.x);	  }

bool ccw(pair<double,double> a, pair<double,double> b, pair<double,double> c)
{	return (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x) > 0;	}

double metro(double x, double y)
{	return sqrt(x*x+y*y);	}

int main()
{
	freopen("fc.in","r",stdin);
	freopen("fc.out","w",stdout);
	scanf("%d",&n);
	for (int i=0; i<n; i++)
	{
		scanf("%lf%lf",&points[i].x,&points[i].y);
		if (points[i].y < p0.y)
		{
			p0 = points[i];
			minloc = i;
		}
	} 
	swap(points[minloc],points[0]);
	sort(points+1,points+n,comp);
	
	stack s;
	s.push(n-1);
	s.push(0);
	s.push(1);
	for (int i=2; i<n; i++)
		if ( ccw(points[s-1], points[s-0], points[i]) ) s.push(i);
		else s.pop(),i--;
				
	for (int i=1; i<s.size; i++)
		apantisi += metro(points[s.data[i]].x-points[s.data[i-1]].x, points[s.data[i]].y-points[s.data[i-1]].y);
	apantisi += metro(points[s.data[0]].x-points[s-0].x, points[s.data[0]].y-points[s-0].y);
	printf("%.2lf\n",apantisi);
}
