#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnNum)
{
  int nNumSiz;
  cin >> nNumSiz;
  rvnNum.resize(nNumSiz);

  for (int& rnNum : rvnNum)
    cin >> rnNum;
}

int calcMaxArea(const vector<int>& cnrvnNum)
{
  int nMaxArea = 0;

  for (int nLeft = 0; nLeft < cnrvnNum.size(); ++nLeft)
  {
    int nMinNum = cnrvnNum[nLeft];

    for (int nRight = nLeft; nRight < cnrvnNum.size(); ++nRight)
    {
      nMinNum = min(nMinNum, cnrvnNum[nRight]);
      nMaxArea = max(nMaxArea, (nRight - nLeft + 1) * nMinNum);
    }
  }
  return nMaxArea;
}
  
int main()
{
  vector<int> vnNum;
  input(vnNum);
  cout << calcMaxArea(vnNum) << endl;

  return 0;
}
