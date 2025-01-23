#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct
{
  char dname[10];
  char fname[10][10];
  int fcnt;
} dir;

int main()
{
  int i, ch;
  char f[30];
  dir.fcnt = 0;

  printf("\nEnter name of directory -- ");
  scanf("%s", dir.dname);

  while (1)
  {
    printf("\n\n1. Create File\t2. Delete File\t3. Search File\n");
    printf("4. Display Files\t5. Exit\nEnter your choice -- ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("\nEnter the name of the file -- ");
      scanf("%s", dir.fname[dir.fcnt]);
      dir.fcnt++;
      break;

    case 2:
      printf("\nEnter the name of the file -- ");
      scanf("%s", f);
      for (i = 0; i < dir.fcnt; i++)
      {
        if (strcmp(f, dir.fname[i]) == 0)
        {
          printf("File %s is deleted\n", f);
          strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
          dir.fcnt--;
          break;
        }
      }
      if (i == dir.fcnt)
        printf("File %s not found\n", f);
      break;

    case 3:
      printf("\nEnter the name of the file -- ");
      scanf("%s", f);
      for (i = 0; i < dir.fcnt; i++)
      {
        if (strcmp(f, dir.fname[i]) == 0)
        {
          printf("File %s is found\n", f);
          break;
        }
      }
      if (i == dir.fcnt)
        printf("File %s not found\n", f);
      break;

    case 4:
      if (dir.fcnt == 0)
        printf("\nDirectory Empty\n");
      else
      {
        printf("\nThe Files are -- ");
        for (i = 0; i < dir.fcnt; i++)
          printf("\t%s", dir.fname[i]);
        printf("\n");
      }
      break;

    case 5:
      exit(0);

    default:
      printf("Invalid choice! Please try again.\n");
    }
  }

  return 0;
}
