#include <stdio.h>

int fr[4];
void display();

void main()
{
    int i, j, fs[4], p[13] = {7,0,1,2,0,3,0,4,2,3,0,3,2};
    int index, k, l = 0, flag1 = 0, flag2 = 0, pf = 0, frsize = 4;

    for (i = 0; i < 4; i++)
    {
        fr[i] = -1;
    }

    for (j = 0; j < 13; j++) // Change the loop condition to 13 to cover all elements in the reference string
    {
        flag1 = 0;
        flag2 = 0;

        for (i = 0; i < 4; i++)
        {
            if (fr[i] == p[j])
            {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (i = 0; i < 4; i++)
            {
                if (fr[i] == -1)
                {
                    fr[i] = p[j];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            for (i = 0; i < 4; i++)
                fs[i] = 0;
            for (k = j - l, l = 0; l < frsize; l++, k++)
            {
                for (i = 0; i < 4; i++)
                {
                    if (fr[i] == p[k])
                        fs[i] = 1;
                }
            }

            for (i = 0; i < 4; i++)
            {
                if (fs[i] == 0)
                {
                    index = i;
                    break; // Add break here to avoid overwriting 'index'
                }
            }
            fr[index] = p[j];
            pf++;
        }
        display();
    }
    printf("\nNo of page faults : %d", pf + frsize);
}

void display()
{
    int i;
    printf("\n");
    for (i = 0; i < 4; i++) // Change the loop condition to 4 to display all frames
    {
        printf("\t%d", fr[i]);
    }
}
