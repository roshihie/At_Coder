#include <bits/stdc++.h>
using namespace std;

void input(string& rsColor)
{
  cin >> rsColor;
}

int calcMaxRemove(string sColor)
{
  vector<int> vnColor(2);

  for (int nx = 0; nx < sColor.size(); ++nx)
    vnColor[ sColor[nx] - '0' ]++;

  return min(vnColor[0], vnColor[1]) * 2;
}
 
int main()
{
  string sColor;

  input(sColor);
  cout << calcMaxRemove(sColor) << endl;

  return 0;
}
