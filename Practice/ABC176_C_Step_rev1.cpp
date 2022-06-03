#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<int>& rvnHigh)
{
  int nHighSiz;
  cin >> nHighSiz;
  rvnHigh.resize(nHighSiz);

  for (int& rnHigh : rvnHigh)
    cin >> rnHigh;
}

llong calcMinStepHigh(vector<int>& rvnHigh)
{
  llong nMinStepHigh = 0;

  for (int nx = 0; nx < rvnHigh.size() - 1; ++nx)
    if (rvnHigh[nx] > rvnHigh[nx + 1])
    {
      nMinStepHigh += rvnHigh[nx] - rvnHigh[nx + 1];
      rvnHigh[nx + 1] = rvnHigh[nx];
    }

  return nMinStepHigh;
}
  
int main()
{
  vector<int> vnHigh;
  
  input(vnHigh);
  cout << calcMinStepHigh(vnHigh) << endl;

  return 0;
}
