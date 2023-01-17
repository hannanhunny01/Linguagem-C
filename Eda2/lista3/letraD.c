#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 101

char ht[TABLE_SIZE][16];
int size = 0;

int hash(char *k)
{
    int h = 0;
    for (int i = 0; k[i] != '\0'; i++)
        h += k[i] * (i+1LL);
    return (h * 19) % TABLE_SIZE;
}

int search(char *s)
{
    int h = hash(s);
    for (int j = 0; j < 20; j++)
    {
        int i = (h + j*j + 23LL*j) % TABLE_SIZE;
        if (strcmp(ht[i], s) == 0)
            return 1;
    }
    return 0;
}

void insert(char *s)
{
    if (search(s))
        return;

    int h = hash(s);
    for (int j = 0; j < 20; j++)
    {
        int i = (h + j*j + 23LL*j) % TABLE_SIZE;
        if (*ht[i] == '\0')
        {
            strcpy(ht[i], s);
            size++;
            break;
        }
    }
}

void delete(char *s)
{
    int h = hash(s);
    for (int j = 0; j < 20; j++)
    {
        int i = (h + j*j + 23LL*j) % TABLE_SIZE;
        if (strcmp(ht[i], s) == 0)
        {
            *ht[i] = '\0';
            size--;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < TABLE_SIZE; i++)
            *ht[i] = '\0';
        size = 0;

        int n;
        scanf("%d", &n);
        char m[4], s[16];
        while (n--)
        {
            scanf("%s:%s", m, s);
            if (m[0] == 'A')
                insert(s);
            else
                delete(s);
        }
        printf("%d\n", size);
        for (int i = 0; i < TABLE_SIZE; i++)
            if (*ht[i] != '\0')
                printf("%d:%s\n", i, ht[i]);
    }
    return 0;
}