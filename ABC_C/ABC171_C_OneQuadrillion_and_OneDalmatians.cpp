#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(llong& rnNum)
{
  cin >> rnNum;
}

void fnNumToName(llong nNum)
{
  const int cnnDivisor = 26;
  vector<int> vnRemain;
  llong nDividend = nNum;

  while ( nDividend )
  {
    llong nQuotient = nDividend / cnnDivisor;
    int nRemain = nDividend % cnnDivisor;
    if (!nRemain)
    {
      vnRemain.push_back( cnnDivisor );
      nQuotient--;
    }
    else
      vnRemain.push_back( nRemain );

    nDividend = nQuotient;
  }
  reverse(begin(vnRemain), end(vnRemain));

  for (int nRemain : vnRemain)
    cout << (char)('a' + nRemain - 1);

  cout << endl;
}
  
int main()
{
  llong nNum;
  fnInput(nNum);
  fnNumToName(nNum);

  return 0;
}
