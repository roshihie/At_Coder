#include <bits/stdc++.h>
using namespace std;

void input(int& rmax, int& rtrg)
{
  cin >> rmax >> rtrg;
}

int calcNumCase(int max, int trg)
{
  int numCase = 0;

  for (int nx = 1; nx <= max; ++nx)
    for (int ny = 1; ny <= max; ++ny)
      if ( trg - ( nx + ny ) >= 1  &&
           trg - ( nx + ny ) <= max  )
        ++numCase;

  return numCase;
}

int main()
{
  int max, trg;

  input(max, trg);
  cout << calcNumCase(max, trg) << endl;

  return 0;
}
