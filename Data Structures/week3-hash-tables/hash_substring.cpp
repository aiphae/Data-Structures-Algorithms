#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    const std::string& s = input.pattern, t = input.text;
    std::vector<int> ans;

    int pattern_length = s.length();
    int text_length = t.length();
    if (pattern_length > text_length) return ans;

    const ull prime = 5381;
    const ull base = 256;

    ull pattern_hash = 0;
    ull text_hash = 0;
    ull highest_base_power = 1;

    for (int i = 0; i < pattern_length - 1; ++i) {
        highest_base_power = (highest_base_power * base) % prime;
    }

    for (int i = 0; i < pattern_length; ++i) {
        pattern_hash = (pattern_hash * base + s[i]) % prime;
        text_hash = (text_hash * base + t[i]) % prime;
    }

    for (int i = 0; i <= text_length - pattern_length; ++i) {
        if (pattern_hash == text_hash) {
            bool match = true;
            for (int j = 0; j < pattern_length; ++j) {
                if (t[i + j] != s[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                ans.push_back(i);
            }
        }

        if (i < text_length - pattern_length) {
            text_hash = (text_hash + prime - t[i] * highest_base_power % prime) % prime;
            text_hash = (text_hash * base + t[i + pattern_length]) % prime;
        }
    }

    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
