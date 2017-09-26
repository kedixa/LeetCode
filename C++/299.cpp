class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.length();
        int A = 0, B = 0;
        int a[10] = {0};
        for(int i = 0; i < len; ++i) {
            if(secret[i] == guess[i])
                guess[i] = '-', ++A;
            else a[secret[i] - '0']++;
        }
        for(int i = 0; i < len; ++i) {
            if(guess[i] != '-' && a[guess[i] - '0'])
                ++B, --a[guess[i] - '0'];
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
