#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(vector<int>& rvnHigh)
{
  int nHighSiz;
  cin >> nHighSiz;
  rvnHigh.resize(nHighSiz);

  for (int& rnHigh : rvnHigh)
    cin >> rnHigh;
}

llong fnMinStepHigh(vector<int>& rvnHigh)
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
  
  fnInput(vnHigh);
  cout << fnMinStepHigh(vnHigh) << endl;

  return 0;
}
