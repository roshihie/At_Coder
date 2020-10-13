#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnStairs)
{
  int nStairsSiz;
  cin >> nStairsSiz;
  rvnStairs.resize(nStairsSiz);

  for (int& rnStairs : rvnStairs)
    cin >> rnStairs;
}
  
string canNonDescStairs(const vector<int>& cnrvnStairs)
{
  int nCurMaxStair = cnrvnStairs[0];

  for (int nx = 1; nx < cnrvnStairs.size(); ++nx)
    if (nCurMaxStair - 1 > cnrvnStairs[nx])
      return "No";
    else if (nCurMaxStair < cnrvnStairs[nx])
      nCurMaxStair = cnrvnStairs[nx];

  return "Yes";
}
  
int main()
{
  vector<int> vnStairs;

  input(vnStairs);
  cout << canNonDescStairs(vnStairs) << endl;

  return 0;
}
