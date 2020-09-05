#include <bits/stdc++.h>
using namespace std;

struct StCoord
{
  StCoord() :
    m_ny(0), m_nx(0)
  { }

  int  m_ny;
  int  m_nx;
};

void input(StCoord& roCoord_S, StCoord& roCoord_G, vector<string>& rvsBoard)
{
  int nHigh, nWide;
  cin >> nHigh >> nWide;

  rvsBoard.resize(nHigh);

  cin >> roCoord_S.m_ny >> roCoord_S.m_nx;
  roCoord_S.m_ny--; roCoord_S.m_nx--;

  cin >> roCoord_G.m_ny >> roCoord_G.m_nx;
  roCoord_G.m_ny--; roCoord_G.m_nx--;

  for (int ny = 0; ny < nHigh; ny++)
    cin >> rvsBoard[ny];
}

int isReach(StCoord oNxtCrd, const vector<string>& cnrvsBoard, const vector<vector<int>>& cnrvvnDis)
{
  if      (oNxtCrd.m_ny < 0 || 
           oNxtCrd.m_ny >= cnrvsBoard.size())               return 0;
  else if (oNxtCrd.m_nx < 0 ||
           oNxtCrd.m_nx >= cnrvsBoard[oNxtCrd.m_ny].size()) return 0;
  else if (cnrvvnDis[oNxtCrd.m_ny][oNxtCrd.m_nx])           return 0;
  else if (cnrvsBoard[oNxtCrd.m_ny][oNxtCrd.m_nx] == '#')   return 0;
  else                                                      return 1;
}

int bfs(queue<StCoord>& rqoCoord ,   const vector<string>& cnrvsBoard, 
               vector<vector<int>> rvvnDis, StCoord oCoord_G)
{
  const vector<int> cnvnDy = {0, -1,  0, 1};
  const vector<int> cnvnDx = {1,  0, -1, 0};

  while (rqoCoord.size())
  {
    StCoord oCoord = rqoCoord.front(); rqoCoord.pop();

    if (oCoord.m_ny == oCoord_G.m_ny &&
        oCoord.m_nx == oCoord_G.m_nx   ) return rvvnDis[oCoord.m_ny][oCoord.m_nx];

    for (int n = 0; n < cnvnDy.size(); n++)
    {
      StCoord oNxtCrd;
      oNxtCrd.m_ny = oCoord.m_ny + cnvnDy[n];
      oNxtCrd.m_nx = oCoord.m_nx + cnvnDx[n];

      if (isReach(oNxtCrd, cnrvsBoard, rvvnDis))
      { 
        rvvnDis[oNxtCrd.m_ny][oNxtCrd.m_nx] = rvvnDis[oCoord.m_ny][oCoord.m_nx] + 1;
        rqoCoord.push(oNxtCrd);
      }
    }
  }
  return 0;
}

void bfsCntl(StCoord oCoord_S, StCoord oCoord_G, const vector<string>& cnrvsBoard)
{
  queue<StCoord> qoCoord;
  vector<vector<int>> vvnDis(cnrvsBoard.size(), vector<int>(cnrvsBoard[0].size()));

  qoCoord.push(oCoord_S);
  cout << bfs(qoCoord, cnrvsBoard, vvnDis, oCoord_G) << endl;
}

int main()
{
  StCoord oCoord_S, oCoord_G;
  vector<string> vsBoard;

  input(oCoord_S, oCoord_G, vsBoard);
  bfsCntl(oCoord_S, oCoord_G, vsBoard);

  return 0;
}
