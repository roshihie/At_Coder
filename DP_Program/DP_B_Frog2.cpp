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

  for (int nx = 0; nx < cnrvnStage.size() - 1; ++nx)
    for (int ny = 1; ny <= nJmpStage; ++ny)
      if (nx + ny < cnrvnStage.size())
        vnDPCost[nx + ny] = 
          min(vnDPCost[nx + ny], vnDPCost[nx] + abs(cnrvnStage[nx + ny] - cnrvnStage[nx]));
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
