#include <bits/stdc++.h>
using namespace std;

void input( int& rnum )
{
  cin >> rnum;
}

void outPairKakko( int num, int bit )
{
  for ( int each = num - 1; each >= 0; --each )
    if ( bit & ( 1 << each ))
      cout << ")";
    else
      cout << "(";

  cout << endl;
}

void chkPairKakko ( int num )
{
  for ( int bit = 0; bit < ( 1 << num ); ++bit )
  {
    int leftKkCnt = 0, rightKkCnt = 0;
    bool isPairKakko = true;

    for ( int each = num - 1; each >= 0; --each )
    {
      if ( bit & ( 1 << each ))
         ++rightKkCnt;
      else
         ++leftKkCnt;

      if ( leftKkCnt < rightKkCnt )
      {
        isPairKakko = false;
        break;
      }
    }
    if ( isPairKakko && leftKkCnt == rightKkCnt )
       outPairKakko( num, bit );
  }
}
  
int main()
{
  int num;
  input( num );
  chkPairKakko( num );

  return 0;
}
