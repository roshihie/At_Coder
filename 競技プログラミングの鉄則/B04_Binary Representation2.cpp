#include <bits/stdc++.h>
using namespace std;        実行未済

void input(int& rdec)
{
  cin >> rdec;
}

void convBinary(int dec)
{
  for (int nx = 9; nx >= 0; --nx)
    cout << ( dec / ( 1 << nx )) % 2;

  cout << endl;
}

int main()
{
  int dec;

  input(dec);
  convBinary(dec);

  return 0;
}
