class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l=0,r=A.size()-1,mid;
        while (l!=r){
            mid=(l+r)>>1;
            if (A[mid]>A[mid+1])r=mid;
            else l=mid+1;
        }
        return l;
    }
};