#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnMaxNum)
{
  cin >> rnMaxNum;
}

int fnDgt753_Check(int nNum)
{
  int nDig3 = 0, nDig5 = 0, nDig7 = 0;

  if (!nNum) return 0;
  while (nNum)
  {
    int nRes = nNum % 10;
    if      (nRes == 3) nDig3++;
    else if (nRes == 5) nDig5++;
    else if (nRes == 7) nDig7++;
    else                return 0;
    nNum /= 10;
  }

  if (nDig3 && nDig5 && nDig7)
    return 1;
  else 
    return 0;
}

int fnNum753_Count(int nMaxNum)
{
  int nDigit753Cnt = 0;
  for (int i = 0; i <= nMaxNum; i++)
    if (fnDgt753_Check(i)) nDigit753Cnt++;

  return nDigit753Cnt;
}

int main()
{
  int nMaxNum;

  fnInput(nMaxNum);
  cout << fnNum753_Count(nMaxNum) << endl;

  return 0;
}
