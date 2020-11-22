//Haris Nawrin
//CS 211 Homework 5
#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
    for(int j=0; j<c; j++)
        if(q[c]== q[j]|| (c-j)==abs(q[c]-q[j]))
            return false;
    
    return true;
};

void print (int q[]){
    static int numSolutions = 0;
    cout<< "Solution #"<< ++numSolutions<< ":";
    int j;
    for (j=0; j<8; j++)
        cout<< q[j]<< " ";
    //print the array
    cout<<"\n";
};

void backtrack(int& col) {
    col--; //go back to previous column
    if(col==-1){
        system ("PAUSE");
        exit(1);
    }
};

int main(){
    int q[8]; q[0]=0;
    int d=1;
    bool  now_backtrack= false;
    
    while(true){
        while (d<8){
            if (!now_backtrack)q[d]=-1;
            now_backtrack=true;
            
            while (q[d]<8){
                q[d]++;
                
                if (q[d]==8){
                    now_backtrack=true;
                    backtrack(d);
                    break;
                }
                if(ok(q, d)){
                    now_backtrack=false;
                    d++;
                    break;
                }
            }
        }
        print(q);
        now_backtrack=true;
        backtrack(d);
    }
}
