class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        int i = 0;

        while (i < n) {
            int j = i;

            // Find a group where consecutive values differ <= limit
            while (j + 1 < n &&
                   arr[j + 1].first - arr[j].first <= limit) {
                j++;
            }

            // Collect indices of this group
            vector<int> indices;

            for (int k = i; k <= j; k++) {
                indices.push_back(arr[k].second);
            }

            // Sort indices so smallest values go to smallest indices
            sort(indices.begin(), indices.end());

            // Assign values in sorted order
            for (int k = i; k <= j; k++) {
                nums[indices[k - i]] = arr[k].first;
            }

            i = j + 1;
        }

        return nums;
    }
};