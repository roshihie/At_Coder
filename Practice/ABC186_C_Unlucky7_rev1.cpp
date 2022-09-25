#include <bits/stdc++.h>
using namespace std;

void input(int& rnum)
{
  cin >> rnum;
}

bool isInclude7(int num, int base)
{
  while ( num )
  {
    if (num % base == 7)
      return true;

    num /= base;
  }
  return false;
}

int calcNotInclude7(int num)
{
  int cntNotInclude7 = 0;

  for (int nx = 1; nx <= num; ++nx)
  {
    if ( isInclude7(nx, 10)) continue;
    if ( isInclude7(nx,  8)) continue;

    ++cntNotInclude7;
  }
  return cntNotInclude7;
}
  
int main()
{
  int num;
  input(num);
  cout << calcNotInclude7(num) << endl;

  return 0;
}
