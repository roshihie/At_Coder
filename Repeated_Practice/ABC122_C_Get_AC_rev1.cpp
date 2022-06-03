#include <bits/stdc++.h>
using namespace std;

struct StQuery
{
  StQuery() : m_nLeft(0), m_nRigt(0) { }

  int m_nLeft;
  int m_nRigt;
};

void fnInput(string& rsStr, vector<StQuery>& rvoQuery)
{
  int nStrSiz, nQuerySiz;
  cin >> nStrSiz >> nQuerySiz;
  rvoQuery.resize(nQuerySiz);

  cin >> rsStr;
  
  for (StQuery& roQuery : rvoQuery)
    cin >> roQuery.m_nLeft >> roQuery.m_nRigt;
}

void fnSubStrACCnt(string sStr, const vector<StQuery>& cnrvoQuery)
{
  vector<int> vnCumlSum(sStr.size() + 1);
  //vnCumlSum 0 1 2 3 4 5 6 7 8
  //sStr_pos   1 2 3 4 5 6 7 8
  //sStr       A C A C T A C G
  //sStr_ix    0 1 2 3 4 5 6 7
  for (int i = 1; i < vnCumlSum.size(); i++)
  {
    vnCumlSum[i + 1] = vnCumlSum[i];
    if (sStr[i - 1] == 'A' && sStr[i] == 'C') vnCumlSum[i + 1]++;
  }
  for (int i = 0; i < cnrvoQuery.size(); i++)
    cout << vnCumlSum[ cnrvoQuery[i].m_nRigt ] - vnCumlSum[ cnrvoQuery[i].m_nLeft ] << endl;
}
 
int main()
{
  string sStr;
  vector<StQuery> voQuery;

  fnInput(sStr, voQuery);
  fnSubStrACCnt(sStr, voQuery);

  return 0;
}
