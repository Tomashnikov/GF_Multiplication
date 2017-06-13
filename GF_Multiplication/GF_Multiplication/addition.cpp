#include <vector>
#include <algorithm>

std::vector<int> addition(std::vector<int> a, std::vector<int> b) {

	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());

	std::vector<int> c;
	if (a.size() >= b.size()) {
		c.resize(a.size());
		for (int x = 0; x < a.size(); x++) c[x] = a[x];
		for (int x = 0; x < b.size(); x++) c[x] = a[x] ^ b[x];
	}
	else {
		c.resize(b.size());
		for (int x = 0; x < b.size(); x++) c[x] = b[x];
		for (int x = 0; x < a.size(); x++) c[x] = a[x] ^ b[x];
	}

	std::reverse(c.begin(), c.end());

	return c;
}