#include <stdio.h>
#include <unistd.h>

int factorial(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int pid = fork();

    if (pid < 0) {
        printf("Fork Failed\n");
    } else if (pid == 0) {
        printf("Child Process\n");
        printf("Factorial of the given number is: %d\n", factorial(num));
    } else {
        printf("Parent Process\n");
    }

    return 0;
}
