#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<vector<int>>& rvvnEnjoy)
{
  int nEnjoySiz;
  cin >> nEnjoySiz;
  rvvnEnjoy.resize(nEnjoySiz, vector<int>(3));

  for (int i = 0; i < nEnjoySiz; i++)
    cin >> rvvnEnjoy[i][0] >> rvvnEnjoy[i][1] >> rvvnEnjoy[i][2];
}
  
int fnDPHappy(const vector<vector<int>>& cnrvvnEnjoy)
{
  vector<vector<int>> vvnDPHappy(cnrvvnEnjoy.size() + 1, vector<int>(cnrvvnEnjoy[0].size()));

  for (int i = 0; i < vvnDPHappy.size() - 1; i++)
    for (int j = 0; j < vvnDPHappy[i].size(); j++)
      for (int k = 0; k < vvnDPHappy[i].size(); k++)
        if (j != k)
          vvnDPHappy[i + 1][j] = max(vvnDPHappy[i + 1][j], vvnDPHappy[i][k] + cnrvvnEnjoy[i][j]);

  int nMaxHappy = 0;
  int nLastDay = vvnDPHappy.size() - 1;

  for (int j = 0; j < vvnDPHappy[nLastDay].size(); j++)
    nMaxHappy = max(nMaxHappy, vvnDPHappy[nLastDay][j]);

  return nMaxHappy;
}
  
int main()
{
  vector<vector<int>> vvnEnjoy;
  fnInput(vvnEnjoy);
  cout << fnDPHappy(vvnEnjoy) << endl;

  return 0;
}
