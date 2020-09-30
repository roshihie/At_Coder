#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnFinCnt, vector<int>& rvnLifePnt)
{
  int nMonstr;
  cin >> nMonstr >> rnFinCnt;
  rvnLifePnt.resize(nMonstr);

  for (int& rnLifePnt : rvnLifePnt)
    cin >> rnLifePnt;

  sort(begin(rvnLifePnt), end(rvnLifePnt), greater<int>() );
}
  
llong calcMinAttackCnt(int nFinCnt, const vector<int>& cnrvnLifePnt)
{
  llong nMinAttackCnt = 0;

  for (int n = nFinCnt; n < cnrvnLifePnt.size(); n++)
    nMinAttackCnt += cnrvnLifePnt[n];

  return nMinAttackCnt;
}
  
int main()
{
  int nFinCnt;
  vector<int> vnLifePnt;

  input(nFinCnt, vnLifePnt);
  cout << calcMinAttackCnt(nFinCnt, vnLifePnt) << endl;

  return 0;
}
