#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnStage, int& rnJmpStage)
{
  int nStageSiz;
  cin >> nStageSiz >> rnJmpStage;
  rvnStage.resize(nStageSiz);

  for (int& rnStage : rvnStage)
    cin >> rnStage;
}
  
int fnDPCost(const vector<int>& cnrvnStage, int nJmpStage)
{
  vector<int> vnDPCost(cnrvnStage.size(), INT_MAX);
  vnDPCost[0] = 0;

  for (int i = 0; i < cnrvnStage.size() - 1; i++)
    for (int j = 1; j <= nJmpStage; j++)
      if (i + j < cnrvnStage.size())
        vnDPCost[i + j] = 
          min(vnDPCost[i + j], vnDPCost[i] + abs(cnrvnStage[i + j] - cnrvnStage[i]));
      else
        break;

  return vnDPCost[cnrvnStage.size() - 1];
}
  
int main()
{
  vector<int> vnStage;
  int nJmpStage;
  fnInput(vnStage, nJmpStage);
  cout << fnDPCost(vnStage, nJmpStage) << endl;

  return 0;
}
