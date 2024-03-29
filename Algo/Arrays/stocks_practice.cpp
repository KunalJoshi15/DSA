
//  This is simply an O(n) solution here we will be finding the local maxima and the minima and according to it we can compute the profit that we are getting.
if (n == 1)
        return;
 
    // Traverse through given price array
    int i = 0;
    while (i < n - 1) {
 
        // Find Local Minima
        // Note that the limit is (n-2) as we are
        // comparing present element to the next element
        while ((i < n - 1) && (price[i + 1] <= price[i]))
            i++;
 
        // If we reached the end, break
        // as no further solution possible
        if (i == n - 1)
            break;
 
        // Store the index of minima
        int buy = i++;
 
        // Find Local Maxima
        // Note that the limit is (n-1) as we are
        // comparing to previous element
        while ((i < n) && (price[i] >= price[i - 1]))
            i++;
 
        // Store the index of maxima
        int sell = i - 1;
 
        cout << "Buy on day: " << buy
             << "\t Sell on day: " << sell << endl;
    }