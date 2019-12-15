#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<string>& rvsGrid)
{
  int nHigh, nWide;
  cin >> nHigh >> nWide;

  rvsGrid.resize(nHigh);
  for (int ny = 0; ny < nHigh; ny++)
    cin >> rvsGrid[ny];
}

int fnRepaint(int ny, int nx, const vector<string>& cnrvsGrid)
{
  if (   ny >= 0  && ny < cnrvsGrid.size()
      && nx >= 0  && nx < cnrvsGrid[ny].size())
    if (cnrvsGrid[ny][nx] == '#')
      return 1;
    else;

  return 0;
}

int fnGridRepaint(const vector<string>& cnrvsGrid)
{
  const vector<int> cnvnDy = {-1,  0,  1,  0};
  const vector<int> cnvnDx = { 0, -1,  0,  1};

  for (int ny = 0; ny < cnrvsGrid.size(); ny++)
  {
    for (int nx = 0; nx < cnrvsGrid[ny].size(); nx++)
    {
      if (cnrvsGrid[ny][nx] == '#')
      {
        bool bRslt = false;
        for (int i = 0; i < cnvnDy.size(); i++)
        {
          if (fnRepaint(ny + cnvnDy[i], nx + cnvnDx[i], cnrvsGrid))
            bRslt = true;
        }
        if (!bRslt)  return 0;
      }
    }
  }
  return 1;
}

int main()
{
  vector<string> vsGrid;

  fnInput(vsGrid);
  if (fnGridRepaint(vsGrid))  cout << "Yes" << endl;
  else                        cout << "No"  << endl;

  return 0;
}
