#include <iostream>
using namespace std;

int const N0 = 61;

unsigned long long steps_number(int coord, unsigned long long (&mem)[N0]){
    if(coord == 0){
        return 0;
    }
    if(mem[coord] != 0){
        return mem[coord];
    }
    else{
        unsigned long long k = steps_number(coord - 1, mem) + steps_number(coord - 2, mem) + steps_number(coord - 3, mem);
        mem[coord] = k;
        return k;
    }
}

int main(){
    int X1;
    cin >> X1;
    unsigned long long mem[N0] = {0};
    mem[0] = 0;
    mem[1] = 1;
    mem[2] = 2;
    mem[3] = 4;
    cout << steps_number(X1, mem);
}