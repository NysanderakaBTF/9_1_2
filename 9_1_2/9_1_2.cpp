#include"hexmask.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string a, b;
	int n,nn;
	char q;
	vector<hexmask> ve;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ve.push_back(hexmask(a, b));
	}
	while (cin >> n >> q >> nn) {
		if (q == '&')
			ve[n - 1] = ve[n - 1] & ve[nn - 1];
		else if (q == '|')
			ve[n - 1] = ve[n - 1] | ve[nn - 1];
	}
	cout << ve[nn - 1].get_hex_val();

}

