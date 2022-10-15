#include <bits/stdc++.h>
using namespace std;

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
  int polygon = 0;
  const vector<int> cvRow = {0, 0, 1, 1};
  const vector<int> cvCol = {0, 1, 1, 0};

  for (int row = 0; row < (int)crvGrid.size() - 1; ++row)
    for (int col = 0; col < (int)crvGrid[row].size() - 1; ++col)
    {
      int angle = 0;
      
      for (int nx = 0; nx < 4; ++nx)
        if (crvGrid[ row + cvRow[nx] ][ col + cvCol[nx] ] == '#')
          ++angle;

      if (angle == 1 || angle == 3)
        ++polygon;
    }

  return polygon;
}
  
int main()
{
  vector<string> vGrid;
  
  input(vGrid);
  cout << calcPolygon(vGrid) << endl;

  return 0;
}
