#include <bits/stdc++.h>
using namespace std;

void input(vector<string>& rvGrid)
{
  int sizRow, sizCol;
  cin >> sizRow >> sizCol;
  rvGrid.resize(sizRow);

  for (string& rsGrid : rvGrid)
    cin >> rsGrid;
}

int calcPolygon(const vector<string>& crvGrid)
{
  const vector<int> cvRow = {0, 1, 1, 0};
  const vector<int> cvCol = {0, 0, 1, 1};
  int polygon = 0;

  for (int row = 0; row < (int)crvGrid.size() - 1; ++row)
    for (int col = 0; col < (int)crvGrid[row].size() - 1; ++col)
    {
      int angle = 0;

      for (int nx = 0; nx < 4; ++nx)
        if ( crvGrid[ row + cvRow[nx] ][ col + cvCol[nx] ] == '#' )
          ++angle;

      if ( angle == 1 || angle == 3 )
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
