class NumArray {
private:
    vector<int> tree;
    int n;
    void buildTree(const vector<int>& nums, int treeIndex, int start, int end) {
        if (start == end) {
            tree[treeIndex] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(nums, 2 * treeIndex + 1, start, mid);
        buildTree(nums, 2 * treeIndex + 2, mid + 1, end);
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }
    void updateTree(int treeIndex, int start, int end, int arrIndex, int val) {
        if (start == end) {
            tree[treeIndex] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (arrIndex <= mid) {
            updateTree(2 * treeIndex + 1, start, mid, arrIndex, val);
        } else {
            updateTree(2 * treeIndex + 2, mid + 1, end, arrIndex, val);
        }
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }

    int queryTree(int treeIndex, int start, int end, int queryLeft, int queryRight) {
        if (end < queryLeft || start > queryRight) return 0;
        if (queryLeft <= start && end <= queryRight) return tree[treeIndex];
        int mid = start + (end - start) / 2;
        int leftSum = queryTree(2 * treeIndex + 1, start, mid, queryLeft, queryRight);
        int rightSum = queryTree(2 * treeIndex + 2, mid + 1, end, queryLeft, queryRight);
        return leftSum + rightSum;
    }

public:
    NumArray(vector<int>& nums) {
        if (!nums.empty()) {
            n = nums.size();
            tree.resize(4 * n);
            buildTree(nums, 0, 0, n - 1);
        }
    }

    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return queryTree(0, 0, n - 1, left, right);
    }
};