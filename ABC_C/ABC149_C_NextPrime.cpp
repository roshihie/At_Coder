#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnNum)
{
  cin >> rnNum;
}
  
int fnNextPrimeGet(int nNum)
{
  int nNextPrime = nNum - 1;
  bool bPrime = false;

  while (!bPrime)
  {
    nNextPrime++;
    int nSqrtInt = sqrt(nNextPrime);
    bPrime = true;

    for (int n = 2; n <= nSqrtInt; n++)
      if (nNextPrime % n == 0)
      {
        bPrime = false;
        break;
      }
  }
  return nNextPrime;
}
  
int main()
{
  int nNum;

  fnInput(nNum);
  cout << fnNextPrimeGet(nNum) << endl;

  return 0;
}
