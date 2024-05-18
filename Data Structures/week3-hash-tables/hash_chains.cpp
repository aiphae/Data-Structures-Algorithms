#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using std::string;
using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::endl;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    vector<list<string>> elems;

    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count), elems(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            auto index = query.ind;
            for (const auto &str: elems[index]) {
                cout << str << " ";
            }
            cout << endl;
        } else {
            auto index = hash_func(query.s);
            auto& bucket = elems[index];
            if (query.type == "find") {
                bool found = false;
                for (const auto &str: bucket) {
                    if (str == query.s) {
                        found = true;
                        break;
                    }
                }
                cout << (found ? "yes" : "no") << endl;
            } else if (query.type == "add") {
                auto it = std::find(bucket.begin(), bucket.end(), query.s);
                if (it == bucket.end())
                    bucket.push_front(query.s);
            } else if (query.type == "del") {
                bucket.remove(query.s);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
