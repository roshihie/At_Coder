#include <bits/stdc++.h>
using namespace std;

struct StQuery
{
  StQuery() : m_op(0), m_posL(0), m_posR(0)
  { }

  int m_op;
  int m_posL;
  int m_posR;
};

void input(vector<string>& rvStr, vector<StQuery>& rvQuery)
{
  int sizStr;
  string str;
  cin >> sizStr >> str;
  rvStr[0] = str.substr(0, sizStr);
  rvStr[1] = str.substr(sizStr);

  int sizQuery;
  cin >> sizQuery;
  rvQuery.resize(sizQuery);

  for (StQuery& roQuery : rvQuery)
  {
    cin >> roQuery.m_op >> roQuery.m_posL >> roQuery.m_posR;
    if (roQuery.m_op == 1) --roQuery.m_posL, --roQuery.m_posR;
  }
}

void calcIndex(int& rsnx, int& rspos, int sizHalf, int pos)
{
  if (pos < sizHalf)
  {
    rsnx = 0;
    rspos = pos;
  }
  else
  {
    rsnx = 1;
    rspos = pos - sizHalf;
  }
}

string moveString(vector<string>& rvStr, 
                  const vector<StQuery>& crvQuery)
{
  for (StQuery oQuery : crvQuery)
    if (oQuery.m_op == 1)
    {
      int snxL, sposL, snxR, sposR;
      calcIndex(snxL, sposL, rvStr[0].size(), oQuery.m_posL);
      calcIndex(snxR, sposR, rvStr[0].size(), oQuery.m_posR);
      swap( rvStr[snxL][sposL], rvStr[snxR][sposR] );
    }
    else
      swap( rvStr[0], rvStr[1] );

  return rvStr[0] + rvStr[1];
}

int main()
{
  vector<string> vStr(2);
  vector<StQuery> vQuery;

  input(vStr, vQuery);
  cout << moveString(vStr, vQuery) << endl;

  return 0;
}

