#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnNum, int& rnWinPnt)
{
  cin >> rnNum >> rnWinPnt;
}

double fnAlmightyPass(int nNum, int nWinPnt)
{
  vector<int> vnBorder;
  int nBorder = nNum;

  while (nBorder)
  {
    vnBorder.push_back( nBorder );
    nBorder /= 2;
  }

  

}
  
int main()
{
  int nNum, nWinPnt;
  fnInput(nNum, nWinPnt);
  cout << fnWinRate(nNum, nWinPnt) << endl;

  return 0;
}
