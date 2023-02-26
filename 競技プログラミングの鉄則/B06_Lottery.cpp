#include <bits/stdc++.h>
using namespace std;

struct StQuery
{
  StQuery() : m_left(0), m_right(0) { }

  int m_left;          // Left 日 1-origin
  int m_right;         // Right日 1-origin
};

void input(vector<int>& rvGame, 
           vector<StQuery>& rvQuery)
{
  int sizGame;
  cin >> sizGame;
  rvGame.resize(sizGame + 1);
                       // 回数    1 2 … N 
                       // 要素# 0 1 2 … N
  for (int nx = 1; nx < rvGame.size(); ++nx)
    cin >> rvGame[nx];

  int sizQuery;
  cin >> sizQuery;
  rvQuery.resize(sizQuery);

  for (StQuery& rQuery : rvQuery)
    cin >> rQuery.m_left >> rQuery.m_right;
}

void calcQuery(const vector<int>& crvGame,
               const vector<StQuery>& crvQuery)
{
                       // 回数    1 2 … N 
                       // 要素# 0 1 2 … N
  vector<int> vWinSum ( crvGame.size() );
  vector<int> vLoseSum( crvGame.size() );

  for (int nx = 1; nx < crvGame.size(); ++nx)
  {
    vWinSum[nx]  = vWinSum[nx - 1];
    vLoseSum[nx] = vLoseSum[nx - 1];

    if (crvGame[nx] == 1) ++vWinSum[nx];
    if (crvGame[nx] == 0) ++vLoseSum[nx];
  }

  for (StQuery oQuery : crvQuery)
  {
    int cntWin  = vWinSum[ oQuery.m_right ] - vWinSum[ oQuery.m_left - 1];
    int cntLose = vLoseSum[ oQuery.m_right ] - vLoseSum[ oQuery.m_left - 1];
    
    if      (cntWin > cntLose) cout << "win"  << endl;
    else if (cntWin < cntLose) cout << "lose" << endl;
    else                       cout << "draw" << endl;
  }

  return;
}

int main()
{
  vector<int> vGame;
  vector<StQuery> vQuery;

  input(vGame, vQuery);
  calcQuery(vGame, vQuery);

  return 0;
}
