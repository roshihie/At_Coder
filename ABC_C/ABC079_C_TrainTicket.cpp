#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnNum)
{
  string sNum;
  cin >> sNum;

  for (int nx = 0; nx < rvnNum.size(); ++nx)
    rvnNum[nx] = sNum[nx] - '0';       // char → int 変換
}

int exhstSearch(const vector<int>& cnrvnNum)
{                              // 必ず答えが存在するため 最終の１つ前まででループ終了
  for (int nCtl = 0; nCtl < ( 1 << 3 ) - 1; ++nCtl)
  {
    int nSum = cnrvnNum[0];

    for (int nEach = 0; nEach < 3; ++nEach)
      if (nCtl & ( 1 << nEach )) nSum += cnrvnNum[nEach + 1];
      else                       nSum -= cnrvnNum[nEach + 1];

    if (nSum == 7)  return nCtl;
  }
  return ( 1 << 3 ) - 1;       // 必ず答えが存在するため 最終が求める答え
}
    
void outputReslt(const vector<int>& cnrvnNum, int nReslt)
{
  cout << cnrvnNum[0];

  for (int nEach = 0; nEach < 3; ++nEach)
  {
    if (nReslt & ( 1 << nEach )) cout << "+";
    else                         cout << "-";

    cout << cnrvnNum[nEach + 1];
  }
  cout << "=7" << endl;
}

int main()
{
  vector<int> vnNum(4);
  
  input(vnNum);
  int nReslt = exhstSearch(vnNum);
  outputReslt(vnNum, nReslt);

  return 0;
}
