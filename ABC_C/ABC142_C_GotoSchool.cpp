#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnOrder)
{
  int nOrderSiz;
  cin >> nOrderSiz;
  rvnOrder.resize(nOrderSiz);

  for (int nx = 0; nx < rvnOrder.size(); ++nx)
  {
    int nOrder;
    cin >> nOrder;
    rvnOrder[--nOrder] = nx + 1;
  }
}

void calcOrder(const vector<int>& cnrvnOrder)
{
  for (int nOrder : cnrvnOrder)
    cout << nOrder << " ";

  cout << endl;
}

int main()
{
  vector<int> vnOrder;

  input(vnOrder);
  calcOrder(vnOrder);

  return 0;
}
