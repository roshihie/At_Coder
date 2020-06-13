#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(llong& nNumN, llong& nNumK)
{
  cin >> nNumN >> nNumK;
}
  
llong fnMinRepNum(llong nNumN, llong nNumK)
{
  llong nRepNum = nNumN % nNumK;
  return min(nRepNum, nNumK - nRepNum);
}
  
int main()
{
  llong nNumN, nNumK;

  fnInput(nNumN, nNumK);
  cout << fnMinRepNum(nNumN, nNumK) << endl;

  return 0;
}
