#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(char *name);
int exec(int len, char *name);

extern char **environ;

char *_getenv(char *name)
{
	int i = 0;
	char *token, *buf, *value;

	while (environ[i])
	{
		token = strtok(environ[i++], "=");
		if (strcmp(name, token) != 0)
            continue;

        token = strtok(NULL, "=");
        buf = strtok(NULL, "\0");

        if (!buf)
            return (token);

        value = malloc(sizeof(char) * strlen(token) + strlen(buf) + 2);
        strcat(value, token), strcat(value, "="), strcat(value, buf);
        return (value);
	}
	return ("doesn't exist");
}

int main(void)
{
	printf("%s\n", _getenv("VSCODE_IPC_HOOK_CLI"));
	return (0);
}
