#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *_getenv(char *name);
int exec(int len, char *name);

extern char **environ;

char *_getenv(char *name)
{
    int i = 0, cmp = 0, cmp2 = 0, j = 0, len, a = 0, f = 0;
    char *fin, *top, **arr;
    top = "boy";

    len = strlen(name);

    while (environ[i])
    {
        j = 0;
        while (environ[i][j] != '=')
            j++;
        char word[j];

        word[j] = '\0';

        if (j == len)
        {
            cmp = 0;
            while (environ[i][cmp] != '=')
            {
                word[cmp] = environ[i][cmp];
                cmp++;
            }
            a = strcmp(word, name);
            if (a == 0)
            {
                printf("%s : is Valid\n", word);
                environ[i][cmp++];
                cmp2 = cmp;
                while (environ[i][cmp] != '\0')
                    cmp++;
                char final[cmp];

                while (environ[i][cmp2] != '\0')
                {
                    final[f] = environ[i][cmp2];
                    cmp2++;
                    f++;
                }
                arr[0] = final;
                printf("%s\n", arr[0]);
                return arr[0];

            }
        }
        i++;
    }
    printf("nah here i dey\n");
    return NULL;
}


int main(void)
{
    printf("%s\n", getenv("USER"));
    char *file;
    file = _getenv("USER");
    printf("ENV is: %s \n", file);

    return 0;
}
