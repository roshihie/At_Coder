#include <bits/stdc++.h>
using namespace std;

struct StQuery
{
  StQuery() : m_nOp(0), m_nP1(0), m_nP2(0) { }

  int m_nOp;
  int m_nP1;
  int m_nP2;
};

void input(vector<string>& rvsStr, vector<StQuery>& rvoQuery)
{
  int nStrSiz, nQuerySiz;
  string sWhole;
  cin >> nStrSiz >> sWhole >> nQuerySiz;

  rvsStr[0] = sWhole.substr(0, nStrSiz);
  rvsStr[1] = sWhole.substr(nStrSiz);

  rvoQuery.resize(nQuerySiz);

  for (StQuery& roQuery : rvoQuery)
  {
    cin >> roQuery.m_nOp >> roQuery.m_nP1 >> roQuery.m_nP2;
    --roQuery.m_nP1, --roQuery.m_nP2;
  }
}

void calcIndex(int& rnxv, int& rnxp, int nx1st, int m_nPn, int nStrSiz)
{
  if (m_nPn < nStrSiz)
  {
    rnxv = nx1st;
    rnxp = m_nPn;
  }
  else
  {
    rnxv = (nx1st + 1) % 2;
    rnxp = m_nPn - nStrSiz;
  }
}

string calcString(vector<string>& rvsStr, const vector<StQuery>& cnrvoQuery)
{
  int nx1st = 0;

  for (StQuery oQuery : cnrvoQuery)
    if (oQuery.m_nOp == 1)
    {
      int nxv1, nxv2, nxp1, nxp2;
      calcIndex(nxv1, nxp1, nx1st, oQuery.m_nP1, rvsStr[0].size() );
      calcIndex(nxv2, nxp2, nx1st, oQuery.m_nP2, rvsStr[0].size() );

      swap( rvsStr[nxv1][nxp1], rvsStr[nxv2][nxp2] );
    }
    else
      nx1st = (nx1st + 1) % 2;

  return rvsStr[nx1st] + rvsStr[(nx1st + 1) % 2];
}

int main()
{
  vector<string> vsStr(2);
  vector<StQuery> voQuery;

  input(vsStr, voQuery);
  cout << calcString(vsStr, voQuery) << endl;

  return 0;
}
