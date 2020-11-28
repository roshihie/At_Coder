#include <bits/stdc++.h>
using namespace std;

void input(vector<vector<int>>& rvvnNum)
{
  for (int ny = 0; ny < rvvnNum.size(); ++ny)
    for (int nx = 0; nx < rvvnNum[ny].size(); ++nx)
      cin >> rvvnNum[ny][nx];
}

int isRight(const vector<vector<int>>& cnrvvnNum)
{
  vector<int> vnDx(2);

  for (int nx = 0; nx < cnrvvnNum[0].size() - 1; ++nx)
    vnDx[nx] = cnrvvnNum[0][nx + 1] - cnrvvnNum[0][nx];

  for (int ny = 1; ny < cnrvvnNum.size(); ++ny)
    for (int nx = 0; nx < cnrvvnNum[ny].size() - 1; ++nx)
      if (cnrvvnNum[ny][nx + 1] == cnrvvnNum[ny][nx] + vnDx[nx]);
      else
        return 0;

  return 1;
}

int main()
{
  vector<vector<int>> vvnNum(3, vector<int>(3));

  input(vvnNum);
  if (isRight(vvnNum)) cout << "Yes" << endl;
  else                 cout << "No"  << endl;

  return 0;
}
