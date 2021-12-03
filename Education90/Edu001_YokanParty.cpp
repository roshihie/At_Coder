#include <bits/stdc++.h>
using namespace std;

void input( vector<int>& rvCutLen, int& rcuttingCnt )
{
  int cutLenSiz, totalLen;
  cin >> cutLenSiz >> totalLen;
  cin >> rcuttingCnt;
  rvCutLen.resize( cutLenSiz );

  for ( int& rcutLen : rvCutLen )
    cin >> rcutLen;

  rvCutLen.push_back( totalLen );
}

bool canCutOff( const vector<int>& crvCutLen, int cuttingCnt, int trgCutLen )
{
  int lastElm = (int)crvCutLen.size() - 1;
  int cuttedCnt = 0;
  int cutedLen = 0;

  for ( int fwd = 0; fwd < lastElm; ++fwd )
    if ( crvCutLen[fwd]  - cutedLen >= trgCutLen         &&
         crvCutLen[lastElm] - crvCutLen[fwd] >= trgCutLen  )
    {
      cutedLen = crvCutLen[fwd];
      ++cuttedCnt;
    }

  if ( cuttedCnt >= cuttingCnt )
    return true;
  else
    return false;
}

int calcMaxShortest( const vector<int>& crvCutLen, int cuttingCnt )
{
  int lastElm = (int)crvCutLen.size() - 1;
  int maxShortest = 0;
  int lowElm = 1, highElm = crvCutLen[lastElm];

  while ( lowElm < highElm )
  {
    int midElm = ( lowElm + highElm ) / 2;

    if ( canCutOff( crvCutLen, cuttingCnt, midElm ))
    {
      maxShortest = midElm;
      lowElm = midElm + 1;
    }
    else
      highElm = midElm;
  }
  return maxShortest;
}
  
int main()
{
  int cuttingCnt;
  vector<int> vCutLen;

  input( vCutLen, cuttingCnt );
  cout << calcMaxShortest( vCutLen, cuttingCnt ) << endl;

  return 0;
}
