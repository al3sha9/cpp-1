#include <stdio.h>
#include <math.h>

int main()
{
  int processSize, numberOfPages, pageSize, pageNumber, frameNumber;
  int pageTable[3] = {2, 4, 6};
  double pagesRequired;
  int offset, relativeAdress = 0;

  printf("Enter process size in KB (max 12)");
  scanf("%d", &processSize);

  pagesRequired = processSize / 4.0;
  numberOfPages = ceil(pagesRequired);

  printf("total pages are: %d", numberOfPages);
  printf("Enter relative address (in hexadecimal notation, e.g. 0XRA): \n");
  scanf("%d", &relativeAdress);

  pageNumber = relativeAdress / 1000;
  offset = relativeAdress % 1000;

  printf("PageNumer is %d", pageNumber);
  printf("Page table:\n");
  for (int i = 0; i < numberOfPages; i++)
  {
    printf("%d [%d]\n", i, pageTable[i]);
  }

  frameNumber = pageTable[pageNumber];
  printf("Equivalent physical address: %d%d\n", frameNumber, offset);

  return 0;
}