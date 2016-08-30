class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
            һ��ʱ�临�Ӷ�O(n^2)�ķ�����ö���Ӵ��Ŀ�ʼλ�ã������λ�����鿴���Ե������Զλ�ã�
            ����ö���Ӵ��Ľ���λ�ã������λ����ǰ�鿴���Ե������Զλ�á�
            ͨ��ά��һЩ��Ϣ�����Եõ�O(n)�Ľⷨ��
        */

        // last_appeare ����ά���ַ�s[i]��һ�γ��ֵ�λ�ã�������Ӵ���s[i]��β��
        // �������λ��Ӧ����last_appeare[s[i]]֮�󣨲�Ȼ������һ���ַ��ظ���
        vector<int> last_appeare(128, -1);

        /*
            min_bound ����֮ǰ����Ϣ��ά����s[i]��β���Ӵ��Ŀ�ʼλ�õ�һ���½�
            �ԡ�aab��Ϊ�����±��0��ʼ������ö�ٵ�s[1]ʱ��������ĸ��a����һ�γ��ֵ�λ����0��
            Ϊ�˲��ظ�������ĸ��a�������Ӵ����ٴ�λ��1��ʼ�����Ҵ˺�����еĿ�ʼλ�ö������ܸ��磻
            ��ö�ٵ�s[2]ʱ��last_appeare��ʾ��ĸ��b����û���ֹ�����min_bound��ʾ��
            ������Ӵ���λ��0��ʼ��������һ����ĸ�����ظ���������Ҫ��λ��1��ʼ��
        */
        int len = s.length(), max_length = 0, min_bound = -1;
        for(int i = 0; i < len; ++i)
        {
            min_bound = max(min_bound, last_appeare[s[i]]);
            max_length = max(max_length, i - min_bound);
            last_appeare[s[i]] = i;
        }
        return max_length;
    }
};
