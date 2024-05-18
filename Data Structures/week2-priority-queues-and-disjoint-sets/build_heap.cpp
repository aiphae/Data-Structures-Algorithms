#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
private:
    vector<int> data_;
    vector<pair<int, int>> swaps_;

    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for(int i = 0; i < n; ++i)
        cin >> data_[i];
    }

    void GenerateSwaps() {
        swaps_.clear();
        for (int i = data_.size() / 2; i > -1; i--) {
            SiftDown(i);
        }
    }

    void SiftDown(int i) {
        int min = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < data_.size() && data_[left] < data_[min]) {
            min = left;
        }
        if (right < data_.size() && data_[right] < data_[min]) {
            min = right;
        }
        if (i != min) {
            std::swap(data_[i], data_[min]);
            swaps_.emplace_back(i, min);
            SiftDown(min);
        }
    }
public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
      std::ios_base::sync_with_stdio(false);
      HeapBuilder heap_builder;
      heap_builder.Solve();
      return 0;
}
