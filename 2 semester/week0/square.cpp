#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    float d = b*b - 4*a*c;
    if (d < 0) {
        cout << "Нет решений" << endl;
    } else {
        if (d == 0){
            float x = (-b)/(2*a);
            cout << "x = " << x << endl;
        } else {
            float x_1 = ((-b) + sqrt(d))/(2*a);
            float x_2 = ((-b) - sqrt(d))/(2*a);
            cout << "x_1 = " << x_1 << endl;
            cout << "x_2 = " << x_2 << endl;
        }
    }
    return 0;
}