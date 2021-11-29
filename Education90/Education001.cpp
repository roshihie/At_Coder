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
  int nCanCnt = 0;
  int nFwd = 0;
  int nSumCutLen = 0;

  while (nFwd < (int)cnrvnCutLen.size() &&
         nCanCnt < nCutCnt                )
  {
    while (nFwd < (int)cnrvnCutLen.size() &&
           nSumCutLen < nTrgCutLen          )
    {
      if ( nFwd )
        nSumCutLen += (cnrvnCutLen[nFwd] - cnrvnCutLen[nFwd - 1]);
      else
        nSumCutLen += cnrvnCutLen[nFwd];

      ++nFwd;
    }
    ++nCanCnt;
    nSumCutLen = 0;
  }

  for ( ; nFwd < (int)cnrvnCutLen.size(); ++nFwd)
    nSumCutLen += (cnrvnCutLen[nFwd] - cnrvnCutLen[nFwd - 1]);

  if (nSumCutLen < nTrgCutLen)
    return false;
  else if (nCanCnt < nCutCnt) 
    return false;
  else
    return true;
}

int calcMaxShortest(const vector<int>& cnrvnCutLen, int nCutCnt)
{
  int nMaxShortest = 0;
  int nLow = 1, nHigh = cnrvnCutLen[ cnrvnCutLen.size() - 1 ];

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
