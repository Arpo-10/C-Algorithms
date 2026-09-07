#include <iostream>

using namespace std;

struct Result{
  int left;
  int right;
  int sum;
};

Result FindCross(int arr[],int start,int mid,int end){
  Result ans;
  int sum = 0;
  int leftsum = arr[mid];
  int maxLeft = mid;
  for(int i = mid;i>=start;i--){
    sum = sum+arr[i];
    if(sum>leftsum){
        leftsum = sum;
        maxLeft = i;
    }
  }

  sum = 0;
  int rightsum = arr[mid+1];
  int maxright = mid+1;

  for(int j = mid+1;j<=end;j++){
    sum = sum+arr[j];
    if(rightsum<sum){
        rightsum = sum;
        maxright = j;
    }
  }

  ans.left = maxLeft;
  ans.right = maxright;
  ans.sum = leftsum+rightsum;
  return ans;

}





 Result MaxSubarraySum(int arr[],int start,int end){
     Result ans;
     if(start == end){
        ans.left = start;
        ans.right = start;
        ans.sum = arr[start];

        return ans;
     }

    int mid = (start+end)/2;
    Result left = MaxSubarraySum(arr,start,mid);
    Result right = MaxSubarraySum(arr,mid+1,end);
    Result cross = FindCross(arr,start,mid,end);

    if(left.sum>=right.sum&&left.sum>=cross.sum){
        return left;

    }else if(right.sum>=left.sum&&right.sum>=cross.sum){
       return right;
    }else{
       return cross;
    }

  }



int main (){

    int arr[]={8,3,2,1,4,5,7,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    Result ans = MaxSubarraySum(arr,0,n-1);

    cout<<"Max sum: "<<ans.sum<<endl;
    cout<<"Start index: "<<ans.left<<endl;
    cout<<"End Index: "<<ans.right<<endl;

    cout<<"Subarray: ";
    for(int i=ans.left;i<=ans.right;i++){
        cout<<arr[i]<<" ";
    }




    return 0;
}
