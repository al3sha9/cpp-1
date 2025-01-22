#include <stdio.h>
#include <stdlib.h>

int main()
{
  size_t size = 10 * sizeof(int);
  int *arr = (int *)malloc(size);

  if (arr == NULL)
  {
    printf("error");
    exit(1);
  }

  for (int i = 0; i < 10; i++)
  {
    arr[i] = i + 1;
  }

  for (int i = 0; i < 10; i++)
  {
    printf("%d", arr[i]);
  }
  printf("\n");

  free(arr);

  return 0;
}