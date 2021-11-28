#include <bits/stdc++.h>
using namespace std;

void input(string& rsStr, int& rnKth)
{
  cin >> rsStr >> rnKth;
}

string calcKthSubstr(string sStr, int nKth)
{
  set<string> seSubstr;

  for (int nPos = 0; nPos < (int)sStr.size(); ++nPos)
  {
    int nLen = 1;

    while (nLen <= 5  &&
           nPos + nLen <= (int)sStr.size() )
    {
      seSubstr.insert( sStr.substr(nPos, nLen) );
      ++nLen;
    }
  }
  int nCnt = 0;

  for (auto sKthSubstr : seSubstr)
    if ( ++nCnt == nKth)
      return sKthSubstr;
    else;
}
  
int main()
{
  string sStr;
  int nKth;

  input(sStr, nKth);
  cout << calcKthSubstr(sStr, nKth) << endl;

  return 0;
}
