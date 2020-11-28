#include <bits/stdc++.h>
using namespace std;

void fnInput(map<char, int>& rmpChars)
{
  string sStr;
  cin >> sStr;

  for (char ch = 'a'; ch <= 'z'; ++ch)
    rmpChars[ch] = 0;

  for (int nx = 0; nx < sStr.size(); ++nx)
    ++rmpChars[ sStr[nx] ];
}

void fnCharCheck(const map<char, int>& cnrmpChars)
{
  for (pair<const char, int> PChars : cnrmpChars)
    if (!PChars.second)
    {
      cout << PChars.first << endl;
      return;
    }

    cout << "None" << endl;
}

int main()
{
  map<char, int> mpChars;

  fnInput(mpChars);
  fnCharCheck(mpChars);

  return 0;
}
