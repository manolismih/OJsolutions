#include <iostream>
#include <string>
using namespace std;

int n, nothing;
string s;

int main()
{
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> nothing >> s;
		if (s.find('I') != s.npos)
			cout << "INDIAN" << endl;
		else if (s.find('Y') != s.npos)
			cout << "NOT INDIAN" << endl;
		else 
			cout << "NOT SURE" << endl;
	}
	return 0;
}

