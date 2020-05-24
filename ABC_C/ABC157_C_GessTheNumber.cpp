#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsNum, bool& rbRslt)
{
  int nDigit, nInfSiz;
  cin >> nDigit >> nInfSiz;
  rsNum.resize(nDigit, ' ');

  rbRslt = true;

  for (int i = 0; i < nInfSiz; i++)
  {
    int nPos, nNum;
    cin >> nPos >> nNum;

    if (nPos == 1 && nNum == 0 && nDigit > 1)
      rbRslt = false;
    else if (rsNum[nPos - 1] == ' ')
      rsNum[nPos - 1] = '0' + nNum;
    else if (rsNum[nPos - 1] != '0' + nNum)
      rbRslt = false;
    else
      continue;
  }
  return;
}
  
string fnNumstrGet(string sNum)
{
  for (int i = 0; i < sNum.size(); i++)
    if (sNum[i] == ' ')
      if ( !i )
        if (sNum.size() == 1) sNum[i] = '0';
        else                  sNum[i] = '1';
      else                    sNum[i] = '0';

  return sNum;
}
  
int main()
{
  string sNum;
  bool bRslt;

  fnInput(sNum, bRslt);
  if (!bRslt)
    cout << "-1" << endl;
  else
    cout << fnNumstrGet(sNum) << endl;

  return 0;
}
