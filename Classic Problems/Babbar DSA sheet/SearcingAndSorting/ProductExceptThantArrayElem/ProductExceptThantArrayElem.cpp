// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        long long prod = 1, sprod = 1; 
        vector <long long int> res(n, 1);
        int zero = 0;
        for(int i = 0; i < n; i++){
            prod *= nums[i];
            if(nums[i] == 0){
            zero++;
            }
            else{
                sprod *= nums[i];
            }
        }   
        for(int i = 0; i < n; i++){ 
            if(zero != 1){ // if no of zeros is greater than one the prod is always zero
            if(nums[i] !=0)
            res[i] = (prod/nums[i]);
            else
            res[i] = 0;
            }
            if(zero == 1){  // if zero count is 1 then if element is 0 then product is rest else 0
                if(nums[i] == 0)
                res[i] = sprod;
                else
                res[i] = 0;
            }
        }
        return res;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends