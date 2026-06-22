class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int hash[26] = {0};
        for (int i = 0; i < text.length(); i++) {
            hash[text[i] - 'a'] += 1;
        }

        int arr[5] = {hash[0], hash[1], hash[11] / 2, hash[14] / 2, hash[13]};
        int min = arr[0];
        for (int i = 1; i < 5; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }
};