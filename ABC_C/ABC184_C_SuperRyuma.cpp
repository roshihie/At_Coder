#include <bits/stdc++.h>
using namespace std;
using llong = long long;

struct StCoord
{
  StCoord() : m_nx(0), m_ny(0) {}
  StCoord(llong nx, llong ny) : m_nx(nx), m_ny(ny) {}

  bool operator==(const StCoord& cnroCrdOtr) const
  {
    return ( m_nx == cnroCrdOtr.m_nx && m_ny == cnroCrdOtr.m_ny );
  }

  llong m_nx;
  llong m_ny;
};

struct StDist
{
  StDist() : m_nDistx(0), m_nDisty(0), m_nDists(0) {}

  llong m_nDistx;
  llong m_nDisty;
  llong m_nDists;
};

void input(StCoord& roCrdBgn, StCoord& roCrdEnd)
{
  cin >> roCrdBgn.m_nx >> roCrdBgn.m_ny;
  cin >> roCrdEnd.m_nx >> roCrdEnd.m_ny;
}

StDist calcDist(StCoord oCrdOne, StCoord oCrdOtr)
{
  StDist oDist;

  oDist.m_nDistx = abs(oCrdOne.m_nx - oCrdOtr.m_nx);
  oDist.m_nDisty = abs(oCrdOne.m_ny - oCrdOtr.m_ny);
  oDist.m_nDists = oDist.m_nDistx + oDist.m_nDisty;

  return oDist;
}

int calcMinStepCnt(StCoord oCrdBgn, StCoord oCrdEnd)
{
  StDist oDist = calcDist(oCrdBgn, oCrdEnd);
 
  if (oCrdBgn == oCrdEnd)
    return 0;
  else if (oDist.m_nDists <= 3  ||
           oDist.m_nDistx == oDist.m_nDisty)
    return 1;
  else if (oDist.m_nDists % 2 == 0  ||
           oDist.m_nDists <= 6         )
    return 2;
 
  int nStepCnt;
  int nMinStepCnt = 3;

  for (int nx = -3; nx <= 3; ++nx)
    for (int ny = abs(nx) - 3; ny <= 3 - abs(nx); ++ny)
    {
      StCoord oCrdOtr(oCrdBgn.m_nx + nx, oCrdBgn.m_ny + ny);
      StDist oDistOtrEnd = calcDist(oCrdOtr, oCrdEnd);

      if (oDistOtrEnd.m_nDists <= 3  ||
          oDistOtrEnd.m_nDistx == oDistOtrEnd.m_nDisty)
        nStepCnt = 2;
      else
        nStepCnt = 3;

      nMinStepCnt = min(nMinStepCnt, nStepCnt);
    }

  return nMinStepCnt;
}

int main()
{
  StCoord oCrdBgn, oCrdEnd;
  input(oCrdBgn, oCrdEnd);
  cout << calcMinStepCnt(oCrdBgn, oCrdEnd) << endl;

  return 0;
}
