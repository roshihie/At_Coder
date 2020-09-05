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

  for (int i = 0; i < rvnHigh.size() - 1; ++i)
    if (rvnHigh[i] - rvnHigh[i + 1] > 0)
    {
      nMinStepHigh += rvnHigh[i] - rvnHigh[i + 1];
      rvnHigh[i + 1] = rvnHigh[i];
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
