#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsColor)
{
  cin >> rsColor;
}

int fnMaxRemove(string sColor)
{
  vector<int> vnColor(2);

  for (int i = 0; i < sColor.size(); i++)
    vnColor[ sColor[i] - '0' ]++;

  return min(vnColor[0], vnColor[1]) * 2;
}
 
int main()
{
  string sColor;

  fnInput(sColor);
  cout << fnMaxRemove(sColor) << endl;

  return 0;
}
