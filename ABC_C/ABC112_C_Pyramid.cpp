#include <bits/stdc++.h>
using namespace std;

struct StCoord
{
  StCoord() : m_nx(0), m_ny(0), m_nHigh(0) { }

  int m_nx;
  int m_ny;
  int m_nHigh;
};

void input(vector<StCoord>& rvoCoord)
{
  int nCoordSiz;
  cin >> nCoordSiz;
  rvoCoord.resize(nCoordSiz);

  for (StCoord& roCoord : rvoCoord)
    cin >> roCoord.m_nx >> roCoord.m_ny >> roCoord.m_nHigh;
}

int calcCenterHigh(StCoord oCenter, StCoord oCoord)
{
  return  abs(oCenter.m_nx - oCoord.m_nx) 
        + abs(oCenter.m_ny - oCoord.m_ny) + oCoord.m_nHigh;
}

bool isCenter(StCoord& roCenter, const vector<StCoord>& cnrvoCoord)
{
  int nCenterHigh = 0;

  for (int nz = 0; nz < cnrvoCoord.size(); ++nz)
    if ( cnrvoCoord[nz].m_nHigh )
      if ( !nCenterHigh )
        nCenterHigh = calcCenterHigh(roCenter, cnrvoCoord[nz]);
      else
        if (nCenterHigh != calcCenterHigh(roCenter, cnrvoCoord[nz]))
          return false;

  for (int nz = 0; nz < cnrvoCoord.size(); ++nz)
    if ( !cnrvoCoord[nz].m_nHigh )
      if (nCenterHigh <= calcCenterHigh(roCenter, cnrvoCoord[nz]));
      else
        return false;

  roCenter.m_nHigh = nCenterHigh;
  return true;
}

void calcCenterCoord(const vector<StCoord>& cnrvoCoord)
{
  StCoord oCenter;
  bool bCenter = false;
  oCenter.m_nx = -1;

  while ( !bCenter         &&
          ++oCenter.m_nx <= 100 )
  {
    oCenter.m_ny = -1;

    while ( !bCenter         &&
            ++oCenter.m_ny <= 100 )
      bCenter = isCenter(oCenter, cnrvoCoord);
  }
  if ( bCenter )  
    cout << oCenter.m_nx << " " << oCenter.m_ny << " " << oCenter.m_nHigh;
}
  
int main()
{
  vector<StCoord> voCoord;
  
  input(voCoord);
  calcCenterCoord(voCoord);

  return 0;
}
