#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnAmount)
{
  cin >> rnAmount;
}

int fnAmtCheck(int nAmount)
{
  const int cnnCake = 4;
  const int cnnDonut = 7;

  int nCake = 0;
  while (true)
  {
    int nAmtCake = cnnCake * nCake;
    if (nAmtCake > nAmount)       return 0;

    int nRestAmt = nAmount - nAmtCake;
    if (nRestAmt % cnnDonut == 0) return 1;
    nCake++;
  }
}

int main()
{
  int nAmount;

  fnInput(nAmount);
  if (fnAmtCheck(nAmount)) cout << "Yes" << endl;
  else                       cout << "No"  << endl;

  return 0;
}
