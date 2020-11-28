#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  string s;
  cin >> s;

  int count = 0;
  for (int nx = 0; nx < s.size(); ++nx)
    if (s[nx] == '1') count++;

   cout << count << endl;
   return 0;
}
