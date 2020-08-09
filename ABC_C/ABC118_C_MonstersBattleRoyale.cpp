#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnDivisor)
{
  cin >> rnDivisor;
}

int fnDigit(int nDivisor)
{
  set<int> seRemain;

  int nDividend = 7;
  int nDigit = 1;
  int nRemain = nDividend % nDivisor;

  while ( seRemain.count(nRemain) == 0 )
  {
    seRemain.insert(nRemain);
    if (!nRemain)
      return nDigit;

    nDividend = nRemain * 10 + 7;
    nRemain = nDividend % nDivisor;
    nDigit++;
  }
  return -1;
}
 
int main()
{
  int nDivisor;

  fnInput(nDivisor);
  cout << fnDigit(nDivisor) << endl;

  return 0;
}
