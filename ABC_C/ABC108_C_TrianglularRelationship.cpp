#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnMaxNum, int& rnBase)
{
  cin >> rnMaxNum >> rnBase;
}

llong calcNumOfCase(int nMaxNum, int nBase)
{
  llong nNumOfCase = 0;
  int nTerm;

  if (nBase % 2 == 0)
  {
//    an = a1 + (n - 1)d
//    nMaxNum = (nBase / 2) + (n - 1)nBase  
     if ( nMaxNum - (nBase / 2) >= 0 )
     {
       nTerm = ( nMaxNum - (nBase / 2) ) / nBase + 1;
       nNumOfCase += (llong)nTerm * nTerm * nTerm;
     }
  }
  nTerm = nMaxNum / nBase;
  nNumOfCase += (llong)nTerm * nTerm * nTerm;

  return nNumOfCase;
}
  
int main()
{
  int nMaxNum, nBase;
  
  input(nMaxNum, nBase);
  cout << calcNumOfCase(nMaxNum, nBase) << endl;

  return 0;
}
