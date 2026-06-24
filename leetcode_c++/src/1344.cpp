#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  double angleClock(int hour, int minutes) {
    double hour_point = (hour * 60 + minutes);
    double minutes_point = (minutes * 12);
    double angle =
        max(hour_point, minutes_point) - min(hour_point, minutes_point);
    if (720 - angle < angle) {
      angle = 720 - angle;
    }
    return angle / 2.0;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
