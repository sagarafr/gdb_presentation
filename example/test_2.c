#include	<stdio.h>
#include	<stdlib.h>

int		main(void)
{
  int		**array;
  int		cpt;

  /* array = malloc(sizeof(char *) * 10); */
  array = malloc(sizeof(int *) * 10);
  cpt = 0;
  while (cpt < 10)
    {
      /* array[cpt] = malloc(sizeof(char) * 10); */
      array[cpt] = malloc(sizeof(int) * 10);
      cpt += 1;
    }
  cpt = 0;
  array[0][2] = 10;
  /* array[0][42] = 100; */
  printf("%i\n", array[0][2]);
  /* printf("%i\n", array[0][42]); */
  while (cpt < 10)
    {
      free(array[cpt]);
      cpt += 1;
    }
  free(array);
  /* array[2][2] = 10; */
  return (0);
}
