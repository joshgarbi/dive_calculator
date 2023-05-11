// header file for decompression stops function

#include <vector>
using namespace std;

// Function to calculate stop times and depth from dive time and depth, returns
// data in 2-D vector form. Use: int numCols = returnedVector[0].size(); to get
// number of columns, which correlates with number of stops.

vector<vector<int>> calculateStops(int time, int depth);