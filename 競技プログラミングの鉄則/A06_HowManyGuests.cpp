#include <bits/stdc++.h>
using namespace std;

struct StQuery
{
  StQuery() : m_left(0), m_right(0) { }

  int m_left;          // Left 日 1-origin
  int m_right;         // Right日 1-origin
};

void input(vector<int>& rvSeq, 
           vector<StQuery>& rvQuery)
{
  int sizSeq, sizQuery;
  cin >> sizSeq >> sizQuery;
  rvSeq.resize(sizSeq + 1);
  rvQuery.resize(sizQuery);
                       // 日      1 2 … N
                       // 要素# 0 1 2 … N
  for (int nx = 1; nx <= sizSeq; ++nx)
    cin >> rvSeq[nx];

  for (StQuery& rQuery : rvQuery)
    cin >> rQuery.m_left >> rQuery.m_right;
}

void calcSumDays(const vector<int>& crvSeq,
                 const vector<StQuery>& crvQuery)
{
                       // 日      1 2 … N
                       // 要素# 0 1 2 … N
  vector<int> vCumSum(crvSeq.size() + 1);

  for (int nx = 1; nx < vCumSum.size(); ++nx)
    vCumSum[nx] += vCumSum[nx - 1] + crvSeq[nx];

  for (StQuery oQuery : crvQuery)
    cout << vCumSum[ oQuery.m_right ] - vCumSum[ oQuery.m_left - 1 ] << endl;

  return;
}

int main()
{
  vector<int> vSeq;
  vector<StQuery> vQuery;

  input(vSeq, vQuery);
  calcSumDays(vSeq, vQuery);

  return 0;
}
