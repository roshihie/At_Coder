#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnNum, int& rnMin, int& rnMax)
{
  cin >> rnNum >> rnMin >> rnMax;
}


void fnSomeSums(int nNum, int nMin, int nMax, int& rnSum)
{
  for (int i = 1; i <= nNum; i++)
  {
    int n1Place    = i % 10;
    int n10Place   = i % 100 - n1Place;
    int n100Place  = i % 1000 - (n100Place * 10 + n1Place);
    int n1000Place = i / 1000;

    if (n1000Place + n100Place + n10Place + n1Place >= nMin &&
        n1000Place + n100Place + n10Place + n1Place <= nMax   )
      rnSum += i;
  }
}

int main()
{
  int nNum, nMin, nMax;
  int nSum = 0;

  fnInput(nNum, nMin, nMax);
  fnSomeSums(nNum, nMin, nMax, nSum);
  cout << nSum << endl;

  return 0;
}
 
