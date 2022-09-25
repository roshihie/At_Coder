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
  for (auto str : cruseStr)
    if (str[0] == '!')
    {
      string wstr = str.substr(1);
      if ( cruseStr.count(wstr) )
        return wstr;
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
