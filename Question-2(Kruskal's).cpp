#include<iostream>

using namespace std;

int parent[1000];

struct Edge1{
  int u,v,w;
};

Edge1 Edges[] = {{0,1,7},{0,2,9},{0,5,14},{1,2,10},{1,3,15},{2,3,11},{2,5,2},{
3,4,6},{4,5,9}};

int m = 9;


void makeset(int n){
  for(int i =0;i<n;i++){
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

void unionn(int x,int y){
  int rep_x = findset(x);
  int rep_y = findset(y);

  if(rep_x!=rep_y){
    parent[rep_x]=rep_y;
  }
}


void EdgingSort(int m){
   //Selection Sort
   for(int i=0;i<m-1;i++){
    int small = i;
    for(int j = i+1; j<m;j++){
        if(Edges[j].w<Edges[small].w){
            small = j;
            swap(Edges[i],Edges[small]);
        }
    }
   }
}

void Kruskal(){
   int n;
   cin>>n;
   makeset(n);
   EdgingSort(m);
   int totalweightcost = 0;
   int totaltaken = 0;
   for(int i=0;i<m&&totaltaken<n-1;i++){
    int u = Edges[i].u;
    int v = Edges[i].v;
    if(findset(u)!=findset(v)){
        unionn(u,v);
        totalweightcost+=Edges[i].w;
        totaltaken+=1;
        cout<<u<<" -> "<<v<<" "<<Edges[i].w<<"\n";
    }

   }
   cout<<"Total Weight Cost: "<<totalweightcost<<"\n";
   cout<<"Total taken: "<<totaltaken<<"\n";

}



int main(){

    Kruskal();


   return 0;
}
