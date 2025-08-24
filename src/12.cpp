#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    unordered_map<int, string> char_map = {{1, "I"},   {5, "V"},   {10, "X"},
                                           {50, "L"},  {100, "C"}, {500, "D"},
                                           {1000, "M"}};
    string result;
    int temp = num % 10;
    int cnt = 1;
    if (temp < 4) {
      for (int i = 0; i < temp; i++) {
        result += char_map[1 * cnt];
      }
    } else if (temp == 4) {
      result += char_map[5 * cnt] + char_map[1 * cnt];
    } else if (temp == 5) {
      result += char_map[5 * cnt];
    } else if (temp < 9) {
      for (int i = 0; i < temp - 5; i++) {
        result += char_map[1 * cnt];
      }
      result += char_map[5 * cnt];
    } else {
      result += char_map[10 * cnt] + char_map[1 * cnt];
    }
    while (num /= 10) {
      temp = num % 10;
      cnt *= 10;
      if (temp < 4) {
        for (int i = 0; i < temp; i++) {
          result += char_map[1 * cnt];
        }
      } else if (temp == 4) {
        result += char_map[5 * cnt] + char_map[1 * cnt];
      } else if (temp == 5) {
        result += char_map[5 * cnt];
      } else if (temp < 9) {
        for (int i = 0; i < temp - 5; i++) {

          result += char_map[1 * cnt];
        }
        result += char_map[5 * cnt];
      } else {
        result += char_map[10 * cnt] + char_map[1 * cnt];
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main(int argc, const char **argv) {
  Solution s;
  std::cout << s.intToRoman(1994) << std::endl;
  return 0;
}
