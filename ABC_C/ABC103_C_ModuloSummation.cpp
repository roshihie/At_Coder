#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnNum)
{
  int nNumSiz;
  cin >> nNumSiz;
  rvnNum.resize(nNumSiz);

  for (int& rnNum : rvnNum)
    cin >> rnNum;
}

int calcRemainSum(const vector<int>& cnrvnNum)
{
  int nRemainSum = 0;

  for (int nNum : cnrvnNum)
    nRemainSum += nNum - 1;

  return nRemainSum;
}

int main()
{
  vector<int> vnNum;

  input(vnNum);
  cout << calcRemainSum(vnNum) << endl;

  return 0;
}
