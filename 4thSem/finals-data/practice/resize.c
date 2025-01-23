#include <stdio.h>
#include <stdlib.h>

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

  size_t newSize = 20 * sizeof(int);
  arr = (int *)realloc(arr, newSize);
  for (int i = 10; i < 20; i++)
  {
    arr[i] = i + 1;
  }

  // print
  for (int i = 0; i < 20; i++)
  {
    printf("%d", arr[i]);
  printf("\t");
  }
  printf("\n");

  free(arr);
  return 0;
}