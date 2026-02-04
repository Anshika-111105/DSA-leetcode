class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count=0,sum=0;
        for (int right = 0, left = 0; right < arr.size(); right++) {
		    sum += arr[right];
		    if (right >= k - 1) {
			    if (sum / k >= threshold)
				    count++;
			    sum -= arr[left++];
		    }
	    }
        return count;
    }
};