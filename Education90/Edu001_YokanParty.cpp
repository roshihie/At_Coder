#include <bits/stdc++.h>
using namespace std;

int N, L, K;
vector<int> vA;

void input()
{
  cin >> N >> L >> K;
  vA.resize( N );

  for ( int& cutLen : vA )
    cin >> cutLen;

  vA.push_back( L );
}

bool canCutOff( int trgCutLen )
{
  int nowCutCnt = 0;
  int cuttedLen = 0;

  for ( int fwd = 0; fwd < N; ++fwd )
    if ( vA[fwd] - cuttedLen >= trgCutLen &&
         vA.back() - vA[fwd] >= trgCutLen   )
    {
      ++nowCutCnt;
      cuttedLen = vA[fwd];
    }

  if ( nowCutCnt >= K )
    return true;
  else
    return false;
}

int calcMaxShortLen()
{
  int maxShortLen = 0;
  int low = 1;
  int high = vA.back();

  while ( low < high )
  {
    int mid = ( low + high ) / 2;
    if ( canCutOff( mid ))
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
  input();
  cout << calcMaxShortLen() << endl; 

  return 0;
}
