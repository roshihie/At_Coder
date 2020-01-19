#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnNum)
{
  for (int& rnElm : rvnNum)
    cin >> rnElm;
}

int fnSameIntTimes(const vector<int>& cnrvnNum)
{
  auto itMaxNum = max_element(begin(cnrvnNum), end(cnrvnNum));

  int  nSum = 0;
  for (int nElm : cnrvnNum)
    nSum += nElm;

  int nSameIntTimes;
  if (*itMaxNum * 3 % 2 == nSum % 2)               // ３数の最大値×３と３数の和のパリティが等しい
    nSameIntTimes = (*itMaxNum * 3 - nSum) / 2;      // ３数の最大値 ← ３数が等しくなる数
  else                                             //  上記以外
    nSameIntTimes = ((*itMaxNum + 1) * 3 - nSum) / 2;// ３数の最大値＋１ ← ３数の等しくなる数

  return nSameIntTimes;
}

int main()
{
  vector<int> vnNum(3);

  fnInput(vnNum);
  cout << fnSameIntTimes(vnNum) << endl;

  return 0;
}
