#include <bits/stdc++.h>
using namespace std;

struct StCoord
{
  StCoord() : m_col(0), m_row(0), m_high(0) { }

  int m_col;
  int m_row;
  int m_high;
};

void input( vector<StCoord>& rvoCoord )
{
  int coordSiz;
  cin >> coordSiz;
  rvoCoord.resize( coordSiz );

  for ( StCoord& roCoord : rvoCoord )
    cin >> roCoord.m_col >> roCoord.m_row >> roCoord.m_high;
}

int calcCenterDiff( StCoord oCenter, StCoord oCoord )
{
  return  abs( oCenter.m_col - oCoord.m_col ) 
        + abs( oCenter.m_row - oCoord.m_row );
}

int calcCenterHigh( StCoord oCenter, StCoord oCoord )
{
  return calcCenterDiff( oCenter, oCoord ) + oCoord.m_high;
}

bool checkCenter( StCoord& roCenter, const vector<StCoord>& crvoCoord )
{
  int size = (int)crvoCoord.size();
  int centerHigh = 0;

  for ( int x = 0; x < size; ++x )
    if ( crvoCoord[x].m_high )
      if ( !centerHigh )
        centerHigh = calcCenterHigh(roCenter, crvoCoord[x]);
      else
        if ( centerHigh != calcCenterHigh( roCenter, crvoCoord[x] ))
          return false;

  for ( int x = 0; x < size; ++x )
    if ( !crvoCoord[x].m_high )
      if ( centerHigh <= calcCenterDiff( roCenter, crvoCoord[x] ));
      else
        return false;

  roCenter.m_high = centerHigh;
  return true;
}

void calcCenterCoord( const vector<StCoord>& crvoCoord )
{
  StCoord oCenter;
  bool isCenter = false;
  oCenter.m_col = -1;

  while ( !isCenter  &&
          ++oCenter.m_col <= 100 )
  {
    oCenter.m_row = -1;

    while ( !isCenter  &&
            ++oCenter.m_row <= 100 )
      isCenter = checkCenter( oCenter, crvoCoord );
  }
  if ( isCenter )  
    cout << oCenter.m_col << " " << oCenter.m_row << " " << oCenter.m_high;
}
  
int main()
{
  vector<StCoord> voCoord;
  
  input( voCoord );
  calcCenterCoord( voCoord );

  return 0;
}
