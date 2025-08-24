#include <vector>
class Mat {
  std::vector<std::vector<int>> data;
  int x, y;

public:
  Mat(std::vector<std::vector<int>> &_data)
      : data(_data), x(_data.size()), y(_data[0].size()) {}
  Mat(std::vector<std::vector<int>> _data = {})
      : data(_data), x(_data.size()), y(_data[0].size()) {}
  Mat(const Mat &other) : data(other.data), x(other.x), y(other.y) {}
  friend Mat operator*(const Mat &a, const Mat &b);
  friend Mat I();
  Mat &operator=(const Mat &other) {
    if (this != &other) {
      data = other.data;
      x = other.x;
      y = other.y;
    }
    return *this;
  }
};

Mat operator*(const Mat &a, const Mat &b) {
  Mat result(std::vector<std::vector<int>>(a.x, std::vector<int>(b.y, 0)));
  for (int i = 0; i < a.x; i++) {
    for (int j = 0; j < b.y; j++) {
      for (int k = 0; k < a.y; k++) {
        result.data[i][j] += a.data[i][k] * b.data[k][j];
      }
    }
  }
  return result;
}
Mat I() {
  Mat w(std::vector<std::vector<int>>(26, std::vector<int>(26, 0)));
  for (int i = 0; i < w.x; ++i) {
    w.data[i][i] = 1;
  }
  return w;
}

Mat quickmul(const Mat &x, int y) {
  Mat ans = I(), cur = x;
  while (y) {
    if (y & 1) {
      ans = ans * cur;
    }
    cur = cur * cur;
    y >>= 1;
  }
  return ans;
}
