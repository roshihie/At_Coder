#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnNum)
{
  cin >> rnNum;
}

int calcDigits(int nDividend)
{
  int nDgtCnt = 1;

  while (nDividend /= 10)
    ++nDgtCnt;

  return nDgtCnt;
}

int isMultiple(llong nNum)
{
  int nDivisor = sqrt(nNum);

  while (nNum % nDivisor)
    --nDivisor;

  int nDividend = nNum / nDivisor;
  return calcDigits(nDividend);  
}

int main()
{
  llong nNum;
  
  input(nNum);
  cout << isMultiple(nNum) << endl;

  return 0;
}
