#include <bits/stdc++.h>
using namespace std;

void input(unordered_set<string>& ruseStr)
{
  int sizStr;
  cin >> sizStr;

  for (int nx = 0; nx < sizStr; ++nx)
  {
    string str;
    cin >> str;
    ruseStr.insert(str);
  }
}

string isExistStr(const unordered_set<string>& cruseStr)
{
  unordered_set<string> useChk;

  for (auto str : cruseStr)
  {
    string wstr;
    if (str.substr(0, 1) == "!")
      wstr = str.substr(1);  
    else
      wstr = str.substr(0);

    auto rslt = useChk.insert( wstr );
    if ( !rslt.second )
      return *rslt.first;
  }
  return "satisfiable";
}
  
int main()
{
  unordered_set<string> useStr;
  input(useStr);
  cout << isExistStr(useStr) << endl;

  return 0;
}
