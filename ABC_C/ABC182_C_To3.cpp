#include <bits/stdc++.h>
using namespace std;

struct StCoord
{
  StCoord() : m_nx(0), m_ny(0) { }

  int m_nx;
  int m_ny;
};

void input(vector<StCoord>& rvoCoord)
{
  int nCoordSiz;
  cin >> nCoordSiz;
  rvoCoord.resize(nCoordSiz);

  for (StCoord& roCoord : rvoCoord)
    cin >> roCoord.m_nx >> roCoord.m_ny;
}

string isCollinearity(const vector<StCoord> cnrvoCoord)
{
  for (int ni = 0; ni < cnrvoCoord.size(); ++ni)
    for (int nj = ni + 1; nj < cnrvoCoord.size(); ++nj)
    {
      double nSlope_nij;

      if (cnrvoCoord[ni].m_nx == cnrvoCoord[nj].m_nx)
        nSlope_nij = DBL_MAX;
      else
        nSlope_nij = (double)(cnrvoCoord[nj].m_ny - cnrvoCoord[ni].m_ny)
                           / (cnrvoCoord[nj].m_nx - cnrvoCoord[ni].m_nx);

      for (int nk = nj + 1; nk < cnrvoCoord.size(); ++nk)
      {
        double nSlope_njk;

        if (cnrvoCoord[nk].m_nx == cnrvoCoord[nj].m_nx)
          nSlope_njk = DBL_MAX;
        else
          nSlope_njk = (double)(cnrvoCoord[nk].m_ny - cnrvoCoord[nj].m_ny)
                             / (cnrvoCoord[nk].m_nx - cnrvoCoord[nj].m_nx);
                                      
        if (nSlope_nij == nSlope_njk)
          return "Yes";
      }
    }

  return "No";
}

int main()
{
  vector<StCoord> voCoord;

  input(voCoord);
  cout << isCollinearity(voCoord) << endl;

  return 0;
}
