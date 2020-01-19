#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnHighNum, int& rnMinSum, int& rnMaxSum)
{
  cin >> rnHighNum >> rnMinSum >> rnMaxSum;
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

int fnSomeSums(int nHighNum, int nMinSum, int nMaxSum)
{
  int nTotal = 0;
  for (int n = 1; n <= nHighNum; n++)
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
  int nHighNum, nMinSum, nMaxSum;
  fnInput(nHighNum, nMinSum, nMaxSum);

  cout << fnSomeSums(nHighNum, nMinSum, nMaxSum) << endl;
  return 0;
}
