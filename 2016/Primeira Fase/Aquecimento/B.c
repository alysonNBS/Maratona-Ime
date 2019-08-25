#include <stdio.h>
#include <string.h>

#define MAXC 100

int main() {
    int N, L, C;
    int lines = 1;
    char work[MAXC];
    int characters = 0, len_work;

    scanf("%d%*c%d%*c%d%*c", &N, &L, &C);


    scanf("%s", work);
    N--;

    while(N) {
        characters = len_work = strlen(work);

        while(N) {
            scanf("%s", work);
            N--;

            len_work = strlen(work);
            characters += len_work + 1;

            if(characters > C) {
                lines++;
                break;
            }
        }
    }

    printf("%d\n", ( lines % L ? lines/L + 1 : lines/L ));

    return 0;
}