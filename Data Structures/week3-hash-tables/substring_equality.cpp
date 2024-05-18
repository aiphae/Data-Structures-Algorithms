#include <iostream>
#include <vector>
#include <random>

using namespace std;
typedef unsigned long long llu;

class Solver {
    string s;
    vector<long long> h1, h2, p1, p2;
    const long long m1 = 1000000007;
    const long long m2 = 1000000009;
    long long x;

public:
    Solver(string s) : s(s), h1(s.size() + 1), h2(s.size() + 1), p1(s.size() + 1), p2(s.size() + 1) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<long long> dis(1, m1 - 1);
        x = dis(gen);

        h1[0] = h2[0] = 0;
        p1[0] = p2[0] = 1;
        for (int i = 1; i <= s.size(); ++i) {
            h1[i] = (x * h1[i - 1] + s[i - 1]) % m1;
            h2[i] = (x * h2[i - 1] + s[i - 1]) % m2;
            p1[i] = (p1[i - 1] * x) % m1;
            p2[i] = (p2[i - 1] * x) % m2;
        }
    }

    bool ask(int a, int b, int l) {
        llu hash1_a, hash1_b, hash2_a, hash2_b;
        hash1_a = (h1[a + l] - (p1[l] * h1[a] % m1) + m1) % m1;
        hash1_b = (h1[b + l] - (p1[l] * h1[b] % m1) + m1) % m1;
        hash2_a = (h2[a + l] - (p2[l] * h2[a] % m2) + m2) % m2;
        hash2_b = (h2[b + l] - (p2[l] * h2[b] % m2) + m2) % m2;
        return hash1_a == hash1_b && hash2_a == hash2_b;
    }
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
