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

double calcDist(int nFrom, int nTo, const vector<StCoord>& cnrvoCoord)
{
  int nDistx = cnrvoCoord[nFrom].m_nx - cnrvoCoord[nTo].m_nx;
  int nDisty = cnrvoCoord[nFrom].m_ny - cnrvoCoord[nTo].m_ny;

  return sqrt(nDistx * nDistx + nDisty * nDisty);
}

double calcAverageDist(const vector<StCoord>& cnrvoCoord)
{
  double nTotalDist = 0.0;
  int nTotalCnt = 0;

  vector<int> vnCity;

  for (int ni = 0; ni < cnrvoCoord.size(); ++ni)
    vnCity.push_back( ni );

  do {
    for (int ni = 0; ni < cnrvoCoord.size() - 1; ++ni)
      nTotalDist += calcDist(vnCity[ni], vnCity[ni + 1], cnrvoCoord);

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
