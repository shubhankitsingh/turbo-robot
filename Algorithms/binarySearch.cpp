#include<iostream>
using namespace std;

//Function to perform binary search
int binarySearch(int arr[],int n,int target){
    int left=0,right=n-1;

    while(left<=right){
        //Calculate mid point to avoid overflow
        int mid=left+(right-left)/2;
        //Check if target is at mid
        if(arr[mid]==target)
            return mid;
        //If target is greater, ignore left half
        if(arr[mid]<target)
            left=mid+1;
        //If target is smaller, ignore right half
        else
            right=mid-1;
    }
    //Return -1 if target is not found
    return -1;
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target; cin>>target;
    int result=binarySearch(arr,n,target);

    // Output result
    if(result!=-1)
        cout<<"Element is present at index "<<result<<endl;
    else
        cout<<"Element is not present in array"<<endl;
    return 0;
}
