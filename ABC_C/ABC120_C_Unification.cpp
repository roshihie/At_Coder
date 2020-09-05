#include <bits/stdc++.h>
using namespace std;

void input(string& rsColor)
{
  cin >> rsColor;
}

int calcMaxRemove(string sColor)
{
  vector<int> vnColor(2);

  for (int i = 0; i < sColor.size(); i++)
    vnColor[ sColor[i] - '0' ]++;

  return min(vnColor[0], vnColor[1]) * 2;
}
 
int main()
{
  string sColor;

  input(sColor);
  cout << calcMaxRemove(sColor) << endl;

  return 0;
}
