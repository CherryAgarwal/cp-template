//Rotated sorted array 
//ques find the index of the guven target 
//Approach 1 xor operator

while (lo < hi) {
        int mid = (lo + hi) / 2;
        if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
            lo = mid + 1;
        else
            hi = mid;
    }
        return lo == hi && nums[lo] == target ? lo : -1;

//Approach 2 

while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        int rot=lo;
        lo=0;hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
return -1;

//Approach 3

int search(vector<int>& n, int t) {
        int low=0;
        int high= n.size()-1;
        int mid;
        while(high>=low);
        {
            mid=low+(high-low)/2;
            if(n[mid]==t) return mid;
            if(n[low]<=n[mid]){
                //left half is sorted
                if(t>=n[low] and t<=n[mid]){
                    //target lies in left half
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                //right half is sorted
                if(t<=n[high] and t>=n[mid]){
                    //target in right half
                    low=mid+1;                    
                }
                else{
                    high=mid-1;
                }               
            }   
        }
        return  -1;
  }

//to find the smallest element
int findMin(int arr[], int low, int high)
{
    while(low < high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid] == arr[high])
            high--;
        else if(arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }
    return arr[high];
}
