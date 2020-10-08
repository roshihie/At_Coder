#include <bits/stdc++.h>
using namespace std;

struct StCity
{
  StCity() : m_nPref(0), m_nYear(0) { }

  int m_nPref;
  int m_nYear;
};

void input(int& rnPrefSiz, vector<StCity>& rvoCity)
{
  int nCitySiz;
  cin >> rnPrefSiz >> nCitySiz;
  rvoCity.resize(nCitySiz);

  for (StCity& roCity : rvoCity)
  {
    cin >> roCity.m_nPref >> roCity.m_nYear;
    --roCity.m_nPref;
  }
}

void calcIDNum(int nPrefSiz, const vector<StCity>& cnrvoCity)
{
  vector<vector<int>> vvnCity(nPrefSiz);
                                           // vvnCity[ nPref ] に nYear を保存 
  for (int nx = 0; nx < cnrvoCity.size(); ++nx)
    vvnCity[ cnrvoCity[nx].m_nPref ].push_back( cnrvoCity[nx].m_nYear );

  for (int nx = 0; nx < vvnCity.size(); ++nx)
  {                                        // vvnCity[ nPref ] 毎に nYear を昇順に sort
    sort( begin(vvnCity[nx]), end(vvnCity[nx]) );
                                           // vvnCity[ nPref ] 毎に nYear の重複を除く
    vvnCity[nx].erase( unique( begin(vvnCity[nx]), end(vvnCity[nx]) ), end(vvnCity[nx]) );
  }

  for (int nx = 0; nx < cnrvoCity.size(); ++nx)
  {
    int nPref = cnrvoCity[nx].m_nPref;
    cout << setfill('0') << setw(6) << nPref + 1;
                   // nYear で sort済の vvnCity[ nPref ] に対して、求める nYear を二分索引して
                   // イテレータを算出し、vvnCity[ nPref ]の begin イテレータを削除し、
                   // nYear が小さい方から何番目かを取得する
    int nIdNum = lower_bound( begin( vvnCity[ nPref ] ), end( vvnCity[ nPref ] ), 
                              cnrvoCity[nx].m_nYear ) - begin( vvnCity[ nPref ] ); 
    cout << setfill('0') << setw(6) << nIdNum + 1 << endl;
  }
}
  
int main()
{
  int nPrefSiz;
  vector<StCity> voCity;
  
  input(nPrefSiz, voCity);
  calcIDNum(nPrefSiz, voCity);

  return 0;
}
