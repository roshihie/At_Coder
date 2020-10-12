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
  
  for (int nx = 0; nx < cnrvoCoord.size(); ++nx)
    for (int ny = 0; ny < cnrvoCoord.size(); ++ny)
      if (nx != ny)
      {
        int nDistx = cnrvoCoord[nx].m_nx - cnrvoCoord[ny].m_nx;
        int nDisty = cnrvoCoord[nx].m_ny - cnrvoCoord[ny].m_ny;
        vvnDist[nx][ny] = vvnDist[ny][nx] = sqrt(nDistx * nDistx + nDisty * nDisty);
      }

  double nTotalDist = 0.0;
  int nTotalCnt = 0;

  vector<int> vnCity(cnrvoCoord.size());
  iota(begin(vnCity), end(vnCity), 0);

  do {
    for (int nx = 0; nx < cnrvoCoord.size() - 1; ++nx)
      nTotalDist += vvnDist[ vnCity[nx] ][ vnCity[nx + 1] ];
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
