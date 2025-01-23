#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  size_t size = 10 * sizeof(int);
  int *arr = (int *)malloc(size);

  if (arr == NULL)
  {
    printf("error hi error");
    exit(1);
  }

  for (int i = 0; i < 10; i++)
  {
    arr[i] = i + 1;
  }

  size_t newsize = 15 * sizeof(int);
  int *newArr = (int *)malloc(newsize);

  if (newArr == NULL)
  {
    printf("error hi error");
    exit(1);
  }

  memcpy(newArr, arr, size);

  free(arr);

  for (int i = 0; i < 15; i++)
  {
    newArr[i] = i + 1;
  }

  printf(" after alloc\n");
  for (int i = 0; i < 15; i++)
  {
    printf("%d", newArr[i]);
  }

  free(newArr);
  return 0;
}