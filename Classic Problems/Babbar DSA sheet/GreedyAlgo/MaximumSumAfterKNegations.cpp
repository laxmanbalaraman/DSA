static bool compare(int a, int b){
        return abs(a) > abs(b);
    }
    
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a, a + n, compare);
        int end = k;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(a[i] < 0 and k > 0){
                a[i] *= -1;
                k--;
            }
            sum += a[i];
        }
        if(!k) return sum;
        else{
            if(k % 2 == 0) return sum;
            else return sum - 2 * a[n-1];
        }
    }