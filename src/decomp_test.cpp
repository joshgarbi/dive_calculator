#include "decomp.cpp"
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void test_calculate_stops() {
  vector<vector<int>> test = calculateStops(715, 27);
  // Expected vector: [20, 158]
  // Vector creation testing
  assert(test.size() == 2);
  assert(test[0].size() == 1);
  assert(test[1].size() == 1);
  assert(test[0][0] == 20);
  assert(test[1][0] == 158);

  test = calculateStops(500, 30);
  // Expected vector: [20, 71]
  assert(test[0][0] == 20);
  assert(test[1][0] == 71);

  test = calculateStops(400, 33);
  // Expected vector: [20, 134]
  assert(test[0][0] == 20);
  assert(test[1][0] == 134);

  test = calculateStops(500, 35);
  // Expected vector: [20, 228]
  assert(test[0][0] == 20);
  assert(test[1][0] == 228);

  test = calculateStops(250, 37);
  // Expected vector: [20, 101]
  assert(test[0][0] == 20);
  assert(test[1][0] == 101);

  test = calculateStops(500, 40);
  // Expected vector: [20, 372]
  assert(test[0][0] == 20);
  assert(test[1][0] == 372);

  test = calculateStops(150, 25);
  // Expected vector: [,]
  assert(test.size() == 2);
  assert(test[0].size() == 0);
  assert(test[1].size() == 0);
}

int main() {
  test_calculate_stops();
  return 0;
}