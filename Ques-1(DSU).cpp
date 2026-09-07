#include<iostream>

using namespace std;

int parent[1000];
int rankings[1000];


void makeset(int n){
  for(int i = 1;i<n;i++){
    parent[i]=i;
  }
}

int findset(int x){
   if(parent[x]==x){
    return x;
   }else{
    int rep_X = findset(parent[x]);
    return rep_X;
   }
}

void UNION(int x,int y){
   int rep_x = findset(x);
   int rep_y = findset(y);

   if(rep_x!=rep_y){
    parent[rep_x]=rep_y;

   }
}


int main(){

   int n;
   cin>>n;
   makeset(n);
   UNION(1,2);
   UNION(2,3);
   int x= findset(1);
   UNION(4,5);
   int y= findset(5);
   cout<<x<<endl;
   cout<<y<<endl;

   return 0;
}
