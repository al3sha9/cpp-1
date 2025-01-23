#include <stdio.h>

void main()
{
    int i, j, k, numFrames, pageFaults = 0, frameCount = 0, referenceString[25], frames[10], stringLength;

    printf("\nEnter the length of reference string: ");
    scanf("%d", &stringLength);

    printf("\nEnter the reference string: ");
    for(i = 0; i < stringLength; i++)
        scanf("%d", &referenceString[i]);

    printf("\nEnter the number of frames: ");
    scanf("%d", &numFrames);

    // Initialize frames array with -1 (empty frames)
    for(i = 0; i < numFrames; i++)
        frames[i] = -1;

    printf("\nThe Page Replacement Process is:\n");

    for(i = 0; i < stringLength; i++)
    {
        // Check if the current page is already in one of the frames
        for(k = 0; k < numFrames; k++)
        {
            if(frames[k] == referenceString[i])
                break;
        }

        // If the page is not found in any of the frames, replace a page
        if(k == numFrames)
        {
            frames[frameCount++] = referenceString[i];
            pageFaults++;
        }

        // Display the current state of frames
        for(j = 0; j < numFrames; j++)
            printf("\t%d", frames[j]);

        // If a page fault occurred, display the page fault number
        if(k == numFrames)
            printf("\tPF No. %d", pageFaults);

        printf("\n");

        // Reset the frame counter if we reach the maximum number of frames
        if(frameCount == numFrames)
            frameCount = 0;
    }

    printf("\nThe number of Page Faults using FIFO are %d", pageFaults);
}
