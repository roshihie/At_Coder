#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnValue)
{
  int nValueSiz;
  cin >> nValueSiz;
  rvnValue.resize(nValueSiz);

  for (int& rnValue : rvnValue)
    cin >> rnValue;
}
  
double fnMaxValueGet(const vector<int>& cnrvnValue)
{
  vector<int> vnAsdValue(cnrvnValue);
  sort(begin(vnAsdValue), end(vnAsdValue));

  double nMaxValue = vnAsdValue[0];
  for (int n = 1; n < vnAsdValue.size(); n++)
    nMaxValue = (nMaxValue + vnAsdValue[n]) / 2;

  return nMaxValue;
}
  
int main()
{
  vector<int> vnValue;

  fnInput(vnValue);
  cout << fnMaxValueGet(vnValue) << endl;

  return 0;
}
