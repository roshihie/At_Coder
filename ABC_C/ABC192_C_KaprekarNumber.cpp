#include <bits/stdc++.h>
using namespace std;

void input(int& rnNum, int& rnTrg)
{
  cin >> rnNum >> rnTrg;
}

int calcMinMaxElm(const vector<int> cnrvnDisit)
{
  int nMinMaxElm = 0;

  for (int nElmx = 0; nElmx < cnrvnDisit.size(); ++nElmx)
  {
    int nPlace = 1;

    for (int nx = 0; nx < nElmx; ++nx)
      nPlace *= 10;

    nMinMaxElm += cnrvnDisit[nElmx] * nPlace;
  }

  return nMinMaxElm;
}

int calcKaprekarNum(int nSequenceElm)
{
  vector<int> vnDigit;

  while ( nSequenceElm )
  {
    vnDigit.push_back( nSequenceElm % 10 );
    nSequenceElm /= 10;
  }

  int nMaxElm = 0, nMinElm = 0;
  if ( vnDigit.size() )
  {
    sort(begin(vnDigit), end(vnDigit));
    nMaxElm = calcMinMaxElm(vnDigit);

    reverse(begin(vnDigit), end(vnDigit));
    nMinElm = calcMinMaxElm(vnDigit);
  }

  return nMaxElm - nMinElm;
}

int calcSequenceElm(int nNum, int nTrg)
{
  int nSequenceElm = nNum;
  
  for (int nElmx = 1; nElmx <= nTrg; ++nElmx)
  {
    nSequenceElm = calcKaprekarNum(nSequenceElm);
  }
  
  return nSequenceElm;
}
  
int main()
{
  int nNum, nTrg;
  input(nNum, nTrg);
  cout << calcSequenceElm(nNum, nTrg) << endl;

  return 0;
}
