#include <bits/stdc++.h>
using namespace std;
using llong = long long;

struct StGrid
{
  StGrid() : m_x(0), m_y(0) {}
  StGrid(llong nx, llong ny) : m_x(nx), m_y(ny) {}

  bool operator==(const StGrid& croGridOtr) const
  {
    return ( m_x == croGridOtr.m_x && m_y == croGridOtr.m_y );
  }

  llong m_x;
  llong m_y;
};

struct StDist
{
  StDist() : m_distx(0), m_disty(0), m_dists(0) {}

  llong m_distx;
  llong m_disty;
  llong m_dists;
};

void input(StGrid& roGridBgn, StGrid& roGridEnd)
{
  cin >> roGridBgn.m_x >> roGridBgn.m_y;
  cin >> roGridEnd.m_x >> roGridEnd.m_y;
}

StDist calcDist(StGrid oGridOne, StGrid oGridOtr)
{
  StDist oDist;

  oDist.m_distx = abs(oGridOne.m_x - oGridOtr.m_x);
  oDist.m_disty = abs(oGridOne.m_y - oGridOtr.m_y);
  oDist.m_dists = oDist.m_distx + oDist.m_disty;

  return oDist;
}

int calcMinStepCnt(StGrid oGridBgn, StGrid oGridEnd)
{
  StDist oDist = calcDist(oGridBgn, oGridEnd);
 
  if (oGridBgn == oGridEnd)
    return 0;
  else if (oDist.m_dists <= 3LL  ||
           oDist.m_distx == oDist.m_disty)
    return 1;
  else if (oDist.m_dists % 2 == 0)
    return 2;
 
  int cntStep;

  for (int nx = -3; nx <= 3; ++nx)
    for (int ny = abs(nx) - 3; ny <= 3 - abs(nx); ++ny)
    {
      StGrid oGridOtr(oGridBgn.m_x + nx, oGridBgn.m_y + ny);
      StDist oDistOtrEnd = calcDist(oGridOtr, oGridEnd);

      if (oDistOtrEnd.m_dists <= 3LL  ||
          oDistOtrEnd.m_distx == oDistOtrEnd.m_disty)
        return 2;
    }

  return 3;
}

int main()
{
  StGrid oGridBgn, oGridEnd;
  input(oGridBgn, oGridEnd);
  cout << calcMinStepCnt(oGridBgn, oGridEnd) << endl;

  return 0;
}
