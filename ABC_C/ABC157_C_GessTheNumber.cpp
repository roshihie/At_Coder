#include <bits/stdc++.h>
using namespace std;

void input(string& rsNum, bool& rbRslt)
{
  int nDigit, nInfSiz;
  cin >> nDigit >> nInfSiz;
  rsNum.resize(nDigit, ' ');

  rbRslt = true;

  for (int nx = 0; nx < nInfSiz; ++nx)
  {
    int nPos, nNum;
    cin >> nPos >> nNum;
    --nPos;

    if ( nPos == 0 && nNum == 0 && nDigit > 1 )
      rbRslt = false;
    else if ( rsNum[nPos] == ' ' )
      rsNum[nPos] = '0' + nNum;
    else if ( rsNum[nPos] != '0' + nNum )
      rbRslt = false;
    else
      continue;
  }
  return;
}
  
string calcMinNumber(string sNum)
{
  for (int nx = 0; nx < sNum.size(); ++nx)
    if ( sNum[nx] == ' ' )
      if ( !nx )
        if ( sNum.size() == 1 ) sNum[nx] = '0';
        else                    sNum[nx] = '1';
      else                      sNum[nx] = '0';

  return sNum;
}
  
int main()
{
  string sNum;
  bool bRslt;

  input(sNum, bRslt);
  if (!bRslt)
    cout << "-1" << endl;
  else
    cout << calcMinNumber(sNum) << endl;

  return 0;
}
