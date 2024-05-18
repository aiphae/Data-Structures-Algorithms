#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

struct Answer {
	size_t i, j, len;
};

class PolyHash {
private:
    const ull m1 = 1e9 + 7;
    const ull m2 = 1e9 + 9;
    ull x;
    vector<ull> h1, h2, p1, p2;

public:
    PolyHash(const string &s, ull base) {
        x = base;

        size_t length = s.size();

        h1.resize(length + 1, 0);
        h2.resize(length + 1, 0);
        p1.resize(length + 1, 1);
        p2.resize(length + 1, 1);

        for (int i = 1; i <= s.size(); ++i) {
            h1[i] = (x * h1[i - 1] + s[i - 1]) % m1;
            h2[i] = (x * h2[i - 1] + s[i - 1]) % m2;
            p1[i] = (p1[i - 1] * x) % m1;
            p2[i] = (p2[i - 1] * x) % m2;
        }
    }

    pair<ull, ull> getHash(int start, int end) {
        ull hash1 = (h1[end] + m1 - (h1[start] * p1[end - start] % m1)) % m1;
        ull hash2 = (h2[end] + m2 - (h2[start] * p2[end - start] % m2)) % m2;
        return {hash1, hash2};
    }
};

struct pair_hash {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

Answer solve(const string &s, const string &t) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ull> dis(1, 1e9 + 6);
    ull x = dis(gen);

    PolyHash s_hash(s, x), t_hash(t, x);

    int start = 0, end = min(s.size(), t.size());
    size_t best_len = 0, best_i = 0, best_j = 0;

    auto check = [&](int length) -> bool {
        unordered_map<pair<ull, ull>, int, pair_hash> hashes;
        for (int i = 0; i + length <= s.size(); ++i) {
            hashes.insert({s_hash.getHash(i, i + length), i});
        }

        for (int j = 0; j + length <= t.size(); ++j) {
            auto hash_t = t_hash.getHash(j, j + length);
            auto it = hashes.find(hash_t);
            if (it != hashes.end()) {
                best_i = it->second;
                best_j = j;
                return true;
            }
        }

        return false;
    };

    while (start <= end) {
        int middle = (start + end) / 2;
        if (check(middle)) {
            best_len = middle;
            start = middle + 1;
        }
        else end = middle - 1;
    }

    Answer ans = {best_i, best_j, best_len};

	return ans;
}

int main() {
	string s, t;
	while (cin >> s >> t) {
		auto ans = solve(s, t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}
