#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct      s_env
{
    char            *name;
    char            *content;
    struct  s_env   *next;
}                   t_env;

extern  char **environ;

char **    ft_strsplit(char *str, char c);

void    push_back(t_env **head, char *str)
{
    t_env   *new;
    t_env   *last;
    char    **split;
    
    split = ft_strsplit(str, '=');
    last = *head;
    new = (t_env *)malloc(sizeof(t_env));
    new->name = strdup(split[0]);
    new->content = strdup(split[1]);
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
        printf("%s=%s\n", env->name, env->content);
        env = env->next;
    }
    
    return (0);
}
