class Solution {
public:
    void conquer(vector<int>& arr, int start, int mid, int end) {
        vector<int> mergeArray(end - start + 1);

        int idx1 = start;
        int idx2 = mid + 1;
        int x = 0;

        while (idx1 <= mid && idx2 <= end) {
            if (arr[idx1] <= arr[idx2]) {
                mergeArray[x++] = arr[idx1++];
            } else {
                mergeArray[x++] = arr[idx2++];
            }
        }

        while (idx1 <= mid) {
            mergeArray[x++] = arr[idx1++];
        }

        while (idx2 <= end) {
            mergeArray[x++] = arr[idx2++];
        }

        for (int i = 0; i < mergeArray.size(); i++) {
            arr[start + i] = mergeArray[i];
        }
    }

    void divide(vector<int>& arr, int start, int end) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;

        divide(arr, start, mid);
        divide(arr, mid + 1, end);

        conquer(arr, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        divide(nums, 0, nums.size() - 1);
        return nums;
    }
};