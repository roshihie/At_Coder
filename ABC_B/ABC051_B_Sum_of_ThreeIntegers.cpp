#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnMaxNum, int& rnTrgNum)
{
  cin >> rnMaxNum >> rnTrgNum;
}

int fnCaseCount(int nMaxNum, int nTrgNum)
{
  int nAllDiff = 0;
  int nSameTwo = 0;
  int nAllSame = 0;

  for (int i = 0; i <= nMaxNum; i++)
    for (int j = 0; j <= i; j++)
    {
      int nRestNum = nTrgNum - (i + j);
      if (0 <= nRestNum && nRestNum <= j)
        if      (i == j && j == nRestNum)
          nAllSame++;
        else if (i == j || j == nRestNum || nRestNum == i)
          nSameTwo++;
        else
          nAllDiff++;
    }

  return (nAllDiff * 6 + nSameTwo * 3 + nAllSame);
}

int main()
{
  int nMaxNum, nTrgNum;

  fnInput(nMaxNum, nTrgNum);
  cout << fnCaseCount(nMaxNum, nTrgNum) << endl;

  return 0;
}
