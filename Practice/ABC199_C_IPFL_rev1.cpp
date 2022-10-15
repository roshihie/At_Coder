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
  int strSiz;
  string str;
  cin >> strSiz >> str;
  rvStr[0] = str.substr(0, strSiz);
  rvStr[1] = str.substr(strSiz);

  int querySiz;
  cin >> querySiz;
  rvQuery.resize(querySiz);

  for (StQuery& roQuery : rvQuery)
    cin >> roQuery.m_op >> roQuery.m_pos1 >> roQuery.m_pos2;
}

void calcIndex(int& rstrnx, int& rstrpos, int halfSiz, int pos)
{
  if (pos < halfSiz)
  {
    rstrnx = 0;
    rstrpos = pos;
  }
  else
  {
    rstrnx = 1;
    rstrpos = pos - halfSiz;
  }
}

string calcString(vector<string>& rvStr, 
                  const vector<StQuery>& crvQuery)
{
  const int cHalfSiz = rvStr[0].size();

  for (StQuery oQuery : crvQuery)
    if (oQuery.m_op == 1)
    {
      int strnx1, strpos1, strnx2, strpos2;
      calcIndex(strnx1, strpos1, cHalfSiz, --oQuery.m_pos1);
      calcIndex(strnx2, strpos2, cHalfSiz, --oQuery.m_pos2);
      swap( rvStr[strnx1][strpos1], rvStr[strnx2][strpos2] );
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
