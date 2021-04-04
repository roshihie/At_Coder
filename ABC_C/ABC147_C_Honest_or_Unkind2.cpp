#include <bits/stdc++.h>
using namespace std;

struct StExpr
{
  StExpr() : m_nPerson(0), m_nAttr(0) { }

  int m_nPerson;
  int m_nAttr;
};

void input(vector<vector<StExpr>>& rvvoExpr)
{
  int nPersonSiz;
  cin >> nPersonSiz;
  rvvoExpr.resize(nPersonSiz);

  for (int ny = 0; ny < rvvoExpr.size(); ++ny)
  {
    int nAttrSiz;
    cin >> nAttrSiz;
    rvvoExpr[ny].resize(nAttrSiz);

    for (int nx = 0; nx < rvvoExpr[ny].size(); ++nx)
      cin >> rvvoExpr[ny][nx].m_nPerson >> rvvoExpr[ny][nx].m_nAttr;
  }
}
 
int isHonest(const vector<vector<StExpr>>& cnrvvoExpr, 
             const vector<int>& cnrvnHonest, int nMan)
{
  if (cnrvnHonest[nMan])               // Honest
  {
    for (int nx = 0; nx < cnrvvoExpr[nMan].size(); ++nx)
      if (cnrvvoExpr[nMan][nx].m_nAttr  ==
          cnrvnHonest[ cnrvvoExpr[nMan][nx].m_nPerson - 1 ] );
      else
        return 0;

    return 1;
  }
  else                                 // UnKind
  {
    for (int nx = 0; nx < cnrvvoExpr[nMan].size(); ++nx)
      if (cnrvvoExpr[nMan][nx].m_nAttr  !=
          cnrvnHonest[ cnrvvoExpr[nMan][nx].m_nPerson - 1 ] );
        return 1;

    return 0;
  }
}
  
int calcMaxHonest(const vector<vector<StExpr>>& cnrvvoExpr)
{
  vector<int> vnHonest(cnrvvoExpr.size());
  int nMaxHonestCnt = 0;
  
  for (int nBit = 0; nBit < ( 1 << vnHonest.size() ); ++nBit)
  {
    int nHonestCnt = 0;

    for (int nEach = 0; nEach < vnHonest.size() ; ++nEach)
      if (nBit & ( 1 << nEach ))
      {
        vnHonest[nEach] = 1;           // Honest
        ++nHonestCnt;
      }
      else
        vnHonest[nEach] = 0;           // UnKind

    bool bRslt = true;

    for (int nMan = 0; nMan < vnHonest.size(); ++nMan)
      if ( !isHonest(cnrvvoExpr, vnHonest, nMan) )
      {
        bRslt = false;
        break;
      }

    if (bRslt) nMaxHonestCnt = max(nMaxHonestCnt, nHonestCnt);
  }
  return nMaxHonestCnt;
}

int main()
{
  vector<vector<StExpr>> vvoExpr;

  input(vvoExpr);
  cout << calcMaxHonest(vvoExpr) << endl;

  return 0;
}
