class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size(), s;
        /*
            ����nums����������nums[i]ʱ�������nums[0...i-1]�а�������(target - nums[i]),
            ����������
        */
        unordered_set<int> se; // ʹ��hash���ж�ĳ�������Ƿ���ֹ�
        se.insert(nums[0]); // ��Ŀ��֤����ֻ��һ���⣬���Դ˴�����Խ��
        vector<int>::iterator it;
        for(s = 1; s < len; ++s)
        {
            if(se.find(target - nums[s]) != se.end())
            {
                // ʹ��unordered_map��˴�����Ҫ�������Բ���
                it = find(nums.begin(), nums.begin() + s, target - nums[s]);
                break;
            }
            se.insert(nums[s]);
        }
        return vector<int>{it - nums.begin(), s};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size(), s;
        /*
            ��ʹ�ö���洢�ռ䣬�����Ӷ�ΪO(n^2)�ķ�����
        */
        vector<int>::iterator it;
        for(s = 0; s < len - 1; ++s)
        {
            it = find(nums.begin() + s + 1, nums.end(), target - nums[s]);
            if(it != nums.end()) break;
        }
        return vector<int>{s, it - nums.begin()};
    }
};
