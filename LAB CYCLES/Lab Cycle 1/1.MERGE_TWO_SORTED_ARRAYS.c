#include<stdio.h>
void main()
{
int n, m, i, j, k, c[40], a[20], b[20];
printf ("Enter limit for A:");
scanf ("%d", &n);
printf ("\nEnter limit for B:");
scanf ("%d", &m);
printf ("Enter elements for A in sorted order:-\n");
for (i = 0; i < n; i++)
    {
scanf ("%d", &a[i]);
    }
printf ("Enter elements for B in sorted order:-\n");
for (j = 0; j < m; j++)
    {
scanf ("%d", &b[j]);
    }
i = j = k = 0;
while (i < n && j < m)
    {
if (a[i] < b[j])
   {
   c[k++] = a[i++];
   }
else if (a[i] > b[j])
	{
	 c[k++] = b[j++];
	}
else
	{
    c[k++] = b[j++];
	  i++;
	  j++;
    }}
if (i < n)
{
for (int t = 0; t < n; t++)
{
c[k++] = a[i++];
}}
if (j < m)
    {
    for (int t = 0; t < m; t++)
      {
	c[k++] = b[j++];
      }}
printf ("\n");
for (k = 0; k < (m + n); k++)
  {
printf ("\t \n %d ", c[k]);
  }
printf("\n");
}
