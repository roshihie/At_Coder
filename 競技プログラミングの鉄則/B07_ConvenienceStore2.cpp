#include <bits/stdc++.h>
using namespace std;

struct StRange
{
  StRange() : m_left(0), m_right(0) { }

  int m_left;          // Left 日 1-origin
  int m_right;         // Right日 1-origin
};

void input(int& rclose, vector<StRange>& rvWork)
{
  int sizWork;
  cin >> rclose >> sizWork;
  rvWork.resize(sizWork);

  for (StRange& rWork : rvWork)
    cin >> rWork.m_left >> rWork.m_right;
}

void calcSumWork(int close, const vector<StRange>& crvWork)
{
                       // 時間  0 1 … T 
                       // 要素# 0 1 … T
  vector<int> vDiff(close + 1);

  for (StRange attend : crvWork)
  {
    ++vDiff[ attend.m_left  ];
    --vDiff[ attend.m_right ];
  }

  int sumWork = 0;

  for (int nx = 0; nx < close; ++nx)
  {
    sumWork += vDiff[nx];
    cout << sumWork << endl;
  }
  return;
}

int main()
{
  int close;
  vector<StRange> vWork;

  input(close, vWork);
  calcSumWork(close, vWork);

  return 0;
}
