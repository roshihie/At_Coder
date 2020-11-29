#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<string>& rvsBoard)
{
  int nHigh, nWide;
  cin >> nHigh >> nWide;

  rvsBoard.resize(nHigh);
  for (int ny = 0; ny < nHigh; ++ny)
    cin >> rvsBoard[ny];
}

int fnDfs(int ny, int nx, const vector<string>& cnrvsBoard, vector<vector<bool>>& rvvbReached)
{
  const vector<int> cnvnDy = {0, -1,  0, 1};
  const vector<int> cnvnDx = {1,  0, -1, 0};

  if (ny < 0  || ny >= cnrvsBoard.size())     return 0;
  if (nx < 0  || nx >= cnrvsBoard[ny].size()) return 0;

  if (rvvbReached[ny][nx])       return 0;
  if (cnrvsBoard[ny][nx] == '#') return 0;
  if (cnrvsBoard[ny][nx] == 'g') return 1;

  rvvbReached[ny][nx] = true;

  for (int ni = 0; ni < cnvnDy.size(); ++ni)
  {
    if (fnDfs(ny + cnvnDy[ni], nx + cnvnDx[ni], cnrvsBoard, rvvbReached))
      return 1;
    else;
  }
  return 0;
}

void fnFfsCntl(const vector<string>& cnrvsBoard)
{
  vector<vector<bool>> vvbReached(cnrvsBoard.size(), vector<bool>(cnrvsBoard[0].size()));
  bool bFind_s = false;

  int ny, nx;
  for (ny = 0; ny < cnrvsBoard.size(); ++ny)
  {
    for (nx = 0; nx < cnrvsBoard[ny].size(); ++nx)
      if (cnrvsBoard[ny][nx] == 's')
      {
        bFind_s = true;
        break;
      }
    if (bFind_s)  break;
  }

  if (fnDfs(ny, nx, cnrvsBoard, vvbReached))
    cout << "Yes" << endl;
  else
    cout << "No"  << endl;
}

void fnResult(const vector<string>& cnrvsBoard)
{
  for (string sBoard : cnrvsBoard)
    cout << sBoard << endl;
}

int main()
{
  vector<string> vsBoard;

  fnInput(vsBoard);
  fnFfsCntl(vsBoard);

  return 0;
}
