#include <bits/stdc++.h>
using namespace std;

void input(int& rnNum)
{
  cin >> rnNum;
}

void calcBaseM2Num(int nNum, vector<int>& rvnRem)
{
  if ( !nNum )
    rvnRem.push_back( 0 );

  while ( nNum )
  {
    int nRem = nNum % -2;
    nNum /= -2;
    
    if (nRem == -1)
    {
      ++nNum;
      nRem += 2;
    }
    rvnRem.push_back( nRem );
  }

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
