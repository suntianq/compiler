
;; Function main (main, funcdef_no=0, decl_uid=2247, cgraph_uid=0, symbol_order=0)

main ()
{
  int m;
  int n;
  int t;
  int i;
  int b;
  int a;
  int D.2259;

  a = 0;
  b = 1;
  i = 1;
  m = 100;
  scanf ("%d", &n);
  printf ("%d\n", a);
  printf ("%d\n", b);
  goto <D.2256>;
  <D.2255>:
  t = b;
  b = a + b;
  printf ("%d\n", b);
  a = t;
  i = i + 1;
  <D.2256>:
  n.0_1 = n;
  if (i < n.0_1) goto <D.2255>; else goto <D.2257>;
  <D.2257>:
  n = {CLOBBER};
  D.2259 = 0;
  goto <D.2260>;
  <D.2260>:
  return D.2259;
}


