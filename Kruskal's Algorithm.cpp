#include<iostream>

using namespace std;

int parent[100];

struct edging{
  int u;
  int v;
  int w;

};

edging edges[] = {{0,1,4},{0,2,3},{1,2,1},{1,3,2},{2,3,4},{2,4,5},{3,4,2},{3,5,7},{4,5,6}};
int m = 9;

void makeset(int x){
   for(int i=1;i<x;i++){
    parent[i]=i;
   }
}

int findset(int x){
  if(parent[x]==x){
    return x;
  }else{
    int rep_x= findset(parent[x]);
    return rep_x;
  }
}

void unionset(int x,int y){
   int rep_x = findset(x);
   int rep_y = findset(y);

   if(rep_x!=rep_y){
    parent[rep_x]= rep_y;
   }

}



void sortEdges(int m){
   for(int i=0;i<m-1;i++){
    int small = i;
    for(int j=i+1;j<m;j++){
        if(edges[j].w<edges[small].w){
            small = j;
            edging t = edges[small];
            edges[i] = t;
        }
    }
   }
}

void kruskal(){
    int n;
    cin>>n;
   makeset(n);
   sortEdges(m);
   int total = 0;
   int taken = 0;
   for(int i =0;i<m&&taken<n-1;i++){
    int u = edges[i].u;
    int v = edges[i].v;
    if(findset(u)!=findset(v)){
        unionset(u,v);
        total = total + edges[i].w;
        taken = taken+1;
        cout<<u<<" -> "<<v<<" "<<edges[i].w<<"\n";
    }
   }

 cout<<"Total Cost: "<<total<<"\n";


}





int main(){

    //Kruskal's Algorithm...
     kruskal();



   return 0;
}
