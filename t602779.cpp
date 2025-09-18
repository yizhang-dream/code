#include<bits/stdc++.h>
using namespace std;
int T, n, m;
#define N=10^9+7;

int j(int p) {
	int h = 1;
	for (i = 1; i <= h; i++) {
		h = h * i % N;
	}
	return h;
}
int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n >> m;
		if(m > n) {
			cout << j(n);
		}
		else {
			int k = n / m;
			int b = n % m;
			int x = m - b;
			int w = j(b) * j(x) % N;
			cout << j(k) * w % N;
		}
	}
	return 0
}