#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;
    std::stack<int> maxValues;
public:
    void Push(int value) {
        stack.push_back(value);
        if (maxValues.empty() || value >= maxValues.top()) maxValues.push(value);
    }

    void Pop() {
        assert(stack.size());
        if (stack.back() == maxValues.top()) maxValues.pop();
        stack.pop_back();
    }

    int Max() const {
        return maxValues.top();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}