#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<string>& rvsBoard)
{
  int nHigh, nWide;
  cin >> nHigh >> nWide;

  rvsBoard.resize(nHigh);
  for (int ny = 0; ny < nHigh; ny++)
    cin >> rvsBoard[ny];
}

int fnCountBomb(int ny, int nx, const vector<string>& cnrvsBoard)
{
  if (   ny >= 0  && ny < cnrvsBoard.size()
      && nx >= 0  && nx < cnrvsBoard[ny].size())
    if (cnrvsBoard[ny][nx] == '#')  return 1;
    else;

  return 0;
}

void fnMinesweeper(vector<string>& rvsBoard)
{
  const vector<int> cnvnDy = {-1, -1, -1,  0,  0,  1,  1,  1};
  const vector<int> cnvnDx = {-1,  0,  1, -1,  1, -1,  0,  1};
  for (int ny = 0; ny < rvsBoard.size(); ny++)
    for (int nx = 0; nx < rvsBoard[ny].size(); nx++)
      if (rvsBoard[ny][nx] == '.')
      {
        int nCount = 0;
        for (int i = 0; i < cnvnDy.size(); i++)
          nCount += fnCountBomb(ny + cnvnDy[i], nx + cnvnDx[i], rvsBoard);

        rvsBoard[ny][nx] = '0' + nCount;       // int → char 変換
      }
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
  fnMinesweeper(vsBoard);
  fnResult(vsBoard);

  return 0;
}
