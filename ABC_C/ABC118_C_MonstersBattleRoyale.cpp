#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnLife)
{
  int nLiftSiz;
  cin >> nLiftSiz;
  rvnLife.resize(nLiftSiz);

  for (int& rnLife : rvnLife)
    cin >> rnLife;
}

int fnGcd(int nOne, int nOtr)
{
  if (nOtr == 0)
    return nOne;
  else
    return fnGcd(nOtr, nOne % nOtr);
}

int fnMinLife(const vector<int>& cnrvnLife)
{
  int nMinLife = cnrvnLife[0];

  for (int i = 1; i < cnrvnLife.size(); i++)
    nMinLife = fnGcd(nMinLife, cnrvnLife[i]);

  return nMinLife;
}
 
int main()
{
  vector<int> vnLife;

  fnInput(vnLife);
  cout << fnMinLife(vnLife) << endl;

  return 0;
}
