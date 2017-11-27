class Solution {
public:
  vector<vector<int>> returnPowerSet(vector<int>& set){
      vector<vector<int>> res;
      int power_count = 1 << set.size();
      for ( int counter = 0; counter < power_count; ++ counter ){
          vector<int> temp
          for ( int i = 0; i < set.size(); ++ i )
              if ( counter & (1 << i) )
                temp.emplace_back(set[i]);
          res.emplace_back(temp);
      }
      return res;
  }
};
