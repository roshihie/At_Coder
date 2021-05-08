#include <bits/stdc++.h>
using namespace std;

void input(int& rnNum)
{
  cin >> rnNum;
}

void calcBaseM2Num(int nNum, vector<int>& rvnRem)
{
  do {
    int nRem = nNum % -2;
    nNum /= -2;
    
    if (nRem == -1)
    {
      ++nNum;
      nRem += 2;
    }
    rvnRem.push_back( nRem );
  }
  while ( nNum );

  reverse(begin(rvnRem), end(rvnRem));
}

int main()
{
  int nNum;
  vector<int> vnRem;

  input(nNum);
  calcBaseM2Num(nNum, vnRem);
  
  for (int nRem : vnRem)
    cout << nRem;

  cout << endl;

  return 0;
}
