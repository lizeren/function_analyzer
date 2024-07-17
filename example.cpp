#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
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
