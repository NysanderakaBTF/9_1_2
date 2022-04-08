#include "hexmask.h"
#include <iostream>
hexmask::hexmask(string va, string ma)
{
	va = "0x"+va; ma = "0x" + ma;
	memset(val, 0, 8);
	memset(mask, 0, 8);
	int v = stoul(va, nullptr, 16);
	for (int i = 7; i >= 0; i--, v>>=1) {
		val[i] = v & 1;
	}
	v = stoul(ma, nullptr, 16);
	for (int i = 7; i >= 0; i--, v >>= 1) {
		mask[i] = v & 1;
	}
}

hexmask& hexmask::operator&(hexmask& a)
{
	for (int i = 0; i < 8; i++) {
		if (this->mask[i] && a.mask[i]) {
			this->val[i] = this->val[i] & a.val[i];
		}
	}
	return *this;
}
hexmask& hexmask::operator|(hexmask& a)
{
	for (int i = 0; i < 8; i++) {
		if (this->mask[i] && a.mask[i]) {
			this->val[i] = this->val[i] | a.val[i];
		}
	}
	return *this;
}

string hexmask::get_hex_val()
{
	char ss[8];
	int q = 0;
	for (int i = 0; i < 8; i++) {
		q += pow(2, (7 - i)) * val[i];
	}
	_itoa_s(q, ss,8, 16);
	for (int i = 0; i < 8; i++) ss[i]=toupper(ss[i]);
	return (string(ss));
}
