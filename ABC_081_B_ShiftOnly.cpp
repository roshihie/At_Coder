#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int N;
  cin >> N;

  vector<int> vnNum(N);

  for (int i = 0; i < N; i++)
    cin >> vnNum[i];

  int nCount = -1;
  bool bLoop = true;

  while (bLoop)
  {
    nCount++;
    for (int& num : vnNum)
    {
      if (num % 2 != 0)
      {
        bLoop = false;
        break;
      }
      else
        num /= 2;
    }
  }

  cout << nCount << endl;
  return 0;
}
