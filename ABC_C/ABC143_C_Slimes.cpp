#include <bits/stdc++.h>
using namespace std;

void input( string& rcolor )
{
  int colorSiz;
  cin >> colorSiz >> rcolor;
}

int calcColorCnt( string color )
{
  int colorCnt = 0;
  int fwd = 0;

  while ( fwd < color.size() )
  {
    while ( fwd < color.size() - 1      &&
            color[fwd] == color[fwd + 1]  )
      ++fwd;

    ++colorCnt;
    ++fwd;
  }
  return colorCnt;
}

int main()
{
  string color;

  input( color );
  cout << calcColorCnt( color ) << endl;

  return 0;
}
