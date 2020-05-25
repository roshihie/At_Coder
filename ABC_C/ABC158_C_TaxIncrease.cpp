#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnTax8per, int& rnTax10per)
{
  cin >> rnTax8per >> rnTax10per;
}
  
int fnNonTaxKinGet(int nTax8per, int nTax10Per)
{
  vector<int> vnNonTaxKin(10);

  int nNonTax10per = nTax10Per * 10;
  for (int i = 0; i < vnNonTaxKin.size(); i++)
    vnNonTaxKin[i] = nNonTax10per++;

  for (int i = 0; i < vnNonTaxKin.size(); i++)
  {
    int nCalTax8per = vnNonTaxKin[i] * 0.08;
    if (nCalTax8per == nTax8per)
      return vnNonTaxKin[i];
  }
  return -1;
}
  
int main()
{
  int nTax8per, nTax10Per;

  fnInput(nTax8per, nTax10Per);
  cout << fnNonTaxKinGet(nTax8per, nTax10Per) << endl;

  return 0;
}
