// Banker's Algorithm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void a(int n, int m, int alloc[n][m], int max[n][m], int avail[m])
{
    int i, j, k;

    

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    bool safefound = true;
    for (i = 0; i < n; i++)
    {
        if (f[i] != 1)
        {
            printf("Safe Sequence could not be found.\n");
            safefound = false;
            break;
        }
    }

    if (safefound)
    {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++)
            printf("P%d -> ", ans[i]);
        printf("P%d\n", ans[n - 1]);
    }

    return;
}

void b(int n, int m, int alloc[n][m], int max[n][m], int proc[n], int avail[m])
{
    //Check if given processes are valid. If numbers are repeated it would simply give false anyway.
    for (int i = 0; i < n; i++)
    {
        if (proc[i] >= n)
        {
            printf("Enter valid process numbers\n");
            return;
        }
    }

    int need[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (need[proc[i]][j] > avail[j])
            {
                printf("\nInputted Process Sequence is not in SAFE STATE.\n");
                return;
            }
            else
            {
                for (int k = 0; k < m; k++)
                {
                    avail[k] = avail[k] + alloc[proc[i]][k];
                }
            }
        }
    }
    printf("\nThe Inputted Process Sequence is in SAFE STATE.\n");
    return;
}

//Don't use this anymore
void old_b(int n, int m, int alloc[n][m], int max[n][m], int proc[n])
{
    //Check if given processes are valid. If numbers are repeated it would simply give false anyway.
    for (int i = 0; i < n; i++)
    {
        if (proc[i] >= n)
        {
            printf("Enter valid process numbers\n");
            return;
        }
    }
    int i, j, k;

    int avail[m];
    printf("Enter available resources: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
        if (f[i] != 1 || ans[i] != proc[i])
        {
            printf("\nInputted Process Sequence is not in SAFE STATE.\n");
            return;
        }
    printf("\nInputted Process Sequence is in SAFE STATE.\n");
    return;
}

void c(int n, int m, int alloc[n][m], int max[n][m], int alloctest[m], int avail[m])
{
    int i, j, k;


    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    for (i = 0; i < m; i++)
    {
        if (alloctest[i] > avail[i])
        {
            printf("\nIt cannot run! Not enough available reasources!\n");
            return;
        }
    }
    printf("\nProcess can run, there are enough resources available.\n");
    return;
}

int main()
{
    //Number of processes, number of resources
    int n, m;

    printf("Enter number of processes: ");
    scanf(" %d", &n);
    printf("Enter number of resources: ");
    scanf(" %d", &m);

    //To store the processes and resources
    int alloc[n][m];
    int max[n][m];
    int avail[m];

    //For B and C parts
    int proc[n], alloctest[m];

    int i, j, k;

    for (i = 0; i < n; i++)
    {
        printf("\nEnter resources allocated by Process %d : ", i);
        for (j = 0; j < m; j++)
        {

            scanf(" %d", &alloc[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Maximum resources required for Process %d: ", i);
        for (j = 0; j < m; j++)
        {
            scanf(" %d", &max[i][j]);
        }
    }

    printf("Enter available resources: ");
    for (int i = 0; i < m; i++)
    {
        scanf(" %d", &avail[i]);
    }

    int opt;
    printf("\n--Menu--\n\n1. Find the sequence for processes that is in the SAFE STATE\n\n2. Enter process sequence to see if its in SAFE STATE\n\n3. Check if a given resource can run.\n\n4. Enter new processes and resources\n\n5. Exit\n\n");

    while (1)
    {
        printf("\nOption: ");
        scanf(" %d", &opt);
        switch (opt)
        {
        case 1:
            a(n, m, alloc, max, avail);
            break;

        case 2:
            printf("\nEnter the order of processes: ");
            for (i = 0; i < n; i++)
            {
                scanf(" %d", &proc[i]);
            }
            b(n, m, alloc, max, proc, avail);
            break;

        case 3:
            printf("Enter the resources allocated for the new process: ");
            for (int i = 0; i < m; i++)
            {
                scanf(" %d", &alloctest[i]);
            }

            int temp;
            printf("Enter the maximum resources required for the new process: ");
            for (int i = 0; i < m; i++)
            {
                scanf(" %d", &temp);
                alloctest[i] = temp - alloctest[i];
            }
            c(n, m, alloc, max, alloctest, avail);

            break;

        case 4:
            printf("Enter number of processes: ");
            scanf(" %d", &n);
            printf("Enter number of resources: ");
            scanf(" %d", &m);

            for (i = 0; i < n; i++)
            {
                printf("\nEnter resources allocated by the Process %d : ", i);
                for (j = 0; j < m; j++)
                {

                    scanf(" %d", &alloc[i][j]);
                }
            }

            for (i = 0; i < n; i++)
            {
                printf("\nEnter Maximum resources required for the Process %d: ", i);
                for (j = 0; j < m; j++)
                {
                    scanf(" %d", &max[i][j]);
                }
            }

            printf("Enter available resources: ");
            for (int i = 0; i < m; i++)
            {
                scanf(" %d", &avail[i]);
            }

            break;

        case 5:
            printf("\nTHE END\n");
            exit(0);

        default:
            printf("Enter a valid option!\n");
        }
    }
}
