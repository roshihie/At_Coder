#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnNum)
{
  cin >> rnNum;
}

int fnDigitSum(int nNum)
{
  int nDigitSum = 0;
  while (nNum)
  {
    nDigitSum += nNum % 10;
    nNum /= 10;
  }

  return nDigitSum;
}

int fnHarshadCheck(int nNum)
{
  if (nNum % fnDigitSum(nNum) == 0) return 1;
  else                              return 0;
}

int main()
{
  int nNum;
  fnInput(nNum);

  if (fnHarshadCheck(nNum)) cout << "Yes" << endl;
  else                      cout << "No"  << endl;

  return 0;
}
