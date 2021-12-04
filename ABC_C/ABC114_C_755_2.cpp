#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input( int& rmaxNum )
{
  cin >> rmaxNum;
}

llong toInt( const vector<char>& crvNum )
{
  const vector<int> cnvdgt = { 0, 3, 5, 7 };
  llong rtnInt = 0;
  int dgtPos = 0;

  for ( int x = crvNum.size() - 1; x >= 0; --x )
  {
    if ( crvNum[x] == '0' ) break;
    llong num = cnvdgt[ crvNum[x] - '0' ];
    
    for ( int pos = 0; pos < dgtPos; ++pos ) num *= 10;

    rtnInt += num;
    ++dgtPos;
  }
  return rtnInt;
}

int isDgt753( const vector<char>& crvNum )
{
  int dgt3 = 0, dgt5 = 0, dgt7 = 0;

  for ( int x = 0; x < crvNum.size(); ++x )
    if      (crvNum[x] == '1') ++dgt3;
    else if (crvNum[x] == '2') ++dgt5;
    else if (crvNum[x] == '3') ++dgt7;

  if ( dgt3 && dgt5 && dgt7 )
    return 1;
  else
    return 0;
}

int countDgt753( int maxNum )
{
  int cntDgt753 = 0;
  int dgtSiz = to_string( maxNum ).size();
  vector<char> vNum( dgtSiz + 1, '0' );

  while ( toInt( vNum ) <= maxNum ) 
  {
    if ( isDgt753( vNum )) ++cntDgt753;
    ++vNum[vNum.size() - 1];

    for ( int x = vNum.size() - 1; x > 0; --x )
      if (vNum[x] > '3')
      {  
        ++vNum[x - 1];
        vNum[x] = '1';
      }
      else
        break;
  }
  return cntDgt753;
}

int main()
{
  int maxNum;

  input( maxNum );
  cout << countDgt753( maxNum ) << endl;

  return 0;
}
