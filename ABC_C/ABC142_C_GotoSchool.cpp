#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnOrder)
{
  int nOrderSiz;
  cin >> nOrderSiz;

  rvnOrder.resize(nOrderSiz + 1);
  for (int n = 1; n < rvnOrder.size(); n++)
  {
    int nOrder;
    cin >> nOrder;
    rvnOrder[nOrder] = n;
  }
}

int fnOrderCheck(const vector<int>& cnrvnOrder)
{
  for (int nOrder : cnrvnOrder)
    if (nOrder) cout << nOrder << " ";

  cout << endl;
}

int main()
{
  vector<int> vnOrder;

  fnInput(vnOrder);
  fnOrderCheck(vnOrder);

  return 0;
}
