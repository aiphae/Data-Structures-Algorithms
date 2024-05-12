#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;

class MinHeap {
private:
    vector<std::pair<long long, int>> data; // {next_free_time, worker_index}

    void SiftUp(int i) {
        while (i > 0 && data[(i - 1) / 2].first > data[i].first) {
            swap(data[(i - 1) / 2], data[i]);
            i = (i - 1) / 2;
        }
    }

    void SiftDown(int i) {
        int minIndex = i;
        int l = 2 * i + 1;
        if (l < data.size() && (data[l].first < data[minIndex].first || (data[l].first == data[minIndex].first && data[l].second < data[minIndex].second)))
            minIndex = l;
        int r = 2 * i + 2;
        if (r < data.size() && (data[r].first < data[minIndex].first || (data[r].first == data[minIndex].first && data[r].second < data[minIndex].second)))
            minIndex = r;
        if (i != minIndex) {
            swap(data[i], data[minIndex]);
            SiftDown(minIndex);
        }
    }

public:
    MinHeap() {}

    void Insert(std::pair<long long, int> job) {
        data.push_back(job);
        SiftUp(data.size() - 1);
    }

    std::pair<long long, int> ExtractMin() {
        std::pair<long long, int> result = data[0];
        data[0] = data[data.size() - 1];
        data.pop_back();
        SiftDown(0);
        return result;
    }
};

class JobQueue {
private:
    int num_workers_;
    vector<int> jobs_;

    vector<int> assigned_workers_;
    vector<long long> start_times_;

    void WriteResponse() const {
        for (int i = 0; i < jobs_.size(); ++i) {
            cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
        }
    }

    void ReadData() {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for (int i = 0; i < m; ++i)
            cin >> jobs_[i];
    }

    void AssignJobs() {
        assigned_workers_.resize(jobs_.size());
        start_times_.resize(jobs_.size());

        MinHeap next_free_time;
        for (int i = 0; i < num_workers_; ++i)
            next_free_time.Insert({0, i});

        for (int i = 0; i < jobs_.size(); ++i) {
            int duration = jobs_[i];
            std::pair<long long, int> next_worker = next_free_time.ExtractMin();
            assigned_workers_[i] = next_worker.second;
            start_times_[i] = next_worker.first;
            next_free_time.Insert({next_worker.first + duration, next_worker.second});
        }
    }

public:
    void Solve() {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
