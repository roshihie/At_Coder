#include <bits/stdc++.h>
using namespace std;

void input(int& rnNum)
{
  cin >> rnNum;
}
  
int calcNextPrime(int nNum)
{
  int nNextPrime = nNum - 1;
  bool bPrime = false;

  while ( !bPrime )
  {
    ++nNextPrime;
    int nSqrtInt = sqrt(nNextPrime);
    bPrime = true;

    for (int nx = 2; nx <= nSqrtInt; ++nx)
      if (nNextPrime % nx == 0)
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

  input(nNum);
  cout << calcNextPrime(nNum) << endl;

  return 0;
}
