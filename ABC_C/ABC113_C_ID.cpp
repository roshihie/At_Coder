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
  for (int i = 0; i < cnrvoCity.size(); ++i)
    vvnCity[ cnrvoCity[i].m_nPref ].push_back( cnrvoCity[i].m_nYear );

  for (int i = 0; i < vvnCity.size(); ++i)
  {                                        // vvnCity[ nPref ] 毎に nYear を昇順に sort
    sort( begin(vvnCity[i]), end(vvnCity[i]) );
                                           // vvnCity[ nPref ] 毎に nYear の重複を除く
    vvnCity[i].erase( unique( begin(vvnCity[i]), end(vvnCity[i]) ), end(vvnCity[i]) );
  }

  for (int i = 0; i < cnrvoCity.size(); ++i)
  {
    int nPref = cnrvoCity[i].m_nPref;
    cout << setfill('0') << setw(6) << nPref + 1;
                   // nYear で sort済の vvnCity[ nPref ] に対して、求める nYear を二分索引して
                   // イテレータを算出し、vvnCity[ nPref ]の begin イテレータを削除し、
                   // nYear が小さい方から何番目かを取得する
    int nIdNum = lower_bound( begin( vvnCity[ nPref ] ), end( vvnCity[ nPref ] ), 
                              cnrvoCity[i].m_nYear ) - begin( vvnCity[ nPref ] ); 
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
