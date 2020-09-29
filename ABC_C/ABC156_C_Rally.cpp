#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnRally)
{
  int nRallySiz;
  cin >> nRallySiz;
  rvnRally.resize(nRallySiz);

  for (int& rnRally : rvnRally)
    cin >> rnRally;
}
  
int calcMinCost(const vector<int>& cnrvnRally)
{
  int nAverage = (double)accumulate(begin(cnrvnRally), end(cnrvnRally), 0) / cnrvnRally.size() + 0.5;
  int nCost = 0;

  for (int nRally : cnrvnRally)
    nCost += (nAverage - nRally) * (nAverage - nRally);

  return nCost;
}
  
int main()
{
  vector<int> vnRally;

  input(vnRally);
  cout << calcMinCost(vnRally) << endl;

  return 0;
}
