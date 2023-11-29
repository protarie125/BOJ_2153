#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

constexpr auto MaxN = ll{ 2000 };

string s;

vb sieve;

void init() {
	sieve = vb(MaxN + 1, true);
	sieve[0] = false;

	for (auto i = 2; i * i <= MaxN; ++i) {
		if (!sieve[i]) {
			continue;
		}

		for (auto j = i + i; j <= MaxN; j += i) {
			sieve[j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> s;

	init();

	auto val = ll{ 0 };
	for (const auto& c : s) {
		if ('a' <= c && c <= 'z') {
			val += c - 'a' + 1;
		}
		else if ('A' <= c && c <= 'Z') {
			val += c - 'A' + 27;
		}
	}

	cout << (sieve[val] ? "It is a prime word." : "It is not a prime word.");

	return 0;
}