#include	<stdlib.h>
#include	<stdio.h>

# ifndef SIZE_ONE
#  define SIZE_ONE 10
# endif	/* !SIZE_ONE */

# ifndef SIZE_TWO
#  define SIZE_TWO 10
# endif	/* !SIZE_TWO */

int		**alloc_double_array(int size_one, int size_two);
void		free_double_array(int **double_array, int size_two);
int		**init_double_array(int **double_array,
				    int size_one, int size_two);

int		**alloc_double_array(int size_one, int size_two)
{
  int		**r_double_array;
  int		cpt;

  cpt = 0;
  if ((r_double_array = malloc(sizeof(int *) * size_one)) == NULL)
    return (NULL);
  while (cpt < size_one)
    {
      if ((r_double_array[cpt] = malloc(sizeof(int) * size_two)) == NULL)
	return (NULL);
      cpt += 1;
    }
  return (r_double_array);
}

void		free_double_array(int **double_array, int size_two)
{
  int		cpt;

  cpt = 0;
  while (cpt < size_two)
    {
      free(double_array[cpt]);
      cpt += 1;
    }
  free(double_array);
}

int		**init_double_array(int **double_array,
				    int size_one, int size_two)
{
  int		**tmp;/* [size_one][size_two]; */
  int		cpt_one;
  int		cpt_two;
  
  cpt_one = 0;
  tmp = alloc_double_array(size_one, size_two);
  while (cpt_one < size_one)
    {
      cpt_two = 0;
      while (cpt_two < size_two)
	{
	  tmp[cpt_one][cpt_two] += double_array[cpt_one][cpt_two];
	  cpt_two += 1;
	}
      free_double_array(double_array, size_two);
      printf("%p\n", (void *)(double_array[cpt_one]));
      free(double_array[cpt_one]);
      double_array[cpt_one] = tmp[cpt_one];
      printf("%p\n\n", (void *)(double_array[cpt_one]));      
      cpt_one += 1;
    }
  free(tmp);
  return (double_array);
}

int		main(void)
{
  int		**double_array;
  int		cpt_one;
  int		cpt_two;

  srand(1337);
  double_array = alloc_double_array(SIZE_ONE, SIZE_TWO);
  cpt_one = 0;
  while (cpt_one < SIZE_ONE)
    {
      cpt_two = 0;
      while (cpt_two < SIZE_TWO)
	{
	  double_array[cpt_one][cpt_two] = rand() % 100;
	  cpt_two += 1;
	}
      cpt_one += 1;
    }
  free_double_array(init_double_array(double_array,
				      SIZE_ONE, SIZE_TWO), SIZE_TWO);
  return (0);
}
