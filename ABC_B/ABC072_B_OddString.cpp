#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsStr)
{
  cin >> rsStr;
}

string fnOddString(string sStr)
{
  string sOddStr = "";
  for (int i = 0; i < sStr.size(); i++)
    if (i % 2 == 0) sOddStr += sStr[i];

  return sOddStr;
}

int main()
{
  string sStr;

  fnInput(sStr);
  cout << fnOddString(sStr) << endl;

  return 0;
}
