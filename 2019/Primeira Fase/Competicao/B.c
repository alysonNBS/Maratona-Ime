#include <stdio.h>

int main() {
    int N, carlos;
    char ans = 'S';
    scanf("%d%d", &N, &carlos);

    int v;
    while(--N) {
        scanf("%d", &v);

        if(v > carlos)
            ans = 'N';
    }

    printf("%c\n", ans);

    return 0;
}