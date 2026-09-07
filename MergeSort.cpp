#include <iostream>

using namespace std;

void Merge(int arr[],int start,int mid,int end){
  int n1 = mid - start+1;
  int n2 = end - mid;
  int L[n1],R[n2];

  for(int i = 0;i<n1;i++){
    L[i]=arr[start+i];
  }

  for(int i =0;i<n2;i++){
    R[i]=arr[mid+1+i];
  }

  int i=0,j=0,k=start;
  while(i<n1&&j<n2){
    if(L[i]<=R[j]){
        arr[k]=L[i];
        i++;
        k++;
    }else{
        arr[k]=R[j];
        j++;
        k++;
    }
  }

  while(i<n1){
       arr[k]=L[i];
       i++;
       k++;
  }

  while(j<n2){
      arr[k]=R[j];
      j++;
      k++;
  }


}




void MergeSort(int arr[],int start,int end){
   if(start<end){
    int mid = (start+end)/2;
    MergeSort(arr,start,mid);
    MergeSort(arr,mid+1,end);
    Merge(arr,start,mid,end);
   }
}



int main (){

   int arr[]={5,3,-7,12,9,-4,13};
   int n = sizeof(arr)/sizeof(arr[0]);
   MergeSort(arr,0,n-1);
   cout<<"After sort: "<<endl;
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;



    return 0;
}
