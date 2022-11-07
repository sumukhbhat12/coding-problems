 vector<int> increasing(n,1), decreasing(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] && increasing[i] < increasing[j] + 1){
                increasing[i] = increasing[j] + 1;
            }
            if(arr[n-1-i] > arr[n-1-j] && decreasing[n-1-i] < decreasing[n-1-j] + 1){
                decreasing[n-1-i] = decreasing[n-1-j] + 1;
            }
        }
    }
    
    int maxi = -1;
    for(int i=0;i<n;i++){
        int temp = increasing[i] + decreasing[i] - 1;
        maxi = max(maxi,temp);
    }
    
    return maxi;
