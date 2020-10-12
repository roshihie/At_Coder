#include <bits/stdc++.h>
using namespace std;

void input(int& rnLen)
{
  cin >> rnLen;
}
  
double calcMaxVolume(int nLen)
{
  double nOneSide = nLen / 3.0;
  return nOneSide * nOneSide * nOneSide;
}
  
int main()
{
  int nLen;

  input(nLen);
  cout << fixed << setprecision(10) << calcMaxVolume(nLen) << endl;

  return 0;
}
