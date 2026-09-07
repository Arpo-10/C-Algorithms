#include<iostream>

using namespace std;

int parent[1000];
int r[1000];



void makeset(int x){
  for(int i = 1; i<= x;i++){
    parent[i]=i;
  }
}



int f(int x){
  if(parent[x]==x){
    return x;
  }else{
    int rep_x = f(parent[x]);
    return rep_x;
  }
}

void UNION(int x, int y){
  int rep_x = f(x);
  int rep_y = f(y);

  if(rep_x!=rep_y){
    parent[rep_x]=rep_y;
    return;
  }
}


int main(){

    int n,m;
    cin>>n>>m;
    makeset(n);

    for(int i = 0;i<m;i++){
        char type;
        cin>>type;
        if(type=='U'||type=='u'){
            int x,y;
            cin>>x>>y;
            UNION(x,y);
        }

        if(type=='F'||type=='f'){
            int x;
            cin>>x;
            cout<<f(x)<<endl;
        }
    }






   return 0;
}
