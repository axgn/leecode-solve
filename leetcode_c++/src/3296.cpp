#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  struct Worker {
    long long cur_value;
    int raw_value;
    long long all_value;
  };

  struct cmp {
    bool operator()(Worker &a, Worker &b) {
      return a.cur_value + a.all_value > b.cur_value + b.all_value;
    }
  };

public:
  long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
    long long res = 0;
    priority_queue<Worker, vector<Worker>, cmp> heap;
    for (auto &worker1 : workerTimes) {
      heap.push(Worker{worker1, worker1, 0});
    }
    while (mountainHeight > 0) {
      Worker temp = heap.top();
      heap.pop();
      temp.all_value += temp.cur_value;
      heap.emplace(Worker{temp.cur_value + temp.raw_value, temp.raw_value,
                          temp.all_value});
      mountainHeight--;
    }
    while (!heap.empty()) {
      Worker one = heap.top();
      if (one.all_value > res) {
        res = one.all_value;
      }
      heap.pop();
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> v = {3, 2, 2, 4};
  cout << s.minNumberOfSeconds(100, v) << "\n";
  return 0;
}
