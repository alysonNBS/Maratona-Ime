#include <iostream>
#include <algorithm>

#define isVowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')

using namespace std;

bool is_palindrome(char *string, int len) {
    int begin=0, end=len-1;

    while(begin < end)
        if(string[begin++] != string[end--])
            return false;
    return true;
}

int main() {
    char laugh[51], laugh_no_consonant[51], len_laugh_no_con=0;
    
    // reading input
    cin >> laugh;
    for(int i=0; laugh[i]; i++)
        if(isVowel(laugh[i]))
            laugh_no_consonant[len_laugh_no_con++] = laugh[i];
    laugh[len_laugh_no_con] = 0;
    
    cout << (is_palindrome(laugh_no_consonant, (int) len_laugh_no_con) ? 'S' : 'N') << endl;

    return 0;
}