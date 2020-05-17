class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2) return true;
        if((coordinates[0][0]-coordinates[1][0]) != 0){
            float slope=(float)(coordinates[0][1]-coordinates[1][1])/(coordinates[0][0]-coordinates[1][0]);
            for(int i=1;i<coordinates.size()-1;++i){
                if((coordinates[i][0]-coordinates[i+1][0]) == 0) return false;
                else{
                    float tmpSlope=(float)(coordinates[i][1]-coordinates[i+1][1])/(coordinates[i][0]-coordinates[i+1][0]);
                    if(tmpSlope != slope)
                        return false;
                }
            }
            return true;
        }else{      // Infinite Slope
            int xVal=coordinates[0][0];
            for(int i=1;i<coordinates.size();++i)
                if(coordinates[i][0]!=xVal)
                    return false;
            return true;
        }
    }
};