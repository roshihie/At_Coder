#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnMonster, int& rnFinCnt, vector<int>& rvnLifePnt)
{
  cin >> rnMonster >> rnFinCnt;
  rvnLifePnt.resize(rnMonster);

  for(int& rnLifePnt : rvnLifePnt)
    cin >> rnLifePnt;
}
  
int64_t fnGameOverCnt(int nFinCnt, vector<int>& rvnLifePnt)
{
  sort(begin(rvnLifePnt), end(rvnLifePnt), greater<int>());

  int64_t nGameOverCnt = 0;
  for (int n = nFinCnt; n < rvnLifePnt.size(); n++)
    nGameOverCnt += rvnLifePnt[n];

  return nGameOverCnt;
}
  
int main()
{
  int nMonstr, nFinCnt;
  vector<int> vnLifePnt;

  fnInput(nMonstr, nFinCnt, vnLifePnt);
  cout << fnGameOverCnt(nFinCnt, vnLifePnt) << endl;

  return 0;
}
