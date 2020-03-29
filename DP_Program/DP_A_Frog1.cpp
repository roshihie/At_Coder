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

  for (int i = 1; i < cnrvnStage.size(); i++)
  {
    vnDPCost[i] = min(vnDPCost[i], vnDPCost[i - 1] + abs(cnrvnStage[i] - cnrvnStage[i - 1]));
    if (i > 1)
      vnDPCost[i] = min(vnDPCost[i], vnDPCost[i - 2] + abs(cnrvnStage[i] - cnrvnStage[i - 2]));
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
