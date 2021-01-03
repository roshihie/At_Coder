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
  int nCrdSiz;
  cin >> nCrdSiz;
  rvoCoord.resize(nCrdSiz);

  for (StCoord& roCoord : rvoCoord)
    cin >> roCoord.m_nx >> roCoord.m_ny;
}

double calcAverageDist(const vector<StCoord>& cnrvoCoord)
{
  vector<vector<double>> vvnDist(cnrvoCoord.size(), vector<double>(cnrvoCoord.size()));
  
  for (int ni = 0; ni < cnrvoCoord.size(); ++ni)
    for (int nj = 0; nj < cnrvoCoord.size(); ++nj)
      if (ni != nj)
      {
        int nDistx = cnrvoCoord[ni].m_nx - cnrvoCoord[nj].m_nx;
        int nDisty = cnrvoCoord[ni].m_ny - cnrvoCoord[nj].m_ny;
        vvnDist[ni][nj] = vvnDist[nj][ni] = sqrt(nDistx * nDistx + nDisty * nDisty);
      }

  double nTotalDist = 0.0;
  int nTotalCnt = 0;

  vector<int> vnCity;

  for (int ni = 0; ni < cnrvoCoord.size(); ++ni)
    vnCity.push_back( ni );

  do {
    for (int ni = 0; ni < cnrvoCoord.size() - 1; ++ni)
      nTotalDist += vvnDist[ vnCity[ni] ][ vnCity[ni + 1] ];

    ++nTotalCnt;
  }
  while ( next_permutation(begin(vnCity), end(vnCity)) );

  return nTotalDist / nTotalCnt;
}

int main()
{
  vector<StCoord> voCoord;

  input(voCoord);
  cout << fixed << setprecision(10) << calcAverageDist(voCoord) << endl;

  return 0;
}
