#include<iostream>
#include<cstring>
using namespace std;

int Next[100];

void PrintNext(int next[],int len){
    for(int i=0;i<len;i++){
        cout<<next[i]<<" ";
    }
    cout<<endl;
}

void getNext(char *t){
    int j=0,k=-1;
    int m = strlen(t);
    Next[0]=-1;
    while(j<m-1){
        if(k==-1||t[j]==t[k]){
            j++;
            k++;
            Next[j]=k;
        }else{
            k = Next[k];
        }
    }
    PrintNext(Next,m);
}

int KMP(char *s,char*p){
    int i=0,j=0;
    int n=strlen(s);
    int m=strlen(p);
    while(i<n&&j<m){
        if(j==-1 || s[i]==p[j]){
            i++;
            j++;
        }else{
            j = Next[j];
        }
    }
    if(j>=m)return i-m;
    else return -1;
}

int KMPfromX(char *s,char *p,int X){
    int i=X,j=0;
    int n=strlen(s);
    int m=strlen(p);
    while(i<n&&j<m){
        if(j==-1 || s[i]==p[j]){
            i++;
            j++;
        }else{
            j = Next[j];
        }
    }
    if(j>=m)return i-m;
    else return -1;
}

int main(){
    
    char s[20]="ABABABABABC";
    char p[5]="ABA";
    int X = KMP(s,p);
    cout<<X<<endl;
    if(X==-1){
        cout<<0<<endl;
        return 0;
    }
    int cnt=0;
    while(X!=-1){
        cnt++;
        X++;
        X = KMPfromX(s,p,X);
    }
    cout<<cnt<<endl;
    
    return 0;
}