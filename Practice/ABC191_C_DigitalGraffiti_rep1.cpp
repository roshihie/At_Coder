#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;

void input(vector<string>& rvGrid)
{
  int sizGrid, sizLen;
  cin >> sizGrid >> sizLen;
  rvGrid.resize(sizGrid);

  for (string& rstr : rvGrid)
    cin >> rstr;
}

int calcPolygon(const vector<string>& crvGrid)
{
  const vector<uint> cvRow = {0, 0, 1, 1};
  const vector<uint> cvCol = {0, 1, 1, 0};
  int cntPolygon = 0;

  for (uint row = 0; row < crvGrid.size() - 1; ++row)
    for (uint col = 0; col < crvGrid[row].size() - 1; ++col)
    {
      int cntEach = 0;

      for (int nx = 0; nx < 4; ++nx)
        if (crvGrid[ row + cvRow[nx] ][ col + cvCol[nx] ] == '#')
          ++cntEach;

      if (cntEach == 1 || cntEach == 3)
        ++cntPolygon;
    }

  return cntPolygon;
}
  
int main()
{
  vector<string> vGrid;
  
  input(vGrid);
  cout << calcPolygon(vGrid) << endl;

  return 0;
}
