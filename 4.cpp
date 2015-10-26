class Solution {
public: 
	int findMedian(vector<int> &num, int length){
		if (length == 1)
		{
			return num[0];
		}
		if(length%2 == 0)
		{
			return (num[length/2 - 1]+num[length/2])/2;
		}
		else
		{
			return num[(length-1)/2];
		}
	}

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 == 0)
        {
        	return findMedian(nums2, n2);
        }
        else if (n2 == 0)
        {
        	return findMedian(nums1, n1);
        }
        else if (n1 == 1 & n2 == 1)
        {
        	return (n1+n2)/2;
        }
        else
        {
        	if(nums1[0] <= nums2[0])
        	{
        		nums1.erase(nums1.begin());
        	}
        	else
        	{
        		nums2.erase(nums2.begin());
        	}
        	if (nums1[nums1.length()-1] < nums2[nums2.length()-1])
    		{
    			nums2.pop_back();
    		}
    		else
    		{
    			nums1.pop_back();
    		}
    		return findMedianSortedArrays(nums1, nums2);
        }
};
