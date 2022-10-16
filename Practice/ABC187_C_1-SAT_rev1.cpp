#include <bits/stdc++.h>
using namespace std;

void input(unordered_set<string>& rusStr)
{
  int sizStr;
  cin >> sizStr;

  for (int nx = 0; nx < sizStr; ++nx)
  {
    string str;
    cin >> str;
    rusStr.insert(str);
  }
}

string isExistStr(const unordered_set<string>& crusStr)
{
  for (auto str : crusStr)
    if ( crusStr.count ( "!" + str ) )
      return str;

  return "satisfiable";
}
  
int main()
{
  unordered_set<string> usStr;
  input(usStr);
  cout << isExistStr(usStr) << endl;

  return 0;
}
