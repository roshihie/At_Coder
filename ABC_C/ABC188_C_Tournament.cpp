#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnPlayer)
{
  int nPlayerPower;
  cin >> nPlayerPower;
  rvnPlayer.resize( 1 << nPlayerPower );

  for (int& rnPlayer : rvnPlayer)
    cin >> rnPlayer;
}

int calc2ndPlayer(const vector<int>& cnrvnPlayer)
{
  auto it1stHalf = max_element( begin(cnrvnPlayer), 
                                begin(cnrvnPlayer) + cnrvnPlayer.size() / 2 );
  auto it2ndHalf = max_element( begin(cnrvnPlayer) + cnrvnPlayer.size() / 2, 
                                end(cnrvnPlayer) );

  if (*it1stHalf < *it2ndHalf)
    return it1stHalf - begin(cnrvnPlayer) + 1;
  else
    return it2ndHalf - begin(cnrvnPlayer) + 1;
}
  
int main()
{
  vector<int> vnPlayer;
  input(vnPlayer);
  cout << calc2ndPlayer(vnPlayer) << endl;

  return 0;
}
