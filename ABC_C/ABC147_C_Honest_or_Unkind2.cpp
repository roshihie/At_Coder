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

  for (int nx = 0; nx < rvvoExpr.size(); ++nx)
  {
    int nAttrSiz;
    cin >> nAttrSiz;
    rvvoExpr[nx].resize(nAttrSiz);

    for (int ny = 0; ny < rvvoExpr[nx].size(); ++ny)
      cin >> rvvoExpr[nx][ny].m_nPerson >> rvvoExpr[nx][ny].m_nAttr;
  }
}
 
int isHonest(const vector<vector<StExpr>>& cnrvvoExpr, 
                  const vector<int>& cnrvnHonest, int nMan)
{
  if (cnrvnHonest[nMan])               // Honest
  {
    for (int ny = 0; ny < cnrvvoExpr[nMan].size(); ++ny)
      if (cnrvvoExpr[nMan][ny].m_nAttr  !=
          cnrvnHonest[ cnrvvoExpr[nMan][ny].m_nPerson - 1 ] )
        return 0;

    return 1;
  }
  else                                 // UnKind
  {
    for (int ny = 0; ny < cnrvvoExpr[nMan].size(); ++ny)
      if (cnrvvoExpr[nMan][ny].m_nAttr  !=
          cnrvnHonest[ cnrvvoExpr[nMan][ny].m_nPerson - 1 ] )
        return 1;

    return 0;
  }
}
  
int calcMaxHonest(const vector<vector<StExpr>>& cnrvvoExpr)
{
  vector<int> vnHonest(cnrvvoExpr.size());
  int nMaxHonestCnt = 0;
  
  for (int nCtl = 0; nCtl < ( 1 << cnrvvoExpr.size() ); ++nCtl)
  {
    int nHonestCnt = 0;

    for (int nEach = 0; nEach < cnrvvoExpr.size() ; ++nEach)
      if (nCtl & ( 1 << nEach ))
      {
        vnHonest[nEach] = 1;            // Honest
        ++nHonestCnt;
      }
      else
        vnHonest[nEach] = 0;            // UnKind

    bool bReslt = true;

    for (int nMan = 0; nMan < vnHonest.size(); ++nMan)
      if (!isHonest(cnrvvoExpr, vnHonest, nMan))
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

  input(vvoExpr);
  cout << calcMaxHonest(vvoExpr) << endl;

  return 0;
}
