#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnOrder)
{
  int nOrderSiz;
  cin >> nOrderSiz;
  rvnOrder.resize(nOrderSiz + 1);

  for (int nNo = 1; nNo < rvnOrder.size(); nNo++)
  {
    int nAttend;
    cin >> nAttend;
    rvnOrder[nAttend] = nNo;
  }
}

int fnOrderCheck(const vector<int>& cnrvnOrder)
{
  for (int n = 1; n < cnrvnOrder.size(); n++)
    cout << cnrvnOrder[n] << " ";

  cout << endl;
}

int main()
{
  vector<int> vnOrder;

  fnInput(vnOrder);
  fnOrderCheck(vnOrder);

  return 0;
}
