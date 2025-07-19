class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickm=0,pickp=0,pickg=0;
        int travelp=0,travelg=0,travelm=0;
        int lastp=0,lastm=0,lastg=0;

        for (int i=0;i<garbage.size();i++){

            string s = garbage[i];
            for(int j=0;j<s.size();j++){
                char ch=s[j];
                if (s[j]=='M'){
                    pickm++;
                    lastm=i;
                }
                if (s[j]=='P'){
                    pickp++;
                    lastp=i;
                }
                if (s[j]=='G'){
                    pickg++;
                    lastg=i;
                }
            }
        }
        for(int i=0;i<lastm;i++){
            travelm=travelm+travel[i];
        }
        for(int i=0;i<lastg;i++){
            travelg=travelg+travel[i];
        }
        for(int i=0;i<lastp;i++){
            travelp=travelp+travel[i];
        }
        int ans=(pickm+travelm)+(pickg+travelg)+(pickp+travelp);
        return ans;
        
    }
};