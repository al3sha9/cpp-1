#include <stdio.h>

int main()
{
  int numFrames, pageFaults = 0, frameCount = 0, refString[25], frames[10], stringLenght;

  printf("Enter lenght of string");
  scanf("%d", stringLenght);

  printf("Enter reference string");
  for (int i = 0; i < stringLenght; i++)
  {
    scanf("%d", refString[i]);
  }

  printf("Enter Number of frames");
  scanf("%d", &numFrames);

  for (int i = 0; i < numFrames; i++)
  {
    frames[i] = -1;
  }

  printf("Page replacement process is :");



  return 0;
}