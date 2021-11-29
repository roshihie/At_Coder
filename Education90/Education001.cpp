#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnCutLen, int& rnCutOffCnt)
{
  int nCutLenSiz, nTotalLen;
  cin >> nCutLenSiz >> nTotalLen;
  cin >> rnCutOffCnt;
  rvnCutLen.resize(nCutLenSiz);

  for (int& nCutLen : rvnCutLen)
    cin >> nCutLen;

  rvnCutLen.push_back( nTotalLen );
}

bool canCutOff(const vector<int>& cnrvnCutLen, int nCutOffCnt, int nTrgCutLen)
{
  int nCanCnt = 0;
  int nFwd = 0;
  int nSumCutLen = 0;

  while (nFwd < (int)cnrvnCutLen.size() &&
         nCanCnt < nCutOffCnt             )
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
  else if (nCanCnt < nCutOffCnt) 
    return false;
  else
    return true;
}

int calcMaxShortest(const vector<int>& cnrvnCutLen, int nCutOffCnt)
{
  int nMaxShortest = 0;
  int nLow = 1, nHigh = cnrvnCutLen[ cnrvnCutLen.size() - 1 ];

  while (nLow < nHigh)
  {
    int nMid = (nLow + nHigh) / 2;

    if ( canCutOff(cnrvnCutLen, nCutOffCnt, nMid) )
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
  int nCutOffCnt;
  vector<int> vnCutLen;

  input(vnCutLen, nCutOffCnt);
  cout << calcMaxShortest(vnCutLen, nCutOffCnt) << endl;

  return 0;
}

