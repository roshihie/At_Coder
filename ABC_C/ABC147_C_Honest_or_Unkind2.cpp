#include <bits/stdc++.h>
using namespace std;

struct StExpr
{
  StExpr() : m_nPerson(0), m_nAttr(0) { }

  int m_nPerson;
  int m_nAttr;
};

void fnInput(vector<vector<StExpr>>& rvvoExpr)
{
  int nPersonSiz;
  cin >> nPersonSiz;
  rvvoExpr.resize(nPersonSiz);

  for (int i = 0; i < rvvoExpr.size(); i++)
  {
    int nAttrSiz;
    cin >> nAttrSiz;
    rvvoExpr[i].resize(nAttrSiz);

    for (int j = 0; j < rvvoExpr[i].size(); j++)
      cin >> rvvoExpr[i][j].m_nPerson >> rvvoExpr[i][j].m_nAttr;
  }
}
 
int fnHonestCheck(const vector<vector<StExpr>>& cnrvvoExpr, 
                  const vector<int>& cnrvnHonest, int nMan)
{
  if (cnrvnHonest[nMan])               // Honest
  {
    for (int j = 0; j < cnrvvoExpr[nMan].size(); j++)
      if (cnrvvoExpr[nMan][j].m_nAttr  !=
          cnrvnHonest[ cnrvvoExpr[nMan][j].m_nPerson - 1 ] )
        return 0;

    return 1;
  }
  else                                 // UnKind
  {
    for (int j = 0; j < cnrvvoExpr[nMan].size(); j++)
      if (cnrvvoExpr[nMan][j].m_nAttr  !=
          cnrvnHonest[ cnrvvoExpr[nMan][j].m_nPerson - 1 ] )
        return 1;

    return 0;
  }
}
  
int fnMaxHonestGet(const vector<vector<StExpr>>& cnrvvoExpr)
{
  vector<int> vnHonest(cnrvvoExpr.size());
  int nMaxHonestCnt = 0;
  
  for (int nCtl = 0; nCtl < ( 1 << cnrvvoExpr.size() ); nCtl++)
  {
    int nHonestCnt = 0;

    for (int nEach = 0; nEach < cnrvvoExpr.size() ; nEach++)
      if (nCtl & ( 1 << nEach ))
      {
        vnHonest[nEach] = 1;            // Honest
        nHonestCnt++;
      }
      else
        vnHonest[nEach] = 0;            // UnKind

    bool bReslt = true;

    for (int nMan = 0; nMan < vnHonest.size(); nMan++)
      if (!fnHonestCheck(cnrvvoExpr, vnHonest, nMan))
      {
        bReslt = false;
        break;
      }

    if (bReslt) nMaxHonestCnt = max(nMaxHonestCnt, nHonestCnt);
  }
  return nMaxHonestCnt;
}

int main()
{
  vector<vector<StExpr>> vvoExpr;

  fnInput(vvoExpr);
  cout << fnMaxHonestGet(vvoExpr) << endl;

  return 0;
}
