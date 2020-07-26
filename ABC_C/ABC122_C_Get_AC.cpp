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
  vector<int> vnCumlSum(sStr.size() + 1);      // 累積和

  //累積和index 0 1 2 3 4 5 6 7 8
  //文字列位置   1 2 3 4 5 6 7 8
  //文字列       A C A C T A C G
  //文字列index  0 1 2 3 4 5 6 7
  for (int nBgn = 0; nBgn < vnCumlSum.size() - 1; nBgn++)
  {
    vnCumlSum[ nBgn + 2 ] = vnCumlSum[ nBgn + 1 ];
    if (sStr[nBgn] == 'A' && sStr[nBgn + 1] == 'C')
      vnCumlSum[ nBgn + 2 ]++;
  }

 for (int i = 0; i < cnrvoQuery.size(); i++)
  {
    cout << vnCumlSum[ cnrvoQuery[i].m_nRigt ] - vnCumlSum[ cnrvoQuery[i].m_nLeft ];
    cout << endl; 
  }
}
 
int main()
{
  string sStr;
  vector<StQuery> voQuery;

  fnInput(sStr, voQuery);
  fnSubStrACCnt(sStr, voQuery);

  return 0;
}
