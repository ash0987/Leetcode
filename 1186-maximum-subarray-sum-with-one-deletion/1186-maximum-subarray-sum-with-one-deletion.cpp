class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        int best1=arr[0];
        if(n==1) return best1;
        vector<int> prefixSum(n,0);
        prefixSum[0]=best1;
        for(int i=1;i<n;i++)
        {
            prefixSum[i]=max(arr[i],arr[i]+prefixSum[i-1]);
        }
        int res=best1;
        int suffPrev= arr[n-1];
        vector<int> suffixSum(n,0);
        suffixSum[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffixSum[i]=max(arr[i],arr[i]+suffixSum[i+1]);
        }

        for(int i=0;i<n;i++)
        {
            int temp=0;
            if(i!=0)
            {
                temp+=prefixSum[i-1];
            }
            if(i!=n-1)
            {
                temp+=suffixSum[i+1];

            }
            res=max(res,temp);
            res=max(res,prefixSum[i]);
        }
        return res;
    }
};