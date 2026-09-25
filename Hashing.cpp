#include<iostream>

using namespace std;

void insertion(int key,int arr[])
{
    int a = (key+7)%6;
    arr[a] = key;
    return ;
}

int searching(int key,int arr[])
{
    int i = (key+7)%6;

    if(arr[i]==key)
    {
        return i;
    }
    return -1;

}

int deleting(int key,int arr[])
{
    int i =(key+7)%6;
    if(arr[i]==key)
    {
        arr[i] = 999999;
        return i;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i]= 9999999;
    }
    int key1,key2;
    cin>>key1;
    cin>>key2;
    insertion(key1,arr);
    int c1 = searching(key1,arr);
    insertion(key2,arr);
    int c2 = deleting(key2,arr);
    cout<<" "<<key1<<" Found! "<<c1<<endl;
    cout<<" "<<key2<<" Deleted! "<<c2<<endl;
    return 0;
}
