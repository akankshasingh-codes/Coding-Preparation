class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b)
    {
        return a[1] >= b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        //sorting in desending order
        sort(boxTypes.begin(),boxTypes.end(),comp);

        int unit = 0;
        int n = boxTypes.size();

        for(int i = 0;i<n;i++)
        {
            if(truckSize == 0) break;
            else if(boxTypes[i][0] <= truckSize)
            {
                unit += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else //trucksize is less than given box
            {
                unit += truckSize*boxTypes[i][1];
                truckSize = 0;

            }
        }
        return unit;
        //t.c = 0(nlogn + n)
        //s.c = 0(1)

        
    }
};