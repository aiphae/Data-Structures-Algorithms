#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;
using std::pair;

struct Query {
    string type, name;
    int number;
};

class HashTable {
private:
    static const int SIZE = 10000000;
    vector<pair<int, string>> table;

    int hash(int key) const {
        return key % SIZE;
    }

public:
    HashTable() : table(SIZE, std::make_pair(-1, "")) {}

    void add(int number, const string &name) {
        int index = hash(number);
        table[index].first = number;
        table[index].second = name;
    }

    void remove(int number) {
        int index = hash(number);
        table[index].first = -1;
        table[index].second = "";
    }

    string find(int number) {
        int index = hash(number);
        if (table[index].first != -1 && !table[index].second.empty()) return table[index].second;
        else return "not found";
    }
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    HashTable contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            contacts.add(queries[i].number, queries[i].name);
        } else if (queries[i].type == "del") {
            contacts.remove(queries[i].number);
        } else {
            result.push_back(contacts.find(queries[i].number));
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
