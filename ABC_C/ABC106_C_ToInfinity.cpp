#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(string& rsNumStr, llong& rnPos)
{
  cin >> rsNumStr >> rnPos;
}

int calcPosChar(string sNumStr, llong nPos)
{
  llong n1st1Cnt = 0;
  int n2ndNo = 0;

  while (n1st1Cnt < sNumStr.size() &&
         sNumStr[n1st1Cnt] == '1'     )
    ++n1st1Cnt;

  if (n1st1Cnt < sNumStr.size() )
    n2ndNo = sNumStr[n1st1Cnt] - '0';

  if (nPos <= n1st1Cnt) return 1;
  return n2ndNo;
}

int main()
{
  string sNumStr;
  llong nPos;
  input(sNumStr, nPos);
  cout << calcPosChar(sNumStr, nPos) << endl;

  return 0;
}
