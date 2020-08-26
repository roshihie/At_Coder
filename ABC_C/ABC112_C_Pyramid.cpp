#include <bits/stdc++.h>
using namespace std;

struct StCoord
{
  StCoord() : m_nx(0), m_ny(0), m_nHigh(0) { }

  int m_nx;
  int m_ny;
  int m_nHigh;
};

void fnInput(vector<StCoord>& rvoCoord)
{
  int nCoordSiz;
  cin >> nCoordSiz;
  rvoCoord.resize(nCoordSiz);

  for (StCoord& roCoord : rvoCoord)
    cin >> roCoord.m_nx >> roCoord.m_ny >> roCoord.m_nHigh;
}

int fnCenterHigh(StCoord oCenter, StCoord oCoord)
{
  return  abs(oCenter.m_nx - oCoord.m_nx) 
        + abs(oCenter.m_ny - oCoord.m_ny) + oCoord.m_nHigh;
}

bool fnCenterCheck(StCoord& roCenter, const vector<StCoord>& cnrvoCoord)
{
  int nCenterHigh = 0;

  for (int i = 0; i < cnrvoCoord.size(); ++i)
    if ( cnrvoCoord[i].m_nHigh )
      if ( !nCenterHigh )
        nCenterHigh = fnCenterHigh(roCenter, cnrvoCoord[i]);
      else
        if (nCenterHigh != fnCenterHigh(roCenter, cnrvoCoord[i]))
          return false;

  for (int i = 0; i < cnrvoCoord.size(); ++i)
    if ( !cnrvoCoord[i].m_nHigh )
      if (nCenterHigh <= fnCenterHigh(roCenter, cnrvoCoord[i]));
      else
        return false;

  roCenter.m_nHigh = nCenterHigh;
  return true;
}

void fnCenterCoord(const vector<StCoord>& cnrvoCoord)
{
  StCoord oCenter;
  bool bCenter = false;
  oCenter.m_nx = -1;

  while ( !bCenter       &&
          oCenter.m_nx < 101 )
  {
    ++oCenter.m_nx;
    oCenter.m_ny = -1;

    while ( !bCenter       &&
            oCenter.m_ny < 101 )
    {
      ++oCenter.m_ny;
      bCenter = fnCenterCheck(oCenter, cnrvoCoord);
    }
  }
  if ( bCenter )  
    cout << oCenter.m_nx << " " << oCenter.m_ny << " " << oCenter.m_nHigh;
}
  
int main()
{
  vector<StCoord> voCoord;
  
  fnInput(voCoord);
  fnCenterCoord(voCoord);

  return 0;
}
