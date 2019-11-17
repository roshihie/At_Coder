#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnSpcNum, int& rnMinSum, int& rnMaxSum)
{
  cin >> rnSpcNum >> rnMinSum >> rnMaxSum;
}

int fnDigitsSum(int nNum)
{
  int nDigitsSum = 0;
  while ( nNum )
  {
    nDigitsSum += nNum % 10;
    nNum /= 10;
  }
  return nDigitsSum;
}

int fnSomeSums(int nSpcNum, int nMinSum, int nMaxSum)
{
  int nTotal = 0;
  for (int n = 1; n <= nSpcNum; n++)
  {  
    int nDigitsSum = 0;
    nDigitsSum += fnDigitsSum(n);
    if (nMinSum <= nDigitsSum && nDigitsSum <= nMaxSum)
      nTotal += n;
  }
  return nTotal;
}

int main()
{
  int nSpcNum, nMinSum, nMaxSum;
  fnInput(nSpcNum, nMinSum, nMaxSum);

  cout << fnSomeSums(nSpcNum, nMinSum, nMaxSum) << endl;
  return 0;
}
 
