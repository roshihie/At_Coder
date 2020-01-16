#include <bits/stdc++.h>
using namespace std;

void fnInput(map<char, int>& rmpChars)
{
  string sStr;
  cin >> sStr;

  for (char ch = 'a'; ch <= 'z'; ch++)
    rmpChars[ch] = 0;

  for (int i = 0; i < sStr.size(); i++)
    rmpChars[ sStr[i] ]++;
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
