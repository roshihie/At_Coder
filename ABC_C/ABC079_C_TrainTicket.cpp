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
  for (int n = 0; n < (1 << 3) - 1; n++)
  {
    int nSum = cnrvnNum[0];
    for (int i = 0; i < 3; i++)
      if (n & (1 << i)) nSum += cnrvnNum[i + 1];
      else              nSum -= cnrvnNum[i + 1];

    if (nSum == 7)  return n;
  }
  return (1 << 3) - 1;                         // 必ず答えが存在するため
}
    
void fnResult(const vector<int>& cnrvnNum, int nReslt)
{
  cout << cnrvnNum[0];
  for (int i = 0; i < 3; i++)
  {
    if (nReslt & (1 << i)) cout << "+";
    else                   cout << "-";

    cout << cnrvnNum[i + 1];
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
