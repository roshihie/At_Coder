#include <bits/stdc++.h>
using namespace std;

void input(vector<string>& rvsGrid)
{
  int nHigh, nWide;
  cin >> nHigh >> nWide;

  rvsGrid.resize(nHigh);
  for (int ny = 0; ny < nHigh; ++ny)
    cin >> rvsGrid[ny];
}

int repaintCell(int ny, int nx, const vector<string>& cnrvsGrid)
{
  if (   ny >= 0  && ny < cnrvsGrid.size()
      && nx >= 0  && nx < cnrvsGrid[ny].size())
    if (cnrvsGrid[ny][nx] == '#')
      return 1;
    else;

  return 0;
}

int canAchive(const vector<string>& cnrvsGrid)
{
  const vector<int> cnvnDy = {-1,  0,  1,  0};
  const vector<int> cnvnDx = { 0, -1,  0,  1};

  for (int ny = 0; ny < cnrvsGrid.size(); ++ny)
    for (int nx = 0; nx < cnrvsGrid[ny].size(); ++nx)
      if (cnrvsGrid[ny][nx] == '#')
      {
        bool bReslt = false;
        for (int ni = 0; ni < cnvnDy.size(); ++ni)
          if (repaintCell(ny + cnvnDy[ni], nx + cnvnDx[ni], cnrvsGrid))
            bReslt = true;

        if (!bReslt)  return 0;
      }

  return 1;
}

int main()
{
  vector<string> vsGrid;

  input(vsGrid);
  if (canAchive(vsGrid))  cout << "Yes" << endl;
  else                        cout << "No"  << endl;

  return 0;
}
