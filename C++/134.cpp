class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();
        if(sz == 0) return -1;
        vector<int> v(sz);
        int res = 0;
        for(int i = 0; i < sz; ++i)
        {
            v[i] = res;
            res += gas[i] - cost[i];
        }
        if(res < 0) return -1;
        
        res = 0;
        int pos = 0, mi = numeric_limits<int>::max();
        for(int i = 0; i < sz; ++i)
        {
            if(v[i] < mi)
                mi = v[i], pos = i;
        }
        if(pos == 0) return 0;
        
        res = 0;
        for(int i = 0; i < sz; ++i)
        {
            int p = (i+pos)%sz;
            res += gas[p] - cost[p];
            if(res < 0) return -1;
        }
        return pos;
    }
};
