#include<iostream>
#include<vector>
using namespace std;

// Function to build the segment tree
void buildTree(vector<int>&arr,vector<int>&segTree,int start,int end,int node){
    if(start==end){
        segTree[node]=arr[start]; // Leaf node
    }
    else{
        int mid=(start+end)/2;
        buildTree(arr,segTree,start,mid,2*node+1); // Build left child
        buildTree(arr,segTree,mid+1,end,2*node+2); // Build right child
        segTree[node]=segTree[2*node+1]+segTree[2*node+2]; // Internal node
    }
}

// Function to perform range sum query
int rangeQuery(vector<int>&segTree,int start,int end,int l,int r,int node){
    if(r<start||l>end) // No overlap
        return 0;
    if(l<=start&&r>=end) // Complete overlap
        return segTree[node];
    // Partial overlap
    int mid=(start+end)/2;
    int leftSum=rangeQuery(segTree,start,mid,l,r,2*node+1);
    int rightSum=rangeQuery(segTree,mid+1,end,l,r,2*node+2);
    return leftSum+rightSum;
}

// Function to update a value in the array and segment tree
void updateTree(vector<int>&arr,vector<int>&segTree,int start,int end,int index,int value,int node){
    if(start==end){
        arr[index]=value; // Update array
        segTree[node]=value; // Update segment tree
    }
    else{
        int mid=(start+end)/2;
        if(index<=mid)
            updateTree(arr,segTree,start,mid,index,value,2*node+1); // Update left child
        else
            updateTree(arr,segTree,mid+1,end,index,value,2*node+2); // Update right child
        segTree[node]=segTree[2*node+1]+segTree[2*node+2]; // Update internal node
    }
}
int main(){
    vector<int>arr={1,3,5,7,9,11};
    int n=arr.size();
    vector<int>segTree(4*n,0); // Segment tree

    // Build segment tree
    buildTree(arr,segTree,0,n-1,0);

    // Range sum query for the range [1,3]
    int sum=rangeQuery(segTree,0,n-1,1,3,0);
    cout<<"Sum in range [1,3]: "<<sum<<endl;

    // Update value at index 1 to 10
    updateTree(arr,segTree,0,n-1,1,10,0);

    // Query again after the update
    sum=rangeQuery(segTree,0,n-1,1,3,0);
    cout<<"Sum in range [1,3] after update: "<<sum<<endl;

    return 0;
}
