#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int factorial(int num)
{
  if (num == 0)
  {
    return 1;
  }
  return num * factorial(num - 1);
}

int main()
{
  int pipefd[2];

  if (pipe(pipefd) == -1)
  {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  int number;
  printf("Enter a number: ");
  scanf("%d", &number);

  int pid = fork();

  if (pid < 0)
  {
    printf("FORK FAIED");
  }
  else if (pid == 0)
  {
    close(pipefd[1]);
    read(pipefd[0], &number, sizeof(number));
    close(pipefd[0]);
    printf("Child Process\n");
    printf("Factorial of the given number is: %d\n", factorial(number));
  }
  else
  {
    close(pipefd[0]);
    write(pipefd[1], &number, sizeof(number));
    close(pipefd[1]);
    printf("PARENT PROCESS\n");
  }
}