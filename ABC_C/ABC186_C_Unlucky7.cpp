#include <bits/stdc++.h>
using namespace std;

void input(int& rnMaxNum)
{
  cin >> rnMaxNum;
}

bool isNotInclude7(int nNum, int nBase)
{
  while (nNum != 0)
  {
    if (nNum % nBase == 7)
      return false;

    nNum /= nBase;
  }
  return true;
}

int calcNotInclude7(int nMaxNum)
{
  int nNotInclude7 = 0;

  for (int nx = 1; nx <= nMaxNum; ++nx)
    if ( isNotInclude7(nx, 10) &&
         isNotInclude7(nx,  8)    )
      ++nNotInclude7;

  return nNotInclude7;
}
  
int main()
{
  int nMaxNum;
  input(nMaxNum);
  cout << calcNotInclude7(nMaxNum) << endl;

  return 0;
}
