#include <stdio.h>

int main() {
    long long V, N;
    scanf("%lld%lld", &V, &N);

    for(int i=10; i<100; i+=10)
        printf("%lld%c", (N*V*i % 100 ? N*V*i/100 + 1 : N*V*i/100),
                         (i == 90 ? '\n' : ' '));

    return 0;
}