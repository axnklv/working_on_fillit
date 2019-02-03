#include <stdio.h>
#include <stdlib.h>

int ft_sqrt(int nb);

int main(int argc, char **av)
{
  int nb = 0;
  
  if (argc == 2)
    {
      nb = atoi(av[1]);
      printf("%d\n", ft_sqrt(nb));
    }
  return (0);
}
