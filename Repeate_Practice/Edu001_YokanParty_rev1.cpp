#include <bits/stdc++.h>
using namespace std;

void input( vector<int>& rvCutLen, int& rcutCnt )
{
  int cutLenSiz, totalLen;

  cin >> cutLenSiz >> totalLen >> rcutCnt;
  rvCutLen.resize( cutLenSiz );

  for ( int& rcutLen : rvCutLen )
    cin >> rcutLen;

  rvCutLen.push_back( totalLen );
}

bool canCutOff( const vector<int>& crvCutLen, int cutCnt, int trgCutLen )
{
  int size = (int)crvCutLen.size();
  int nowCutCnt = 0;
  int cuttedLen = 0;

  for ( int fwd = 0; fwd < size; ++fwd )
    if ( crvCutLen[fwd] - cuttedLen >= trgCutLen      &&
        crvCutLen.back() - crvCutLen[fwd] >= trgCutLen  )
    {
      ++nowCutCnt;
      cuttedLen = crvCutLen[fwd];
    }

  if ( nowCutCnt >= cutCnt )
    return true;
  else
    return false;
}

int calcMaxShortLen( const vector<int>& crvCutLen, int cutCnt )
{
  int maxShortLen = 0;
  int low = 1;
  int high = crvCutLen.back();

  while ( low < high )
  {
    int mid = ( low + high ) / 2;
    if ( canCutOff( crvCutLen, cutCnt, mid ))
    {
      maxShortLen = mid;
      low = mid + 1;
    }
    else
      high = mid;
  }
  return maxShortLen;
}
  
int main()
{
  vector<int> vCutLen;
  int cutCnt;

  input( vCutLen, cutCnt );
  cout << calcMaxShortLen( vCutLen, cutCnt ) << endl; 

  return 0;
}
