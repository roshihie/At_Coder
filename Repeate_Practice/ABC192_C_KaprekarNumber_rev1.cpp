#include <bits/stdc++.h>
using namespace std;

void input(int& rnum, int& rterm)
{
  cin >> rnum >> rterm;
}

int calcNum(const vector<int>& crvDigit)
{
  int num = 0;

  for (int digit : crvDigit)
  {
    num *= 10;
    num += digit;
  }
  return num;
}

int calcDigitNum(int num)
{
  vector<int> vDigit;

  while ( num )
  {
    vDigit.push_back( num % 10 );
    num /= 10;
  }
  sort(begin(vDigit), end(vDigit));
  int min = calcNum(vDigit);
  reverse(begin(vDigit), end(vDigit));
  int max = calcNum(vDigit);

  return max - min;
}

int calcMaxMinDiff(int num, int term)
{
  for (int nx = 1; nx <= term; ++nx)
    num = calcDigitNum(num);

  return num;
}
  
int main()
{
  int num, term;
  input(num, term);
  cout << calcMaxMinDiff(num, term);

  return 0;
}
