#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnLowNum, int& rnHighNum)
{
  cin >> rnLowNum >> rnHighNum;
}

void fnDigitGet(int nNum, vector<int>& rvnDigit)
{
  for (int n = rvnDigit.size() - 1; n >= 0; n--)
  {
    rvnDigit[n] = nNum % 10;
    nNum /= 10;
  }
}

int fnPalindromeCnt(int nLowNum, int nHighNum)
{
  int nPlindromeCnt = 0;
  vector<int> vnDigit(5);

  for (int nNum = nLowNum; nNum <= nHighNum; nNum++)
  {
    fnDigitGet(nNum, vnDigit);

    vector<int> vnRevDigit(vnDigit);
    reverse(begin(vnRevDigit), end(vnRevDigit));

    if (vnDigit == vnRevDigit)  nPlindromeCnt++;
  }
  return nPlindromeCnt;
}

int main()
{
  int nLowNum, nHighNum, nMinSum, nMaxSum;
  fnInput(nLowNum, nHighNum);

  cout << fnPalindromeCnt(nLowNum, nHighNum) << endl;
  return 0;
}
