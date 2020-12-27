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
    for (int nj = 0; nj < cnrvoCoord.size(); ++nj)
      if (ni != nj)
      {
        double nSlope_nij = (double)(cnrvoCoord[nj].m_ny - cnrvoCoord[ni].m_ny)
                                  / (cnrvoCoord[nj].m_nx - cnrvoCoord[ni].m_nx);

        for (int nk = 0; nk < cnrvoCoord.size(); ++nk)
        {
          if (nk != ni  &&  nk != nj)
          {
            double nSlope_nik = (double)(cnrvoCoord[nk].m_ny - cnrvoCoord[ni].m_ny)
                                      / (cnrvoCoord[nk].m_nx - cnrvoCoord[ni].m_nx);
                                      
            if (nSlope_nij == nSlope_nik)
              return "Yes";
          }
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
