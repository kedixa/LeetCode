class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>v1, v2;
        istringstream iss1(version1);
        int ver;
        char dot;
        while(iss1 >> ver) {
            if(iss1.fail()) break;
            v1.push_back(ver);
            iss1 >> dot;
        }
        istringstream iss2(version2);
        while(iss2 >> ver) {
            if(iss2.fail()) break;
            v2.push_back(ver);
            iss2 >> dot;
        }
        while(!v1.empty() && v1.back()==0) v1.pop_back();
        while(!v2.empty() && v2.back()==0) v2.pop_back();
        if(v1 > v2) return 1;
        else if(v1 == v2) return 0;
        else return -1;
    }
};
