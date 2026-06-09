class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int curr1 = 0;
        int curr2 = 0;
        int curr3 = 0;
        for(int x: bills){
            if(x==5) curr1 += 1;
            else if(x == 10){
                if(curr1 == 0) return false;
                curr1--;
                curr2++;
            }
            else{
                // if(curr1<3 || (curr2<1) ) return false;
                if (curr2>0 && curr1>0) curr1--,curr2--;
                else if (curr1>=3) curr1-=3;
                else return false;
                // curr1--,curr2--,curr3++;
                curr3++;
            }
        }
        return true;
    }
};