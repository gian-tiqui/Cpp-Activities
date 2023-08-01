#include <iostream>

using std::cout;

// Without passing args as reference, it will only modify the copy of n within the scope but the value will not change
void change_n(int *n) {
    int **nn = &n;

    cout << **nn << '\n';

    **nn = 100;
}

int main() {
    int n = 10;

    cout << n << '\n';

    change_n(&n);

    cout << n << '\n';

    return 0;
}