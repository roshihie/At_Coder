#include <bits/stdc++.h>
using namespace std;

void input( int& rswitchSiz, 
            vector<vector<int>>& rvvLightSwt, vector<int>& rvRslt)
{
  int lightSiz;
  cin >> rswitchSiz >> lightSiz;
  rvvLightSwt.resize( lightSiz );

  for ( auto& rvLightSwt : rvvLightSwt )
  {
    int lightSwtSiz;
    cin >> lightSwtSiz;
    rvLightSwt.resize( lightSwtSiz );

    for ( int& rlightSwt : rvLightSwt )
      cin >> rlightSwt;
  }

  rvRslt.resize( lightSiz );

  for ( int& rnRslt : rvRslt )
    cin >> rnRslt;
}

bool canLinghtOn( const vector<vector<int>>& crvvLightSwt,
                  const vector<int>& cnrvnSwitch,
                  const vector<int>& crvRslt)
{
  for ( int row = 0; row < crvvLightSwt.size(); ++row )
  {
    int nCanLightOn = 0;

    for ( const int& cnrlightSwt : crvvLightSwt[row] )
      nCanLightOn += cnrvnSwitch[ cnrlightSwt - 1 ];

    if ( nCanLightOn % 2 != crvRslt[row] )
      return false;
  }
  return true;
}

int calcLightOnCnt( int switchSiz,
                    const vector<vector<int>>& crvvLightSwt, 
                    const vector<int>& crvRslt )
{
  int lightOnCnt = 0;
  vector<int> vnSwitch( switchSiz );

  for ( int nBit = 0; nBit < ( 1 << switchSiz ); ++nBit )
  {
    for ( int nEach = 0; nEach < switchSiz; ++nEach )
      if ( nBit & ( 1 << nEach ))
        vnSwitch[nEach] = 1;
      else
        vnSwitch[nEach] = 0;

    if ( canLinghtOn( crvvLightSwt, vnSwitch, crvRslt ))
      ++lightOnCnt;
  }
  return lightOnCnt;
}
  
int main()
{
  int switchSiz;
  vector<vector<int>> vvLightSwt;
  vector<int> vRslt;

  input( switchSiz, vvLightSwt, vRslt );
  cout << calcLightOnCnt( switchSiz, vvLightSwt, vRslt ) << endl;

  return 0;
}
