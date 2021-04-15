#include <bits/stdc++.h>
using namespace std;

void input(vector<string>& rvsGrid)
{
  int nRowSiz, nColSiz;
  cin >> nRowSiz >> nColSiz;
  rvsGrid.resize(nRowSiz);

  for (string& rsGrid : rvsGrid)
      cin >> rsGrid;
}

int calcPolygon(const vector<string>& cnrvsGrid)
{
  const vector<int> cnvnDy = { 0, 0, 1, 1};
  const vector<int> cnvnDx = { 0, 1, 1, 0};

  int nPolygon = 0;

  for (int ny = 0; ny < cnrvsGrid.size() - 1; ++ny)
    for (int nx = 0; nx <cnrvsGrid[ny].size() - 1; ++nx)
    {
      int nBlackCnt = 0;

      for (int nz = 0; nz < cnvnDy.size(); ++nz)
        if (cnrvsGrid[ ny + cnvnDy[nz] ][ nx + cnvnDx[nz] ] == '#')
          ++nBlackCnt;

      if (nBlackCnt == 1 || nBlackCnt == 3)
        ++nPolygon;
    }

  return nPolygon;
}
  
int main()
{
  vector<string> vsGrid;

  input(vsGrid);
  cout << calcPolygon(vsGrid) << endl;

  return 0;
}
