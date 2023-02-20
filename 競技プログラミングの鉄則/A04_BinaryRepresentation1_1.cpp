#include <bits/stdc++.h>
using namespace std;

void input(int& rdec)
{
  cin >> rdec;
}

string convBinary(int dec)
{
  string str("0000000000");
  int nx = str.size() - 1;

  while ( dec )
  {
    if (dec % 2 == 0)
      str[nx--] = '0';
    else
      str[nx--] = '1';

    dec /= 2;
  }
  return str;
}

int main()
{
  int dec;

  input(dec);
  cout << convBinary(dec) << endl;

  return 0;
}
