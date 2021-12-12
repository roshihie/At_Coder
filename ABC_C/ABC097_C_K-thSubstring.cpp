#include <bits/stdc++.h>
using namespace std;

void input( string& rstr, int& rnumKth )
{
  cin >> rstr >> rnumKth;
}

string calcKthSubstr( string str, int numKth )
{
  int size = (int)str.size();
  set<string> seSubstr;

  for ( int pos = 0; pos < size; ++pos )
  {
    int len = 1;

    while ( len <= 5         &&
            pos + len <= size  )
    {
      seSubstr.insert( str.substr( pos, len ));
      ++len;
    }
  }
  int cnt = 0;

  for ( auto substrKth : seSubstr )
    if ( ++cnt == numKth )
      return substrKth;
    else;
}
  
int main()
{
  string str;
  int numKth;

  input( str, numKth );
  cout << calcKthSubstr( str, numKth ) << endl;

  return 0;
}
