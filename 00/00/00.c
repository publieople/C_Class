#include <stdio.h>

int main() {
    double sum = 0.0;
    int n;

    for (n = 1; n <= 100; n++) {
        if (n % 2 == 1) {
            sum += 1.0 / n;  // 奇数项，加
        }
        else {
            sum -= 1.0 / n;  // 偶数项，减
        }
		printf("After %3d terms, partial sum = %.15f\n", n, sum);
    }

    printf("The sum is: %.15f\n", sum);
    return 0;
}