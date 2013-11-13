#ifndef __Util__Util__
#define __Util__Util__

namespace Util {
	int gcd(int a, int b);
	inline int lcm(int a, int b) {
		return (a / Util::gcd(a, b)) * b;
	}
	inline void swap(int& a, int& b) {
		int t = a; a = b; b = t;
	}
}

#endif /* defined (__Util__Util__) */