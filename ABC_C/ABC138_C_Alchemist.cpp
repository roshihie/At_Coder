#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnValue)
{
  int nValueSiz;
  cin >> nValueSiz;
  rvnValue.resize(nValueSiz);

  for (int& rnValue : rvnValue)
    cin >> rnValue;
}
  
double calcMaxValue(const vector<int>& cnrvnValue)
{
  vector<int> vnSrtValue(cnrvnValue);
  sort(begin(vnSrtValue), end(vnSrtValue));

  double nMaxValue = vnSrtValue[0];

  for (int nx = 1; nx < vnSrtValue.size(); ++nx)
    nMaxValue = (nMaxValue + vnSrtValue[nx]) / 2;

  return nMaxValue;
}
  
int main()
{
  vector<int> vnValue;

  input(vnValue);
  cout << calcMaxValue(vnValue) << endl;

  return 0;
}
