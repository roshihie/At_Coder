#include <bits/stdc++.h>
using namespace std;

void input(vector<vector<int>>& rvvnNum)
{
  for (int i = 0; i < rvvnNum.size(); i++)
    for (int j = 0; j < rvvnNum[i].size(); j++)
      cin >> rvvnNum[i][j];
}

int isRight(const vector<vector<int>>& cnrvvnNum)
{
  vector<int> vnDx(2);

  for (int j = 0; j < cnrvvnNum[0].size() - 1; j++)
    vnDx[j] = cnrvvnNum[0][j + 1] - cnrvvnNum[0][j];

  for (int i = 1; i < cnrvvnNum.size(); i++)
    for (int j = 0; j < cnrvvnNum[i].size() - 1; j++)
      if (cnrvvnNum[i][j + 1] == cnrvvnNum[i][j] + vnDx[j]);
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
