#include <bits/stdc++.h>
using namespace std;

void input(map<int, int>& rmpNumCnt)
{
  int nSize;
  cin >> nSize;

  for (int nx = 0; nx < nSize; ++nx)
  {
    int nNum;
    cin >> nNum;
    ++rmpNumCnt[nNum];
  }
}

int calcWriteNum(const map<int, int> cnrmpNumCnt)
{
  int nWriteNumCnt = 0;

  for (auto PNumCnt : cnrmpNumCnt)
    if ( PNumCnt.second % 2 ) ++nWriteNumCnt;

  return nWriteNumCnt;
}

int main()
{
  map<int, int> mpNumCnt;

  input(mpNumCnt);
  cout << calcWriteNum(mpNumCnt) << endl;

  return 0;
}
