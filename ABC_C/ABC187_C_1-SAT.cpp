#include <bits/stdc++.h>
using namespace std;

void input(set<string>& rseStr)
{
  int nStrSiz;
  cin >> nStrSiz;

  for (int nx = 0; nx < nStrSiz; ++nx)
  {
    string sStr;
    cin >> sStr;
    rseStr.insert(sStr);
  }
}

string isExistStr(const set<string>& cnrseStr)
{
  for (auto sStr : cnrseStr)
  {
    if (sStr[0] == '!')
    {
      string s2ndSubStr = sStr.substr(1);
      if ( cnrseStr.count(s2ndSubStr) )
        return s2ndSubStr;
    }
  }
  return "satisfiable";
}
  
int main()
{
  set<string> seStr;
  input(seStr);
  cout << isExistStr(seStr) << endl;

  return 0;
}
