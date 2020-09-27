#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnMaxNum, int& rnBase)
{
  cin >> rnMaxNum >> rnBase;
}

llong calcNumOfCases(int nMaxNum, int nBase)
{
  llong nNumOfCases = 0;
  int nTerm;

  if (nBase % 2 == 0)
  {
//    an = a1 + (n - 1)d
//    nMaxNum = (nBase / 2) + (n - 1)nBase  
     if ( nMaxNum - (nBase / 2) >= 0 )
     {
       nTerm = ( nMaxNum - (nBase / 2) ) / nBase + 1;
       nNumOfCases += (llong)nTerm * nTerm * nTerm;
     }
  }
  nTerm = nMaxNum / nBase;
  nNumOfCases += (llong)nTerm * nTerm * nTerm;

  return nNumOfCases;
}
  
int main()
{
  int nMaxNum, nBase;
  
  input(nMaxNum, nBase);
  cout << calcNumOfCases(nMaxNum, nBase) << endl;

  return 0;
}
