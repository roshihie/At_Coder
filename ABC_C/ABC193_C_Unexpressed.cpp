#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnNum)
{
  cin >> rnNum;
}
  
llong calcPowerNumCnt(llong nNum)
{
  unordered_set<llong> sePowerNum;
  
  for (llong nx = 2; nx * nx <= nNum; ++nx)
  {
    llong nPowerNum = nx * nx;

    while (nPowerNum <= nNum)
    {
      sePowerNum.insert(nPowerNum);
      nPowerNum *= nx;
    }
  }
  return nNum - sePowerNum.size();
}

int main()
{
  llong nNum;
  input(nNum);
  cout << calcPowerNumCnt(nNum) << endl;

  return 0;
}
