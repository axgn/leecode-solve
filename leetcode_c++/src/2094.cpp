#include <array>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
class Solution {
  array<int, 11> map;
  vector<int> result;
  vector<int> temp;

public:
  void findresult(int i) {
    if (temp.size() < 3) {
      if (map[i] > 0) {
        temp.push_back(i);
        map[i]--;
        findresult(i);
        map[i]++;
        temp.pop_back();
      } else {
        for (int j = i + 1; j <= 9; j++) {
          findresult(j + 1);
        }
      }
    } else {
      findnumber();
    }
  }

  void findnumber() {}
  vector<int> findEvenNumbers(vector<int> &digits) {
    for (auto &digit : digits) {
      map[digit]++;
    }
    return result;
  }
};

class Solution2 {
  array<int, 11> map{0};
  bool is_number(int i) {
    array<int, 11> map2{0};
    int a = i / 100;
    int b = (i % 100) / 10;
    int c = i % 10;
    map2[a]++, map2[b]++, map2[c]++;
    for (int i = 0; i < 10; i++) {
      if (map[i] < map2[i]) {
        return false;
      }
    }
    return true;
  }

public:
  vector<int> findEvenNumbers(vector<int> &digits) {
    for (auto &digit : digits) {
      map[digit]++;
    }
    vector<int> result;
    for (int i = 100; i < 1000; i += 2) {
      if (is_number(i)) {
        result.push_back(i);
      }
    }
    return result;
  }
};
class Solution3 {
  array<int, 11> map{0};
  bool is_number(int a, int b, int c) {
    array<int, 11> map2{0};
    map2[a]++, map2[b]++, map2[c]++;
    for (int i = 0; i < 10; i++) {
      if (map[i] < map2[i]) {
        return false;
      }
    }
    return true;
  }

public:
  vector<int> findEvenNumbers(vector<int> &digits) {
    for (auto &digit : digits) {
      map[digit]++;
    }
    vector<int> result;
    for (int i = 1; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10; k += 2) {
          if (is_number(i, j, k)) {
            result.push_back(i * 100 + j * 10 + k);
          }
        }
      }
    }

    return result;
  }
};
int main() {
  Solution2 s;
  vector<int> v = {7, 4, 1, 7, 2, 2, 0, 3, 9};
  v = s.findEvenNumbers(v);
  ranges::copy(v, ostream_iterator<int>(cout, " "));
  cout << "" << endl;
  return 0;
}
