#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnNum)
{
  for (int& rnElm : rvnNum)
    cin >> rnElm;
}

int calcSameNumOpe(const vector<int>& cnrvnNum)
{
  auto itMaxNum = max_element(begin(cnrvnNum), end(cnrvnNum));
  int  nSum = 0;

  for (int nElm : cnrvnNum)
    nSum += nElm;

  int nSameNumTimes;
  if (*itMaxNum * 3 % 2 == nSum % 2)               // ３数の最大値×３と３数の和の偶奇が等しい
    nSameNumTimes = (*itMaxNum * 3 - nSum) / 2;      // ３数の最大値 ← ３数が等しくなる数
  else                                             //  上記以外
    nSameNumTimes = ((*itMaxNum + 1) * 3 - nSum) / 2;// ３数の最大値＋１ ← ３数の等しくなる数

  return nSameNumTimes;
}

int main()
{
  vector<int> vnNum(3);

  input(vnNum);
  cout << calcSameNumOpe(vnNum) << endl;

  return 0;
}
