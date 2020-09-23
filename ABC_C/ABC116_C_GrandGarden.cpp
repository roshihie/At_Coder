#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnHeight)
{
  int nHeightSiz;
  cin >> nHeightSiz;
  rvnHeight.resize(nHeightSiz);

  for (int& rnHeight : rvnHeight)
    cin >> rnHeight;
}

int calcMinExecCnt(vector<int>& rvnHeight)
{
  int nExecCnt = 0;
  int nPrevExecCnt = -1;

  while (nPrevExecCnt != nExecCnt)
  {
    nPrevExecCnt = nExecCnt;
    int nBgn = 0;
  
    while (nBgn < rvnHeight.size() )
    {
      int nFwd = nBgn;

      while (nFwd < rvnHeight.size() &&
             rvnHeight[nFwd]            )
      {
        --rvnHeight[nFwd];
        ++nFwd;
      }

      if (nBgn != nFwd) ++nExecCnt;
      nBgn = nFwd + 1;
    }
  }
  return nExecCnt;
}
 
int main()
{
  vector<int> vnHeight;

  input(vnHeight);
  cout << calcMinExecCnt(vnHeight) << endl;

  return 0;
}
