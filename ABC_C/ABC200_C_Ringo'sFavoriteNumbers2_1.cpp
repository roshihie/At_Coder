#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<int>& rvNum)
{
  int sizNum;
  cin >> sizNum;
  rvNum.resize(sizNum);

  for (int& rNum : rvNum)
    cin >> rNum;
}

llong calc200MultCnt(const vector<int>& crvNum)
{
  llong cnt200Mult = 0;
  vector<int> vRem(200);

  for (int num : crvNum)
    ++vRem[ num % 200 ];

  for (int nRem : vRem)
    cnt200Mult += (llong)nRem * (nRem - 1) / 2;

  return cnt200Mult;
}

int main()
{
  vector<int> vNum;

  input(vNum);
  cout << calc200MultCnt(vNum) << endl;

  return 0;
}
