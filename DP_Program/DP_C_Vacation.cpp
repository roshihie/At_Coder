#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<vector<int>>& rvvnEnjoy)
{
  int nEnjoySiz;
  cin >> nEnjoySiz;
  rvvnEnjoy.resize(nEnjoySiz, vector<int>(3));

  for (int nx = 0; nx < nEnjoySiz; ++nx)
    cin >> rvvnEnjoy[nx][0] >> rvvnEnjoy[nx][1] >> rvvnEnjoy[nx][2];
}
  
int fnDPHappy(const vector<vector<int>>& cnrvvnEnjoy)
{
  vector<vector<int>> vvnDPHappy(cnrvvnEnjoy.size() + 1, vector<int>(cnrvvnEnjoy[0].size()));

  for (int nx = 0; nx < cnrvvnEnjoy.size(); ++nx)
    for (int ny = 0; ny < cnrvvnEnjoy[nx].size(); ++ny)
      for (int nz = 0; nz < cnrvvnEnjoy[nx].size(); ++nz)
        if (ny != nz)
          vvnDPHappy[nx + 1][ny] = max(vvnDPHappy[nx + 1][ny], 
                                       vvnDPHappy[nx][nz] + cnrvvnEnjoy[nx][ny]);

  int nMaxHappy = 0;
  int nLastDay = vvnDPHappy.size() - 1;

  for (int ny = 0; ny < vvnDPHappy[nLastDay].size(); ++ny)
    nMaxHappy = max(nMaxHappy, vvnDPHappy[nLastDay][ny]);

  return nMaxHappy;
}
  
int main()
{
  vector<vector<int>> vvnEnjoy;
  fnInput(vvnEnjoy);
  cout << fnDPHappy(vvnEnjoy) << endl;

  return 0;
}
