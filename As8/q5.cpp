// Q5 


#include <iostream>
using namespace std;
    void heapify(int arr[],int index,int n){
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;
        
        if(left<n && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<n && arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=index){
            swap(arr[index],arr[largest]);
            heapify(arr,largest,n);
        }
    }
    void buildMaxHeap(int arr[],int n){
        for(int i=(n-1)/2;i>=0;i--){
            heapify(arr,i,n);
        }
    }
    void heapsort(int arr[],int n){
        for(int i=n-1;i>=0;i--){
            swap(arr[i],arr[0]);
            heapify(arr,0,i);
        }
    }
    void print(int arr[],int size){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

int main() {
    int arr[]={4,2,6,4,1,8,9,34,65,11,2};
    buildMaxHeap(arr,11);
    heapsort(arr,11);
    print(arr,11);
    return 0;
}