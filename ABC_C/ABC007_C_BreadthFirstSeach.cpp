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

void input(StCoord& roStart, StCoord& roGoal, vector<string>& rvsBoard)
{
  int nHigh, nWide;
  cin >> nHigh >> nWide;

  rvsBoard.resize(nHigh);

  cin >> roStart.m_ny >> roStart.m_nx;
  --roStart.m_ny; --roStart.m_nx;

  cin >> roGoal.m_ny >> roGoal.m_nx;
  --roGoal.m_ny; --roGoal.m_nx;

  for (int ny = 0; ny < nHigh; ++ny)
    cin >> rvsBoard[ny];
}

int canReach(StCoord oNextCrd, 
             const vector<string>& cnrvsBoard, const vector<vector<int>>& cnrvvnDis)
{
  if      ( oNextCrd.m_ny < 0 || 
            oNextCrd.m_ny >= cnrvsBoard.size() )                return 0;
  else if ( oNextCrd.m_nx < 0 ||
            oNextCrd.m_nx >= cnrvsBoard[oNextCrd.m_ny].size() ) return 0;
  else if ( cnrvvnDis[oNextCrd.m_ny][oNextCrd.m_nx] )           return 0;
  else if ( cnrvsBoard[oNextCrd.m_ny][oNextCrd.m_nx] == '#' )   return 0;
  else                                                          return 1;
}

int bfs(queue<StCoord>& rqoCoord, const vector<string>& cnrvsBoard, 
        vector<vector<int>> rvvnDis, StCoord oGoal)
{
  const vector<int> cnvnDy = {0, -1,  0, 1};
  const vector<int> cnvnDx = {1,  0, -1, 0};

  while (rqoCoord.size())
  {
    StCoord oCurCrd = rqoCoord.front(); rqoCoord.pop();

    if (oCurCrd.m_ny == oGoal.m_ny &&
        oCurCrd.m_nx == oGoal.m_nx   ) return rvvnDis[oCurCrd.m_ny][oCurCrd.m_nx];

    for (int ni = 0; ni < cnvnDy.size(); ++ni)
    {
      StCoord oNextCrd;
      oNextCrd.m_ny = oCurCrd.m_ny + cnvnDy[ni];
      oNextCrd.m_nx = oCurCrd.m_nx + cnvnDx[ni];

      if (canReach(oNextCrd, cnrvsBoard, rvvnDis))
      { 
        rvvnDis[oNextCrd.m_ny][oNextCrd.m_nx] = rvvnDis[oCurCrd.m_ny][oCurCrd.m_nx] + 1;
        rqoCoord.push(oNextCrd);
      }
    }
  }
  return 0;
}

void bfsCntl(StCoord oStart, StCoord oGoal, const vector<string>& cnrvsBoard)
{
  queue<StCoord> qoCoord;
  vector<vector<int>> vvnDis(cnrvsBoard.size(), vector<int>(cnrvsBoard[0].size()));

  qoCoord.push(oStart);
  cout << bfs(qoCoord, cnrvsBoard, vvnDis, oGoal) << endl;
}

int main()
{
  StCoord oStart, oGoal;
  vector<string> vsBoard;

  input(oStart, oGoal, vsBoard);
  bfsCntl(oStart, oGoal, vsBoard);

  return 0;
}
