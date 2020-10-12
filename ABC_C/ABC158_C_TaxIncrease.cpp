#include <bits/stdc++.h>
using namespace std;

void input(int& rnTax8per, int& rnTax10per)
{
  cin >> rnTax8per >> rnTax10per;
}
  
int calcNonTaxPrice(int nTax8per, int nTax10Per)
{
  vector<int> vnNonTaxPrc(10);
  int nNonTaxP10per = nTax10Per * 10;

  for (int nx = 0; nx < vnNonTaxPrc.size(); ++nx)
    vnNonTaxPrc[nx] = nNonTaxP10per++;

  for (int nx = 0; nx < vnNonTaxPrc.size(); ++nx)
  {
    int nCalTaxP8per = vnNonTaxPrc[nx] * 0.08;
    if (nCalTaxP8per == nTax8per)
      return vnNonTaxPrc[nx];
  }
  return -1;
}
  
int main()
{
  int nTax8per, nTax10Per;

  input(nTax8per, nTax10Per);
  cout << calcNonTaxPrice(nTax8per, nTax10Per) << endl;

  return 0;
}
