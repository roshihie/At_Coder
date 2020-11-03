#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnLife)
{
  int nLiftSiz;
  cin >> nLiftSiz;
  rvnLife.resize(nLiftSiz);

  for (int& rnLife : rvnLife)
    cin >> rnLife;
}

int calcGcd(int nOne, int nOtr)
{
  if ( !nOtr ) return nOne;
  return calcGcd(nOtr, nOne % nOtr);
}

int calcMinLife(const vector<int>& cnrvnLife)
{
  int nMinLife = cnrvnLife[0];

  for (int i = 1; i < cnrvnLife.size(); i++)
    nMinLife = calcGcd(nMinLife, cnrvnLife[i]);

  return nMinLife;
}
 
int main()
{
  vector<int> vnLife;

  input(vnLife);
  cout << calcMinLife(vnLife) << endl;

  return 0;
}
