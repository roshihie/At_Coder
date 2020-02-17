#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<double>& rvnValue)
{
  int nValueSiz;
  cin >> nValueSiz;
  rvnValue.resize(nValueSiz);

  for(double& rnValue : rvnValue)
    cin >> rnValue;
}
  
double fnMaxValueGet(const vector<double>& cnrvnValue)
{
  vector<double> vnAscValue(cnrvnValue);

  while (vnAscValue.size() > 1)
  {
    sort(begin(vnAscValue), end(vnAscValue));
    auto it = begin(vnAscValue);
    double nAveValue = ( *it + *(it + 1) ) / 2;

    vnAscValue.erase(it, it + 2);
    vnAscValue.push_back(nAveValue);
  }
  return vnAscValue[0];
}
  
int main()
{
  vector<double> vnValue;

  fnInput(vnValue);
  cout << fnMaxValueGet(vnValue) << endl;

  return 0;
}
