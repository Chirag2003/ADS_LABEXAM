#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int hash[SIZE];
void insert()
{
    int key, index, i, flag = 0, hkey;
    printf("\nENETR VALUE: ");
    scanf("%d", &key);
    hkey = key % SIZE;
    for (i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
            printf("\nELEMENT CANNOT BE INSERTED\n");
        else
        {
            index = (hkey + i) % SIZE;
            if (hash[index] == NULL)
            {
                hash[index] = key;
                break;
            }
        }
    }
}

void search()
{
    int key, index, i, flag = 0, hkey;
    printf("\nENETR VALUE TO BE SEARCHED: ");
    scanf("%d", &key);
    hkey = key % SIZE;
    for (i = 0; i < SIZE; i++)
    {
        index = (hkey + i) % SIZE;
        if (hash[index] == key)
        {
            printf("\nVALUE FOUND AT INDEX %d", index);
            break;
        }
    }
    if (i == SIZE)
        printf("\nVALUE NOT FOUND\n");
}

void hash_display()
{
    int i;
    printf("\nELEMENTS IN THE HASH TABLE ARE \n");
    for (i = 0; i < SIZE; i++)
        printf("\nINDEX %d \t VALUE =  %d", i, hash[i]);
}

int main()
{
    int ch, opt;
    struct Graph *graph;
    int ver, start;
main_menu:
    printf("\n1. INSERT\n2. DISPLAY\n3. SEARCH\n4. EXIT\n");
    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        insert();
        goto main_menu;
        break;
    case 2:
        hash_display();
        printf("\n");
        goto main_menu;
        break;
    case 3:
        search();
        goto main_menu;
        break;
    case 4:
        return 0;
    }
}
