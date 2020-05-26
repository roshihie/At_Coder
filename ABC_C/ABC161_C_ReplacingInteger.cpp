#include <bits/stdc++.h>
using namespace std;

void fnInput(int64_t& nNumN, int64_t& nNumK)
{
  cin >> nNumN >> nNumK;
}
  
int64_t fnMinRepNum(int64_t nNumN, int64_t nNumK)
{
  int64_t nRepNum = nNumN % nNumK;
  return min(nRepNum, nNumK - nRepNum);
}
  
int main()
{
  int64_t nNumN, nNumK;

  fnInput(nNumN, nNumK);
  cout << fnMinRepNum(nNumN, nNumK) << endl;

  return 0;
}
