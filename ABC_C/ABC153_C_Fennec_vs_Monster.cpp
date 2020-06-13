#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(int& rnMonster, int& rnFinCnt, vector<int>& rvnLifePnt)
{
  cin >> rnMonster >> rnFinCnt;
  rvnLifePnt.resize(rnMonster);

  for (int& rnLifePnt : rvnLifePnt)
    cin >> rnLifePnt;
}
  
llong fnGameOverCnt(int nFinCnt, vector<int>& rvnLifePnt)
{
  sort(begin(rvnLifePnt), end(rvnLifePnt), greater<int>());

  llong nGameOverCnt = 0;
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
