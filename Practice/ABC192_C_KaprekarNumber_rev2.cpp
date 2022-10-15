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
    num = num * 10 + digit;

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
  int maxMinDiff = num;

  for (int nx = 0; nx < term; ++nx)
    maxMinDiff = calcDigitNum(maxMinDiff);

  return maxMinDiff;
}
  
int main()
{
  int num, term;
  input(num, term);
  cout << calcMaxMinDiff(num, term) << endl;

  return 0;
}
