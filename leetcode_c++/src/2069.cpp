#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Robot {
  static constexpr array<string, 4> directions = {"North", "East", "South",
                                                  "West"};
  vector<array<int, 3>> pos_dire;
  int i = 0;
  bool moved = false;

public:
  Robot(int width, int height) {
    for (int i = 0; i < width - 1; i++) {
      array<int, 3> arr = {i, 0, 1};
      if (i == 0) {
        arr[2] = 2;
      }
      pos_dire.push_back(arr);
    }
    for (int i = 0; i < height - 1; i++) {
      array<int, 3> arr = {width - 1, i, 0};
      if (i == 0) {
        arr[2] = 1;
      }
      pos_dire.push_back(arr);
    }
    for (int i = 0; i < width - 1; i++) {
      array<int, 3> arr = {width - 1 - i, height - 1, 3};
      if (i == 0) {
        arr[2] = 0;
      }
      pos_dire.push_back(arr);
    }
    for (int i = 0; i < height - 1; i++) {
      array<int, 3> arr = {0, height - 1 - i, 2};
      if (i == 0) {
        arr[2] = 3;
      }
      pos_dire.push_back(arr);
    }
  }

  void step(int num) {
    moved = true;
    int n = pos_dire.size();
    i = (i + num) % n;
  }

  vector<int> getPos() { return vector<int>{pos_dire[i][0], pos_dire[i][1]}; }

  string getDir() {
    if (moved) {
      return directions.at(pos_dire[i][2]);
    } else {
      return "East";
    }
  }
};

int main() {

  Robot *obj = new Robot(6, 3);
  obj->step(2);
  obj->step(2);
  obj->step(2);
  obj->step(1);
  obj->step(4);
  vector<int> param_2 = obj->getPos();
  string param_3 = obj->getDir();

  return 0;
}
