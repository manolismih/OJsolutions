#include <iostream>
#include <algorithm>
using namespace std;

int t,n,f,heights[10005];
long long apantisi;
pair<int*,int*> bounds;

int main()
{
	cin >> t;
	for (int i=0; i<t; i++)
	{
		apantisi = 0;
		cin >> n >> f;
		for (int i=0; i<n; i++)
			cin >> heights[i];
		sort(heights,heights+n);
		for (int i=n-1; i>0; i--)
			for (int h=heights[i]; ; h/=f)
			{
				bounds = equal_range(heights,heights+i,h);
				if (bounds.first != bounds.second)
					apantisi += bounds.second - bounds.first;
				if (h%f) break;
			}
		cout << apantisi << endl;
	}
	return 0;
}

