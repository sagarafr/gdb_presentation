int	facto(int a);

int	facto(int a)
{
  int	b;

  b = a + 1;
  return (facto(b));
}

int	main(void)
{
  facto(100);
  return (0);
}
