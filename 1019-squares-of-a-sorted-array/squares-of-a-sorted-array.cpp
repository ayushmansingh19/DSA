
class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int n = a.size();

        vector<int> neg;
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                neg.push_back(a[i]);
            }
            else {
                pos.push_back(a[i]);
            }
        }

        // WRONG: You returned inside the for loop.
        // This would process only the first element.
        // Also, you don't need separate return cases.

        int i = 0, j = 0;
        int id = 0;

        int n1 = neg.size();
        int p = pos.size();

        // WRONG: You wrote vector<int>(n+p);
        // This creates a temporary vector and doesn't store it.
        // Correct: Declare a named result vector.
        vector<int> res(n1 + p);

        // Square negative numbers
        for (int i = 0; i < n1; i++) {
            neg[i] = neg[i] * neg[i];
        }

        // WRONG: You forgot that negative numbers
        // must be reversed AFTER squaring.
        reverse(neg.begin(), neg.end());

        // Square positive numbers
        for (int i = 0; i < p; i++) {
            pos[i] = pos[i] * pos[i];
        }

        // Merge both sorted arrays
        while (i < n1 && j < p) {

            if (neg[i] <= pos[j]) {
                res[id] = neg[i];
                id++;
                i++;
            }
            else {
                // WRONG: You wrote neg[i] here.
                // You should insert pos[j].
                res[id] = pos[j];
                id++;
                j++;
            }
        }

        // Add remaining elements from neg
        while (i < n1) {
            res[id] = neg[i];
            id++;
            i++;
        }

        // WRONG: You wrote while(i < m).
        // You should check j < p.
        // You also used neg[p] instead of pos[j].
        while (j < p) {
            res[id] = pos[j];
            id++;
            j++;
        }

        return res;
    }
};
