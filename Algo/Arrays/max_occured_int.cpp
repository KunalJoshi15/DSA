// Initalising all element of array to 0.
    int arr[MAX];
    memset(arr, 0, sizeof arr);
 
    // Adding +1 at Li index and substracting 1
    // at Ri index.
    int maxi=-1;
    for (int i = 0; i < n; i++) {
        arr[L[i]] += 1;
        arr[R[i] + 1] -= 1;
        if(R[i]>maxi){
            maxi=R[i];
        }
    }
    // Firstly create a particular array of the maxx size and initialize it to all 0's.
    // Mark the position of the elements that occur in the L[i] and decrement from R[i+1]; 
 
    // Finding prefix sum and index having maximum
    // prefix sum.
    // Find the prefix sum of the entire array which is now obtained.
    int msum = arr[0],ind;
    for (int i = 1; i < maxi+1; i++) {
        arr[i] += arr[i - 1];
        if (msum < arr[i]) {
            msum = arr[i];
            ind = i;
        }
    }
 
    return ind;