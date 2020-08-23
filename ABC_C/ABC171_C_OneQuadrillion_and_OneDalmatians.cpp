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
    --nDividend;
    int nRemain = nDividend % cnnDivisor;
    vnRemain.push_back( nRemain );

    nDividend /= cnnDivisor;
  }
  reverse(begin(vnRemain), end(vnRemain));

  for (int nRemain : vnRemain)
    cout << (char)('a' + nRemain);

  cout << endl;
}
  
int main()
{
  llong nNum;
  fnInput(nNum);
  fnNumToName(nNum);

  return 0;
}
