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

void calcIndex(int& rhstr, int& rhpos, int sizHalf, int pos)
{
  if (pos < sizHalf)
  {
    rhstr = 0;
    rhpos = pos;
  }
  else
  {
    rhstr = 1;
    rhpos = pos - sizHalf;
  }
}

string updtString(vector<string>& rvStr, 
                  const vector<StQuery>& crvQuery)
{
  for (StQuery oQuery : crvQuery)
    if (oQuery.m_op == 1)
    {
      int hstrL, hposL, hstrR, hposR;
      calcIndex(hstrL, hposL, rvStr[0].size(), oQuery.m_posL);
      calcIndex(hstrR, hposR, rvStr[1].size(), oQuery.m_posR);
      swap( rvStr[hstrL][hposL], rvStr[hstrR][hposR] );
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
  cout << updtString(vStr, vQuery) << endl;

  return 0;
}

