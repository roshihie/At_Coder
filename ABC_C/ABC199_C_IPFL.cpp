#include <bits/stdc++.h>
using namespace std;

struct StQuery
{
  StQuery() : m_op(0), m_pos1(0), m_pos2(0)
  { }

  int m_op;
  int m_pos1;
  int m_pos2;
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
    cin >> roQuery.m_op >> roQuery.m_pos1 >> roQuery.m_pos2;
    if (roQuery.m_op == 1) --roQuery.m_pos1, --roQuery.m_pos2;
  }
}

void calcIndex(int& rsnx, int& rspos, int halfSiz, int pos)
{
  if (pos < halfSiz)
  {
    rsnx = 0;
    rspos = pos;
  }
  else
  {
    rsnx = 1;
    rspos = pos - halfSiz;
  }
}

string calcString(vector<string>& rvStr, 
                  const vector<StQuery>& crvQuery)
{
  for (StQuery oQuery : crvQuery)
    if (oQuery.m_op == 1)
    {
      int snx1, spos1, snx2, spos2;
      calcIndex(snx1, spos1, rvStr[0].size(), oQuery.m_pos1);
      calcIndex(snx2, spos2, rvStr[0].size(), oQuery.m_pos2);
      swap( rvStr[snx1][spos1], rvStr[snx2][spos2] );
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
  cout << calcString(vStr, vQuery) << endl;

  return 0;
}
