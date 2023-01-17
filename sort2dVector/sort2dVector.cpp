#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<vector<int>>& v) {
  for (const auto& a : v) {
    for (const auto& b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> v = {{6, 2, 4}, {3}, {6, 2}, {1, 5, 2}, {3, 1, 1}};

  sort(v.begin(), v.end());

  printVector(v);
  /*
    実行結果
    1 5 2
    3 1 1
    3 8 7
    6 2 1
    6 2 4
  */

  return 0;
}