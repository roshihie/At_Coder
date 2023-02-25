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

                       // 累積和 vector 要素No：1＝1st要素
  for (int nx = 1; nx <= sizSeq; ++nx)
  {
    int each;
    cin >> each;
    rvSeq[nx] = rvSeq[nx - 1] + each;
  }

  for (StQuery& rQuery : rvQuery)
    cin >> rQuery.m_left >> rQuery.m_right;
}

void calcQuery(const vector<int>& crvSeq,
               const vector<StQuery>& crvQuery)
{
  for (StQuery oQuery : crvQuery)
    cout << crvSeq[ oQuery.m_right ] - crvSeq[ oQuery.m_left - 1 ] << endl;

  return;
}

int main()
{
  vector<int> vSeq;
  vector<StQuery> vQuery;

  input(vSeq, vQuery);
  calcQuery(vSeq, vQuery);;

  return 0;
}
