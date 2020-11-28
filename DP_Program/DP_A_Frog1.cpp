#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnStage)
{
  int nStageSiz;
  cin >> nStageSiz;
  rvnStage.resize(nStageSiz);

  for (int& rnStage : rvnStage)
    cin >> rnStage;
}
  
int fnDPCost(const vector<int>& cnrvnStage)
{
  vector<int> vnDPCost(cnrvnStage.size(), INT_MAX);
  vnDPCost[0] = 0;

  for (int nx = 1; nx < cnrvnStage.size(); ++nx)
  {
    vnDPCost[nx] = min(vnDPCost[nx], vnDPCost[nx - 1] + abs(cnrvnStage[nx] - cnrvnStage[nx - 1]));
    if (nx > 1)
      vnDPCost[nx] = min(vnDPCost[nx], vnDPCost[nx - 2] + abs(cnrvnStage[nx] - cnrvnStage[nx - 2]));
  }

  return vnDPCost[cnrvnStage.size() - 1];
}
  
int main()
{
  vector<int> vnStage;

  fnInput(vnStage);
  cout << fnDPCost(vnStage) << endl;

  return 0;
}
