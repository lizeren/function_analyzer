#include <iostream>
using namespace std;

int add(int a, int b) {
    int c = a;
    int d = b;
    float e = 0;
    return c + d;
}

void printHello() {
    cout << "Hello, world!" << endl;
}

int main() {
    int result = add(3, 4);
    printHello();
    cout << "Result of add: " << result << endl;
    return 0;
}
