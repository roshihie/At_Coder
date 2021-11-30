#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnCutLen, int& rnCutCnt)
{
  int nCutLenSiz, nTotalLen;
  cin >> nCutLenSiz >> nTotalLen;
  cin >> rnCutCnt;
  rvnCutLen.resize(nCutLenSiz);

  for (int& nCutLen : rvnCutLen)
    cin >> nCutLen;

  rvnCutLen.push_back( nTotalLen );
}

bool canCutOff(const vector<int>& cnrvnCutLen, int nCutCnt, int nTrgCutLen)
{
  int nLast = (int)cnrvnCutLen.size() - 1;
  int nCanCutCnt = 0;
  int nCutedLen = 0;

  for (int nFwd = 0; nFwd < nLast; ++nFwd)
    if (cnrvnCutLen[nFwd]  - nCutedLen >= nTrgCutLen        &&
        cnrvnCutLen[nLast] - cnrvnCutLen[nFwd] >= nTrgCutLen  )
    {
      nCutedLen = cnrvnCutLen[nFwd];
      ++nCanCutCnt;
    }

  if (nCanCutCnt >= nCutCnt)
    return true;
  else
    return false;
}

int calcMaxShortest(const vector<int>& cnrvnCutLen, int nCutCnt)
{
  int nLast = (int)cnrvnCutLen.size() - 1;
  int nMaxShortest = 0;
  int nLow = 1, nHigh = cnrvnCutLen[nLast];

  while (nLow < nHigh)
  {
    int nMid = (nLow + nHigh) / 2;

    if ( canCutOff(cnrvnCutLen, nCutCnt, nMid) )
    {
      nMaxShortest = nMid;
      nLow = nMid + 1;
    }
    else
      nHigh = nMid;
  }
  return nMaxShortest;
}
  
int main()
{
  int nCutCnt;
  vector<int> vnCutLen;

  input(vnCutLen, nCutCnt);
  cout << calcMaxShortest(vnCutLen, nCutCnt) << endl;

  return 0;
}
