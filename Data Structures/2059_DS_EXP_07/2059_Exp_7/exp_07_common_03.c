#include <stdio.h>

void tower(int n, char src_rod, char des_rod, char tem_rod) {
    if (n == 1) 
	{
        printf("Move disk 1 from rod %c to rod %c\n", src_rod, des_rod);
        return;
    }
    tower(n - 1, src_rod, tem_rod, des_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, src_rod, des_rod);
    tower(n - 1, tem_rod, des_rod, src_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower(n, 'A', 'C', 'B');
    return 0;
}
