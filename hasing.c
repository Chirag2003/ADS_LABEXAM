#include <stdio.h>
#include <stdlib.h>

struct Index
{
    int row;
    int column;
};

void printHash(int arr[8][4])
{
    int r = 8, c = 4;
    for (int i = 0; i < r; i++)
    {
        printf("%d | ", i);
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

struct Index inputValue(int arr[8][4], int value)
{
    struct Index index;
    int key = value % 8;
    int placed = 0;
    int col = 0;

    for (int j = 0; j < 4; j++)
    {
        if (arr[key][j] == -1 && placed == 0)
        {
            arr[key][j] = value;
            placed = 1;
            col = j;
        }
    }

    if (placed == 1)
    {
        index.row = key;
        index.column = col;
        return index;
    }
    else
    {
        int limit = key;
        key = (key + 1) % 8;
        while (key != limit)
        {
            for (int j = 0; j < 4; j++)
            {
                if (arr[key][j] == -1 && placed == 0)
                {
                    arr[key][j] = value;
                    placed = 1;
                    col = j;
                }
            }

            if (placed == 1)
            {
                index.row = key;
                index.column = col;
                return index;
            }
            else
            {
                key = (key + 1) % 8;
            }
        }

        if (placed == 0)
        {
            printf("Table Full!!");
        }
    }
}

int main()
{
    int hashtable[8][4];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            hashtable[i][j] = -1;
        }
    }

    printHash(hashtable);

    int c = 0;
    printf("Hash Table Program\nHash Key = %%8\n");
    while (c == 0)
    {
        int choice;
        printf("\nEnter 1 to input value\nEnter 2 to print Hash Table\nEnter 0 to Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int value;
            printf("Enter a number\n");
            scanf("%d", &value);
            struct Index index = inputValue(hashtable, value);
            printf("Value added to index (%d , %d)\n", index.row, index.column);
        }
        break;

        case 2:
            printHash(hashtable);
            break;

        case 0:
            c = 1;
            break;

        default:
            printf("Invalid Input");
            break;
        }
    }
}