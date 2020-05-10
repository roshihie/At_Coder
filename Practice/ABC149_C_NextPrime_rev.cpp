#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnNum)
{
  cin >> rnNum;
}
  
int fnNextPrimeGet(int nNum)
{
  int nNextNum = nNum - 1;
  bool bPrime = false;

  while (!bPrime)
  {
    nNextNum++;
    int nSqrtNum = sqrt(nNextNum);
    bPrime = true;

    for (int n = 2; n <= nSqrtNum; n++)
      if (nNextNum % n == 0)
      {
        bPrime = false;
        break;
      }
  }
  return nNextNum;
}
  
int main()
{
  int nNum;

  fnInput(nNum);
  cout << fnNextPrimeGet(nNum) << endl;

  return 0;
}
