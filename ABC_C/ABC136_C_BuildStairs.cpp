#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnStairs)
{
  int nStairsSiz;
  cin >> nStairsSiz;
  rvnStairs.resize(nStairsSiz);

  for (int& rnStairs : rvnStairs)
    cin >> rnStairs;
}
  
string fnNonDecrChk(const vector<int>& cnrvnStairs)
{
  int nMaxStairs = cnrvnStairs[0];

  for (int i = 0; i < cnrvnStairs.size() - 1; i++)
    if      (nMaxStairs - 1 > cnrvnStairs[i + 1])
      return "No";
    else if (cnrvnStairs[i] < cnrvnStairs[i + 1])
      nMaxStairs = cnrvnStairs[i + 1];

  return "Yes";
}
  
int main()
{
  vector<int> vnStairs;

  fnInput(vnStairs);
  cout << fnNonDecrChk(vnStairs) << endl;

  return 0;
}
