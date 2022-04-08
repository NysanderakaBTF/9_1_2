#pragma once
#include <string>
using namespace std;
class hexmask
{
private:
	bool val[8];
	bool mask[8];
public:
	hexmask(string, string);
	hexmask& operator& (const hexmask& a);
	hexmask& operator| (const hexmask& a);
	string get_hex_val();

};

