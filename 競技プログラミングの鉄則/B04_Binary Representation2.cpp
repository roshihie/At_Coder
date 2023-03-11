#include <bits/stdc++.h>
using namespace std;

void input(int& rbin)
{
  cin >> rbin;
}

int convDecimal(int bin)
{
  int dec = 0;
  int base = 0;

  while ( bin )
  {
    int rem = bin % 10;
    bin /= 10;
    dec += rem * ( 1 << base++ );
  }
  return dec;
}

int main()
{
  int bin;

  input(bin);
  cout << convDecimal(bin) << endl;

  return 0;
}
