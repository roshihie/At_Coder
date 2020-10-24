#include <bits/stdc++.h>
using namespace std;
using llong = long long;
 
void input(llong& nNumN, llong& nNumK)
{
  cin >> nNumN >> nNumK;
}
  
llong calcMinNum(llong nNumN, llong nNumK)
{
  llong nModK = nNumN % nNumK;
  return min(nModK, nNumK - nModK);
}
  
int main()
{
  llong nNumN, nNumK;
     
  input(nNumN, nNumK);
  cout << calcMinNum(nNumN, nNumK) << endl;
        
  return 0;
}
