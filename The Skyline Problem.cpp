class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        
        multimap<int, pair<int, int>> point;
        multiset<int, greater<int>> highestPoint;
        
        for (auto b:buildings) {
            point.insert({b[0], {b[2], 0}}); 
            point.insert({b[1], {b[2], 1}}); 
        }
        
        auto pointIter = point.begin();
        highestPoint.insert(0);
        while(pointIter != point.end()) {
            auto preHeight = *highestPoint.begin();
            int startPoint = pointIter->first;
            while(pointIter != point.end() && pointIter->first == startPoint) {
                bool isLeftPoint = pointIter->second.second == 0;
                auto height = pointIter->second.first;
                if (isLeftPoint) {
                    highestPoint.insert(height);
                } else {
                    highestPoint.erase(highestPoint.find(height));
                }
                ++pointIter;
            }
            
            auto newHeight = *highestPoint.begin();
            if (newHeight != preHeight) {
                ans.push_back({startPoint, newHeight});
            }
        }
        
        return ans;
    }
};
