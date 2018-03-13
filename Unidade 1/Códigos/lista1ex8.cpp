#include<iostream>

using namespace std;

unsigned int INVERTE (unsigned int num){

    int div = 10;
    int res = 1;
    unsigned int inv = 0;
    for( ; res > 0; div*=10){
        
        res = num/div;
        inv += num - res*div - inv;
        inv*=div;

    }

}


int main(){



}