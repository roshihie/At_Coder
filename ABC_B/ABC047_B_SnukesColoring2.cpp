#include <bits/stdc++.h>
using namespace std;

struct StCoord
{
  StCoord() : m_nx(0), m_ny(0), m_nOpe(0) { }

  int m_nx;
  int m_ny;
  int m_nOpe;
};

void fnInput(vector<StCoord>& rvoCoord, StCoord& roCrdEnd)
{
  int nCrdSiz;
  cin >> roCrdEnd.m_nx >> roCrdEnd.m_ny >> nCrdSiz;

  rvoCoord.resize(nCrdSiz);
  for (StCoord& roCoord : rvoCoord)
    cin >> roCoord.m_nx >> roCoord.m_ny >> roCoord.m_nOpe;
}

int fnRectPaint(const vector<StCoord>& cnrvoCoord,
                 StCoord& roCrdBgn, StCoord& roCrdEnd)
{
  for (StCoord oCoord : cnrvoCoord)
    if      (oCoord.m_nOpe == 1)  roCrdBgn.m_nx = max(roCrdBgn.m_nx, oCoord.m_nx);
    else if (oCoord.m_nOpe == 2)  roCrdEnd.m_nx = min(roCrdEnd.m_nx, oCoord.m_nx);
    else if (oCoord.m_nOpe == 3)  roCrdBgn.m_ny = max(roCrdBgn.m_ny, oCoord.m_ny);
    else if (oCoord.m_nOpe == 4)  roCrdEnd.m_ny = min(roCrdEnd.m_ny, oCoord.m_ny);

  if (roCrdBgn.m_nx >= roCrdEnd.m_nx ||
      roCrdBgn.m_ny >= roCrdEnd.m_ny   )
    return 0;
  else
    return (roCrdEnd.m_nx - roCrdBgn.m_nx) * (roCrdEnd.m_ny - roCrdBgn.m_ny);
}

int main()
{
  vector<StCoord> voCoord;
  StCoord oCrdBgn, oCrdEnd;

  fnInput(voCoord, oCrdEnd);
  cout << fnRectPaint(voCoord, oCrdBgn, oCrdEnd) << endl;

  return 0;
}
