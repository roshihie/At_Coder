#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rmaxNum)
{
  cin >> rmaxNum;
}

bool isDgt753( llong recrNum )
{
  int cntDgt3 = 0, cntDgt5 = 0, cntDgt7 = 0;

  while ( recrNum )
  {
    int n1stDgt = recrNum % 10;

    if      ( n1stDgt == 3 ) ++cntDgt3;
    else if ( n1stDgt == 5 ) ++cntDgt5;
    else if ( n1stDgt == 7 ) ++cntDgt7;

    recrNum /= 10;
  }
  if ( cntDgt3 && cntDgt5 && cntDgt7 )
    return true;
  else
    return false;
}

void dfs( int maxNum, llong recrNum )
{
  static int stCntDgt753 = 0;

  if ( recrNum > maxNum ) return;
  if ( isDgt753( recrNum )) ++stCntDgt753;

  dfs( maxNum, 10 * recrNum + 3 );
  dfs( maxNum, 10 * recrNum + 5 );
  dfs( maxNum, 10 * recrNum + 7 );

  if ( !recrNum ) cout << stCntDgt753 << endl;
}

int main()
{
  int maxNum;

  input( maxNum );
  dfs( maxNum, 0 );

  return 0;
}
