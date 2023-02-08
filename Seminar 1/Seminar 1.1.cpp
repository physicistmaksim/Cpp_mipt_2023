#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if (a==0 or b==0){
        cout << "Error" << endl;
    } else {
        if (a > b) {
        int r = a%b;
        if (r == 0){
            cout << b << endl;
        } else {
            int q = b;
            int pre_r = 0;
            do {
                pre_r = r;
                r = q%r;
            } while(r != 0);
            cout << pre_r << endl;   
        }
        } else {
            int r = b%a;
            if (r == 0){
                cout << a << endl;
            } else {
                int q = a;
                int pre_r = 0;
                do {
                    pre_r = r;
                    r = q%r;
                } while(r != 0);
                cout << pre_r << endl;   
            }
        }
    }
    return 0;
}