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
    int rem = num % base;
    if ( rem == 7 ) return true;
    num /= base;
  }
  return false;
}

int calcNotInclude7(int num)
{
  int notIncude7 = 0;

  for (int nx = 1; nx <= num; ++nx)
  {
    if ( isInclude7(nx, 10)) continue;
    if ( isInclude7(nx,  8)) continue;
    ++notIncude7;
  }
  return notIncude7;
}
  
int main()
{
  int num;
  input(num);
  cout << calcNotInclude7(num) << endl;

  return 0;
}
