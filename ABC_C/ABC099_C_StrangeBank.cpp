#include <bits/stdc++.h>
using namespace std;

void input( int& rcash )
{
  cin >> rcash;
}

int calcOpeCnt( int cash )
{
  //                   最大値に cash 指定
  vector<int> vExchg( cash + 1, cash );
  vExchg[0] = 0;

  for ( int x = 1; x <= cash; ++x )
  {
    for ( int y = 1; x - y >= 0; y *= 6 )
      vExchg[x] = min( vExchg[x], vExchg[ x - y ] + 1 );

    for ( int y = 1; x - y >= 0; y *= 9 )
      vExchg[x] = min( vExchg[x], vExchg[ x - y ] + 1 );
  }
  return vExchg[cash];
}

int main()
{
  int cash; 
  input( cash );
  cout << calcOpeCnt( cash ) << endl;

  return 0;
}
