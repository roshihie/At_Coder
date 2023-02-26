#include <bits/stdc++.h>
using namespace std;

struct StRange
{
  StRange() : m_left(0), m_right(0) { }

  int m_left;          // Left 日 1-origin
  int m_right;         // Right日 1-origin
};

void input(int& rdays, vector<StRange>& rvCount)
{
  int sizCount;
  cin >> rdays >> sizCount;
  rvCount.resize(sizCount);

  for (StRange& rCount : rvCount)
    cin >> rCount.m_left >> rCount.m_right;
}

void calcSumDays(int days, const vector<StRange>& crvCount)
{
                       // 日      1 2 … D 
                       // 要素# 0 1 2 … D D+1
  vector<int> vDiff(days + 2);

  for (StRange attend : crvCount)
  {
    ++vDiff[ attend.m_left ];
    --vDiff[ attend.m_right + 1 ];
  }

  int sumDays = 0;

  for (int nx = 1; nx <= days; ++nx)
  {
    sumDays += vDiff[nx];
    cout << sumDays << endl;
  }
  return;
}

int main()
{
  int days;
  vector<StRange> vCount;

  input(days, vCount);
  calcSumDays(days, vCount);

  return 0;
}
