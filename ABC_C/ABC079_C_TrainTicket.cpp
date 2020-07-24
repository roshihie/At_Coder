#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnNum)
{
  string sNum;
  cin >> sNum;

  for (int i = 0; i < rvnNum.size(); i++)
    rvnNum[i] = sNum[i] - '0';                 // char → int 変換
}

int fnBitFullSch(const vector<int>& cnrvnNum)
{
  for (int nCtl = 0; nCtl < ( 1 << 3 ) - 1; nCtl++)
  {
    int nSum = cnrvnNum[0];
    for (int nEach = 0; nEach < 3; nEach++)
      if (nCtl & ( 1 << nEach )) nSum += cnrvnNum[nEach + 1];
      else                       nSum -= cnrvnNum[nEach + 1];

    if (nSum == 7)  return nCtl;
  }
  return ( 1 << 3 ) - 1;                       // 必ず答えが存在するため
}
    
void fnResult(const vector<int>& cnrvnNum, int nReslt)
{
  cout << cnrvnNum[0];
  for (int nEach = 0; nEach < 3; nEach++)
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
  
  fnInput(vnNum);
  int nReslt = fnBitFullSch(vnNum);
  fnResult(vnNum, nReslt);

  return 0;
}
