#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsSLine, string& rsTLine)
{
  cin >> rsSLine >> rsTLine;

  sort(begin(rsSLine), end(rsSLine));
  sort(begin(rsTLine), end(rsTLine), greater<char>());
}

void fnAnagramCheck(string sSLine, string sTLine)
{
  if (sSLine < sTLine) cout << "Yes" << endl;
  else                 cout << "No"  << endl;
}

int main()
{
  string sSLine;
  string sTLine;

  fnInput(sSLine, sTLine);
  fnAnagramCheck(sSLine, sTLine);

  return 0;
}
