#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

bool check(int i, int j, int size) {
  if (i < 0 || j < 0 || i >= size || j >= size) {
    return false;
  }
  return true;
}

std::mt19937 rng(std::random_device{}());

void random_direction(std::vector<std::pair<int, int>> &direction) {
  std::vector<std::pair<int, int>> temp = {
      {-2, 0},
      {2, 0},
      {0, -2},
      {0, 2},
  };
  srand((unsigned)time(NULL));
  int random_num = rand() % 4;
  direction[0] = std::move(temp[random_num]);
  direction[1] = std::move(temp[(random_num + 1) % 4]);
  direction[2] = std::move(temp[(random_num + 2) % 4]);
  direction[3] = std::move(temp[(random_num + 3) % 4]);
}

void random_direction(std::vector<std::pair<int, int>> &direction,
                      std::mt19937 &rng) {
  direction = {
      {-2, 0},
      {2, 0},
      {0, -2},
      {0, 2},
  };
  std::shuffle(direction.begin(), direction.end(), rng);
}

void dfs(std::vector<std::vector<int>> &map, int i, int j) {
  std::vector<std::pair<int, int>> directions(4);
  random_direction(directions, rng);
  int size = map.size();
  map[i][j] = 2;
  for (auto &direction : directions) {
    int i1 = i + direction.first, i2 = i + direction.first / 2;
    int j1 = j + direction.second, j2 = j + direction.second / 2;
    if (check(i1, j1, size) && map[i1][j1] == 1) {
      dfs(map, i1, j1);
      map[i2][j2] = 2;
    }
  }
}

int main() {
  std::vector<std::vector<int>> map(21, std::vector<int>(21, 0));
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      if (i % 2 && j % 2) {
        map[i][j] = 1;
      }
    }
  }
  dfs(map, 1, 1);
  for (int i = 0; i < 21; i += 2) {
    for (int j = 0; j < 21; j++) {
      bool up = map[i][j] == 0;
      bool down = (i + 1 < 21) ? map[i + 1][j] == 0 : true;

      if (up && down)
        std::cout << "█";
      else if (up && !down)
        std::cout << "▀";
      else if (!up && down)
        std::cout << "▄";
      else
        std::cout << " ";
    }
    std::cout << '\n';
  }
  return 0;
}
