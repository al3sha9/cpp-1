#include <stdio.h>
#include <stdlib.h>

int main()
{
  size_t size = 10 * sizeof(int);
  int *arr = (int *)malloc(size);

  if(arr == NULL){
    printf("error hi error");
  }

  for (int i = 0; i < 10; i++)
  {
    arr[i] = i + 1;
  }

  return 0;
}