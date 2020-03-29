#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnEnjoyA, vector<int>& rvnEnjoyB, vector<int>& rvnEnjoyC)
{
  int nEnjoySiz;
  cin >> nEnjoySiz;
  rvnEnjoyA.resize(nEnjoySiz);
  rvnEnjoyB.resize(nEnjoySiz);
  rvnEnjoyC.resize(nEnjoySiz);

  for (int i = 0; i < nEnjoySiz; i++)
    cin >> rvnEnjoyA[i] >> rvnEnjoyB[i] >> rvnEnjoyC[i];
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
  vector<int> vnEnjoyA, vnEnjoyB, vnEnjoyC;
  fnInput(vnEnjoyA, vnEnjoyB, vnEnjoyC);
  cout << fnDPCost(vnStage, nJmpStage) << endl;

  return 0;
}
