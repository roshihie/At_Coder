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

  for (int nx = 0; nx <= nMaxNum; ++nx)
    for (int ny = 0; ny <= nx; ++ny)
    {
      int nRestNum = nTrgNum - (nx + ny);
      if (0 <= nRestNum && nRestNum <= ny)
        if      (nx == ny && ny == nRestNum)
          ++nAllSame;
        else if (nx == ny || ny == nRestNum || nRestNum == nx)
          ++nSameTwo;
        else
          ++nAllDiff;
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
