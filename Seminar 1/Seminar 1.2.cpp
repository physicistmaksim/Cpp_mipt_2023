#include <iostream>
using namespace std;

int main(){
    int a;
    int flag = 1;
    cin >> a;
    int i = 2;
    while (flag != 0 and i < (a/2 + 1)){
        flag = a%i;
        i++;
    }
    if (flag == 0){
        cout << "Не простое число" << endl;
    } else {
        cout << "Простое число" << endl;
    }
    return 0;
}
