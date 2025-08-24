#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  struct line {
    vector<int>::iterator start;
    vector<int>::iterator end;
    int length;
  };

  struct Compare {
    bool operator()(const line &line1, const line &line2) {
      return line1.length < line2.length;
    }
  };

  vector<int>::iterator find_next(const line &line1,
                                  const vector<int> &position) {
    auto start = line1.start;
    auto end = line1.end;
    int target = *start + (*end - *start) / 2;
    auto mid = start + (end - start) / 2;
    while (end - start > 1) {
      mid = start + (end - start) / 2;
      if (*mid > target) {
        end = mid - 1;
      } else if (*mid < target) {
        start = mid + 1;
      } else {
        return mid;
      }
    }
    return abs(*end - target) > abs(*start - target) ? start : end;
  }

public:
  bool check(vector<int> &position, int mid, int m) {
    int cnt = 1;
    int pre = position[0];
    for (int i = 1; i < position.size(); i++) {
      if (position[i] - pre >= mid) {
        pre = position[i];
        cnt++;
      }
    }
    return m <= cnt;
  }
  int maxDistance(vector<int> &position, int m) {
    sort(position.begin(), position.end());
    int left = 1, right = position.back() - position.front();
    int mid, res = -1;
    while (left <= right) {
      mid = (left + right) / 2;
      if (check(position, mid, m)) {
        res = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return res;
  }
  int maxDistance1(vector<int> &position, int m) {
    int result;
    sort(position.begin(), position.end());
    priority_queue<line, vector<line>, Compare> pq_line;
    pq_line.push({.start = position.begin(),
                  .end = position.end() - 1,
                  .length = *(position.end() - 1) - *(position.begin())});
    m -= 2;
    while (m > 0) {
      line current = pq_line.top();
      auto next = find_next(current, position);
      pq_line.pop();
      pq_line.push({.start = current.start,
                    .end = next,
                    .length = *next - *current.start});
      pq_line.push(
          {.start = next, .end = current.end, .length = *current.end - *next});
      m--;
    }
    while (!pq_line.empty()) {
      if (pq_line.size() == 1) {
        result = pq_line.top().length;
      }
      pq_line.pop();
    }
    return result;
  }
};

int main(int argc, const char **argv) {
  vector<int> position = {1, 2, 3, 4, 7, 100, 50, 34};
  int m = 4;
  Solution s;
  cout << s.maxDistance(position, m);
  return 0;
}