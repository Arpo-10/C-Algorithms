#include<iostream>

using namespace std;

int parent[1000];

struct Edge{
 int u,v,w;
};

Edge edges[] = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4},{2,4,8},{3,4,12}};
int m = 7;

void makeset(int x){
  for(int i=0;i<x;i++){
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

void unionset(int x,int y){
   int rep_x = findset(x);
   int rep_y = findset(y);

   if(rep_x != rep_y){
    parent[rep_x]=rep_y;
   }
}

void EdgeSort(int m){
  for(int i=0;i<m-1;i++){
    int small = i;
    for(int j=i+1;j<m;j++){
        if(edges[j].w<edges[small].w){
            small = j;
            swap(edges[i],edges[small]);
        }
    }
  }

}


void Kruskal(){
   int n;
   cin>>n;
   makeset(n);
   EdgeSort(m);
   int totalcost = 0;
   int totaltaken = 0;

   for(int i=0;i<m&&totaltaken<n-1;i++){
    int u = edges[i].u;
    int v = edges[i].v;

    if(findset(u)!=findset(v)){
        unionset(u,v);
        totalcost = totalcost+edges[i].w;
        totaltaken+=1;
        cout<<u<<" -> "<<v<<" "<<edges[i].w<<"\n";
    }
   }
   cout<<"Total cost: "<<totalcost<<"\n";
   cout<<"Total Taken: "<<totaltaken<<"\n";
}



int main(){

   Kruskal();


   return 0;
}
