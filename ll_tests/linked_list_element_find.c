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

t_env   *find_elem(t_env **env, char *str)
{
    while (*env)
    {
        if (strcmp( (*env)->name, str) == 0)
            return (*env);
        *env = (*env)->next;
    }
    return (NULL);
}

void    test2(t_env **env)
{
    int i = 0;
    
    while (environ[i])
        push_back(env, environ[i++]);
    t_env * x = find_elem(env, "PWD");
    
    x->content = strdup("1111111111111");
    
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
