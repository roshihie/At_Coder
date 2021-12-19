#include <bits/stdc++.h>
using namespace std;

int N;

void input()
{
  cin >> N;
}

void outPairKakko( int bit )
{
  for ( int each = N - 1; each >= 0; --each )
    if ( bit & ( 1 << each ))
      cout << ")";
    else
      cout << "(";

  cout << endl;
}

void checkPairKakko()
{
  for ( int bit = 0; bit < ( 1 << N ); ++bit )
  {
    bool isPairKakko = true;
    int leftCnt = 0, rightCnt = 0;

    for ( int each = N - 1; each >= 0; --each )
    {
      if ( bit & ( 1 << each ))
        ++rightCnt;
      else
        ++leftCnt;

      if ( leftCnt < rightCnt )
      {
        isPairKakko = false;
        break;
      }
    }

    if ( isPairKakko && ( leftCnt == rightCnt ))
      outPairKakko( bit );
  }
}
  
int main()
{
  input();
  checkPairKakko();

  return 0;
}
