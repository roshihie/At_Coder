#include <bits/stdc++.h>
using namespace std;

struct StCoord
{
  StCoord() : m_nx(0), m_ny(0) { }

  int m_nx;
  int m_ny;
};

void fnInput(vector<StCoord>& rvoCoord)
{
  int nCrdSiz;
  cin >> nCrdSiz;
  rvoCoord.resize(nCrdSiz);

  for (StCoord& roCoord : rvoCoord)
    cin >> roCoord.m_nx >> roCoord.m_ny;
}

double fnAveDistGet(const vector<StCoord>& cnrvoCoord)
{
  vector<vector<double>> vvnDist(cnrvoCoord.size(), vector<double>(cnrvoCoord.size()));
  
  for (int i = 0; i < cnrvoCoord.size(); i++)
    for (int j = 0; j < cnrvoCoord.size(); j++)
      if (i != j)
        vvnDist[i][j] = vvnDist[j][i] =
          sqrt(pow(cnrvoCoord[i].m_nx - cnrvoCoord[j].m_nx, 2.0) +
               pow(cnrvoCoord[i].m_ny - cnrvoCoord[j].m_ny, 2.0)  );

  int nFact = 1;
  for (int n = 1; n < cnrvoCoord.size() + 1; n++)
    nFact *= n;

  double nTotalDist = 0.0;
  vector<int> vnCity(cnrvoCoord.size());
  iota(begin(vnCity), end(vnCity), 0);

  do {
    for (int i = 0; i < cnrvoCoord.size() - 1; i++)
      nTotalDist += vvnDist[ vnCity[i] ][ vnCity[i + 1] ];
  }
  while ( next_permutation(begin(vnCity), end(vnCity)) );

  return nTotalDist / nFact;
}

int main()
{
  vector<StCoord> voCoord;

  fnInput(voCoord);
  cout << fixed << setprecision(10) << fnAveDistGet(voCoord) << endl;

  return 0;
}
