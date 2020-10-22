#include <bits/stdc++.h>
using namespace std;
using llong = long long;
 
void input(llong& nNumN, llong& nNumK)
{
  cin >> nNumN >> nNumK;
}
  
llong calcMinNum(llong nNumN, llong nNumK)
{
  llong nRepNum = nNumN % nNumK;
  return min(nRepNum, nNumK - nRepNum);
}
  
int main()
{
  llong nNumN, nNumK;
     
  input(nNumN, nNumK);
  cout << calcMinNum(nNumN, nNumK) << endl;
        
  return 0;
}
