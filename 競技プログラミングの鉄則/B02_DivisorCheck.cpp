#include <bits/stdc++.h>
using namespace std;

void input(int& rmin, int& rmax)
{
  cin >> rmin >> rmax;
}

string isDivisor100(int min, int max)
{
  for (int divisor = min; divisor <= max; ++divisor)
    if ( 100 % divisor == 0 ) return "Yes";

  return "No";
}

int main()
{
  int min, max;

  input(min, max);
  cout << isDivisor100(min, max) << endl;

  return 0;
}
