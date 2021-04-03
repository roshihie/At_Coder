#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnNum)
{
  string sNum;
  cin >> sNum;

  for (int nx = 0; nx < rvnNum.size(); ++nx)
    rvnNum[nx] = sNum[nx] - '0';       // char → int 変換
}

int calcFormulaEq7(const vector<int>& cnrvnNum)
{
  for (int nBit = 0; nBit < ( 1 << 3 ); ++nBit)
  {
    int nSum = cnrvnNum[0];

    for (int nEach = 0; nEach < 3; ++nEach)
                               // 1の位が op1, 10の位が op2, 100の位が op3 を表す
      if (nBit & ( 1 << nEach ))
        nSum += cnrvnNum[nEach + 1];
      else
        nSum -= cnrvnNum[nEach + 1];
                               // 必ず答えが存在するため nSum == 7 が存在 
    if (nSum == 7)
      return nBit;
  }
  return 7;                    // 必ず答えが存在するため ここには来ない
}
    
void outputRslt(const vector<int>& cnrvnNum, int nRslt)
{
  cout << cnrvnNum[0];

  for (int nEach = 0; nEach < 3; ++nEach)
  {
    if (nRslt & ( 1 << nEach )) cout << "+";
    else                        cout << "-";

    cout << cnrvnNum[nEach + 1];
  }
  cout << "=7" << endl;
}

int main()
{
  vector<int> vnNum(4);
  
  input(vnNum);
  int nRslt = calcFormulaEq7(vnNum);
  outputRslt(vnNum, nRslt);

  return 0;
}
