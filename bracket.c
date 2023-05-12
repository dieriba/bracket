# include <stdio.h>

int check_if_valid_bracket(const char *msg, char to_find, int i)
{
    while (msg[++i])
    {
        if (msg[i] == '(' || msg[i] == '{' || msg[i] == '[')
        {
            i = check_if_valid_bracket(msg, (msg[i] % 2 ? msg[i] + 2 : msg[i] + 1), i);
            if (i == -1)
                    return -1;
        }
        else if (msg[i] == ')' || msg[i] == '}' || msg[i] == ']')
            return (msg[i] != to_find) ? -1 : i;
    }
    return msg[i] != to_find ? -1 : 0; 
}

int main (int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (check_if_valid_bracket(argv[i], 0, -1) == 0)
            printf("OK\n");
        else
            printf("Error\n");
    }
}
