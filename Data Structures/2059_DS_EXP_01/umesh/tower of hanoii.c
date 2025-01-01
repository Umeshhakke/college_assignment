//Program of Tower of Hanoii
//Name:Umesh Pandit Hakke 
//Roll no:- 2059
#include <stdio.h>
void towerOfHanoi(int n, char from, char to, char temp) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, temp, to);
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    towerOfHanoi(n - 1, temp, to, from);
}

int main() {
    int n = 4;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}




