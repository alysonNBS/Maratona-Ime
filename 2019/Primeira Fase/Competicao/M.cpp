#include <iostream>
#include <cmath>
#define MAXN 100100

using namespace std;

int N, C, T;
int P[MAXN];
double times[MAXN];

bool possible(int max_time) {
    int min_comp = 1;
    double time = 0.0;

    for(int i=0; i<N; i++) {
        if( times[i] > (double) max_time )
            return false;
        time += times[i];

        if( time >= (double) max_time ) {
            min_comp++;

            if( time == (double) max_time ) {
                time = 0.0;

                if(i == N-1)
                    min_comp--;
            }
            else
                time = 0.0, i--;
        }
    }

    return min_comp <= C;
}

int bb(int a, int b) {
    int mid = (a+b)/2;

    if(possible(mid))
        b = mid;
    else
        a = mid + 1;
    
    if(a == b)
        return a;
    return bb(a, b);
}

int main() {
    int max_time = 0;
    
    cin >> N >> C >> T;

    for(int i=0; i<N; i++) {
        cin >> P[i];
        times[i] = (double) P[i]/T;
        max_time += P[i];
    }
    max_time = (max_time % T ? max_time/T + 1 : max_time/T);

    cout << bb(1, max_time) << endl;

    return 0;
}