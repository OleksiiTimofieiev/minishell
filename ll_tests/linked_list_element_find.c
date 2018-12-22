#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  s_env
{
    char        *name;
    char        *content;
    struct  s_env *next;
}               t_env;

extern  char **environ;

void    push_back(t_env **head, char *str)
{
    t_env   *new;
    t_env   *last;
    
    last = *head;
    new = (t_env *)malloc(sizeof(t_env));
    new->name = strdup(str);
    new->next = NULL;

    if (!*head)
        *head = new;
    else
    {
        while (last->next)
            last = last->next;
        last->next = new;
    }
}

void    test2(t_env **env)
{
    int i = 0;
    
    while (environ[i])
        push_back(env, environ[i++]);
    
}

void    test1(t_env **env)
{
    test2(env);
}

int     main(void)
{
    t_env *env = NULL;
    
    test1(&env);
    
    int i = 0;
    while (env)
    {
        printf("%s\n", env->name);
        env = env->next;
    }
    
    
    
    
    return (0);
}
