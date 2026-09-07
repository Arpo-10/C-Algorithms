#include<iostream>

using namespace std;

int parent[100];
int ranking[100];


void makeset(int x){
   for(int i =1;i<x;i++){
    parent[i]=i;
   }

}

int findset(int x){
  if(parent[x]==x){
    return x;
  }else{
    int rep_x = findset(parent[x]);
    return rep_x;
  }
}

void Union(int x,int y){
   int rep_x= findset(x);
   int rep_y= findset(y);

   if(rep_x==rep_y){
    return;
   }

   if(rep_x!=rep_y){
    parent[rep_x]=rep_y;
   }
}


int main(){

    //DSU... Disjoint set Union
    int n;
    cin>>n;
    makeset(n);
    Union(2,1);
    Union(2,3);
    Union(3,4);

    int x = findset(3);
    int y = findset(2);
    cout<<x<<endl;
    cout<<y<<endl;


   return 0;
}
