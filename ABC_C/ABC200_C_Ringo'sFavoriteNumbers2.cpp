#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<int>& rvnNum)
{
  int nNumSiz;
  cin >> nNumSiz;
  rvnNum.resize(nNumSiz);

  for (int& rnNum : rvnNum)
    cin >> rnNum;
}

llong calc200MultplCnt(const vector<int>& cnrvnNum)
{
  llong n200MultplCnt = 0;
  vector<int> vnRem(200);

  for (int nNum : cnrvnNum)
    ++vnRem[ nNum % 200 ];

  for (int nRem : vnRem)
    if (nRem > 1)
      n200MultplCnt += (llong)nRem * (nRem - 1) / 2;

  return n200MultplCnt;
}

int main()
{
  vector<int> vnNum;

  input(vnNum);
  cout << calc200MultplCnt(vnNum) << endl;

  return 0;
}
