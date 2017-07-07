class Solution {
public:
    string numberToWords(int num) {
        // 注意到每三个数位为一节，分别模拟即可
        static char *c1[] = {
            "Zero", "One", "Two", "Three", "Four", "Five", "Six",
            "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
            "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
            "Eighteen", "Nineteen", "Twenty"
        };
        static char *c2[] = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety"
        };
        static int  mod[] = {1000000000, 1000000, 1000, 1};
        static char *c3[] = {" Billion", " Million", " Thousand", ""};
        string str;
        for(int i = 0; i < 4; ++i) {
            int n = num / mod[i];
            num -= n * mod[i];
            if(n == 0) continue;
            string tmp;
            int b = n / 100;
            n %= 100;
            if(b != 0) tmp += c1[b] + string(" Hundred");
            if(n == 0){}
            else if(n <= 20) {
                if(tmp.length() != 0) tmp += " ";
                tmp += c1[n];
            }
            else {
                if(tmp.length() != 0) tmp += " ";
                tmp += c2[n/10];
                if(n%10 != 0)
                    tmp += string(" ") + c1[n%10];
            }
            if(str.length() != 0)
                str += " ";
            str += tmp;
            str += c3[i];
        }
        if(str.length() == 0) str = c1[0];
        return str;
    }
};
