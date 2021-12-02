#include <bits/stdc++.h>
using namespace std;

void input( vector<int>& rvCutLen, int& rcutCnt )
{
  int cutLenSiz, totalLen;
  cin >> cutLenSiz >> totalLen;
  cin >> rcutCnt;
  rvCutLen.resize( cutLenSiz );

  for ( int& rcutLen : rvCutLen )
    cin >> rcutLen;

  rvCutLen.push_back( totalLen );
}

bool canCutOff( const vector<int>& cnrvCutLen, int cutCnt, int trgCutLen )
{
  int last = (int)cnrvCutLen.size() - 1;
  int cuttingCut = 0;
  int cutedLen = 0;

  for ( int fwd = 0; fwd < last; ++fwd )
    if ( cnrvCutLen[fwd]  - cutedLen >= trgCutLen       &&
         cnrvCutLen[last] - cnrvCutLen[fwd] >= trgCutLen  )
    {
      cutedLen = cnrvCutLen[fwd];
      ++cuttingCut;
    }

  if ( cuttingCut >= cutCnt )
    return true;
  else
    return false;
}

int calcMaxShortest( const vector<int>& cnrvCutLen, int cutCnt )
{
  int last = (int)cnrvCutLen.size() - 1;
  int maxShortest = 0;
  int low = 1, high = cnrvCutLen[last];

  while ( low < high )
  {
    int mid = ( low + high ) / 2;

    if ( canCutOff( cnrvCutLen, cutCnt, mid ))
    {
      maxShortest = mid;
      low = mid + 1;
    }
    else
      high = mid;
  }
  return maxShortest;
}
  
int main()
{
  int cutCnt;
  vector<int> vCutLen;

  input( vCutLen, cutCnt );
  cout << calcMaxShortest( vCutLen, cutCnt ) << endl;

  return 0;
}
