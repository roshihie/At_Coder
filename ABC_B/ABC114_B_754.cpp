#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsNumStr)
{
  cin >> rsNumStr;
}

int fnMinDiffChk(string sNumStr)
{
  const int cnnNum = 753;
  int nMinDiff = INT_MAX;

  for (int i = 0; i < sNumStr.size() - 2; i++)
  {
    int nNum = (sNumStr[i]     - '0') * 100 +
               (sNumStr[i + 1] - '0') * 10  +
               (sNumStr[i + 2] - '0');         // char → int 変換

    nMinDiff = min(nMinDiff, abs(nNum - cnnNum));
  }
  return nMinDiff;
}

int main()
{
  string sNumStr;

  fnInput(sNumStr);
  cout << fnMinDiffChk(sNumStr) << endl;

  return 0;
}
