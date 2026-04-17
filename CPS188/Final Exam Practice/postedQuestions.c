/*
S01. Convert 32 into signed integer binary.
a) 1000 0000 0000 0000 0000 0000 0101 1001
b) 0000 0000 0000 0000 0000 0000 0010 0000
c) 0000 0000 0000 0000 0000 0000 0001 0000
d) 1000 0000 0000 0000 0000 0000 0010 0000
e) none of the above

ANS: b)

S02. Convert 0000 0000 0000 0000 0000 0000 1100 0111 into a decimal integer.
a) 123  	
b) 194  	
c) 199  		
d) 227  	
e) none of the above

ANS: c)

S03. Convert 1100 0001 0100 0000 0000 0000 0000 0000 into a decimal floating point.
a) 35.0 		
b) -200.0 	
c) -12.0 		
d) -24.0 		
e) none of the above

ANS: c)

S04. Convert 2A (hexadecimal) into a decimal integer.
a) 21 		
b) 35 	
c) 42 		
d) 68 		
e) none of the above

ANS: c)

S05. Which expression is invalid (all variables are declared as int)?
a) a+b-0 
b) c%a%4 
c) xm6-24 
d) xf3r6+2
e) all are valid

ANS: 

S06. Which expression is invalid?
a) ant+int 
b) one+twx 
c) three*3 
d) four/-4
e) all are valid

ANS: a)

For questions S07 and S08: Assuming int a=10, b=5, c=1, d=2; double w=3.5, x=-5.0, y=2.5, z=1.0; What would be the exact output of the printf statement? (# means a space)

S07. printf ("%3.2lf", -a-x);
a) ###-5 
b) -5.00 
c) -5.0 
d) -5.
e) none of the above

ANS: b)

S08. printf ("%-4d", 5-c/d);
a) 2### 
b) 4.5 
c) 4 
d) 5###
e) none of these

ANS: d)

S09. What will be printed by printf("%d", strlen("The Lord of the Rings")); ?
a) 19		
b) 20		
c) 21		
d) 22		
e) none of the above

ANS: 21 (excludes NULL character)

S10. What will be printed by printf("%d", atoi("33.33ff")); ?
a) 33			
b) 33.33		
c) 3333
d) 33.33ff		
e) none of the above

ANS: a) (reads until non numerical character is reached)

S11. What is the correct syntax of the while statement?
a) while [x > 2] x=x+1;
b) while {x > 2} x=x+1;
c) while (x > 2) x=x+1;
d) while x > 2 x=x+1;
e) none of the above

ANS: c) 

S12. What C function allocates cells in an array dynamically and initializes all cells at zero?
a) alloc
b) calloc
c) malloc
d) free
e) none of the above

ANS: b) (calloc sets all to zero. malloc sets to the first byte, but leaves garbage everywhere)

S13. What is the output of printf("%0.2lf", (double)2 / 4 / 2); ?
a) 0.00
b) 0.25
c) 0.50
d) 0
e) none of the above

ANS: b)

S14. In C, what is the correct way to assign a value to a string variable named s?
a) s = 'this is a string value';
b) s = "this is a string value";
c) s = strncpy ("this is a string value")
d) strncpy (s, "this is a string value", sizeof(s));
e) none of the above

ANS: d)

S15. What is the C keyword that creates a type alias or synonym?
a) alias	
b) synonym		
c) type	
d) typedef		
e) none of the above

ANS: d)

S16. What is the C operator that counts the number of bytes in a variable, structure or array?
a) size	
b) sizeof	   
c) countb	
d) nbytes		
e) none of the above

ANS: b)

S17. Which if statement checks if x is a real number that is also a whole number (for example, 14.0 is a whole number, 3.57 is not).
a) if (whole(x)) 
b) if (x == ceil(x))
c) if (x = !x) 
d) if (x == x)
e) none of the above

ANS: b)

S18. Identify the condition that will always be false.
a) if (3 < x < 2) 
b) if (x < 3 || x >= 2)
c) if (x < 3 && x < 2) 
d) if (x > 3 && x < 2)
e) none of the above

ANS: d)

S19. Complete the program by adding the missing line (position indicated by ► )
#include <stdio.h>
int
main (void)
{
	int age, senior;
	scanf ("%d", &age);
	senior = age >= 65;
►
		printf ("You do not qualify for the seniors discount\n");
	else
		printf ("You qualify for the seniors discount");
	return (0);
}
a) if (senior) 
b) if (!senior)
c) if (senior == false) 
d) if (senior >= 65)
e) none of the above

ANS: b) (note: relational operators (>=, <=, ==) occur before assignment)

S20. What is the output of this program?
#include <stdio.h>
int cps (int mark, int *num)
{
	int gp;
	gp = mark - 5;
	*num = gp + mark;
	return (gp);
}
int
main (void)
{
	int tt=10, vv;
	tt = cps (tt, &vv);
	printf ("%d", tt+vv);
	return (0);
}
a) 0		b) 5		c) 10		d) 15
e) none of the above

ANS: e)

S21.What is the output of this program?
#include <stdio.h>
int cps (int mark)
{
	mark = mark-3;
	return (mark);
}
int ckcs (int num)
{
	num= cps(num) /2;
	return (num);
}
int
main (void)
{
	int t=12;
	t = ckcs (t)-1;
	printf ("%d", t);
	return (0);
}
a) 12
b) 9
c) 6
d) 3
e) none of the above

ANS: d) (remember integer division)

S22. What is the output of this program?
#include <stdio.h>
int main (void)
{
	int scalar_product, n, k;
	int v1[]={2,3,1};
	int v2[]={1,2,4};
	scalar_product = 0;
	n=3;
	for (k = 0; k < n; ++k)
		scalar_product = scalar_product + v1[k]*v2[k];
	printf ("The scalar product is: %d.", scalar_product);
	return (0);
}
a) 2		
b) 10		
c) 12		
d) 40
e) none of the above

ANS: c)

S23. What is the output of this program?
#include <stdio.h>
int toronto (int x) {
     int w;
	if (x == 0) w = 1; else w = toronto (x-1);
	return (w);
}
int main (void) {
	int a = 2;
	printf ("%d", toronto (a));
	return (0);
}
a) 0          
b) 1      
c) 2          
d) -1		
e) none of the above

ANS: b) (always returns 1)

S24. What is the output of the following program? 
#include <stdio.h> 
int 
f1 (int w[], int x) 
{
int y=0, i;
for (i=0; i<x; ++i) y=y+w[i];
}
int main (void) 
{ 
int a;
int b[5] = {3,4,5,6,7};
printf ("%d", f1(b,5));
return (0); 
} 
a) 3 		b) 5 		c) 12 	d) 25 
e) none of the above

ANS: idk if it was intentional but f1 doesnt return so the answer is e)

S25. What is the output of the following program? 
#include <stdio.h> 
#define ZZ(a) a+a-a
int 
main (void) { 
int x=50;
printf ("%d", ZZ(x));
return (0); 
} 
a) 0 		b) 50 		c) 100 		d) 150 		e) none of these

ANS: b)

S26. What is the output of the following program?
#include <stdio.h> 
#define BB(b) b-b
int 
main (void) 
{ 
int x = 33;
int* y = &x;
printf ("%d%d", BB(x), BB(*y));
return (0); 
} 
a) 33
b) 3333 
c) 0 
d) 00 
e) none of the above

ANS: d)

S27.What is the missing line in this program (position indicated by ► )?
#include <stdio.h> 
int  
main (void) 
{ 
double x[100]; 
► 
    initializing the array with 0.0
for (i=0; i<100; ++i) 
     x[i] = 0.0; 
    printing the array for verification
for (i=0; i<100; ++i) 
     printf ("%5.1lf", x[i]); 
return (0); 
} 
a) int x; 
b) int i; 
c) printf (“%d”, i); 
d) int i[100]; 
e) none of the above

ANS: b)

S28. Identify the error in this program. 
#include <stdio.h> 
int main (void) 
{ 
  int x[100], i, value; 
  printf ("Enter a value: "); 
  scanf ("%d", &value); 
  fill_array (x, 100, value);  
  for (i=0; i<100; ++i) printf ("%d ", x[i]); 
  return (0); 
} 
a) int x[100]; should be int x(100); 
b) fill_array function does not exist 
c) scanf ("%d", &value); should be scanf ("%d", value); 
d) printf ("%d ", x[i]); should be printf ("%d ", &x[i]); 
e) no errors in the program

ANS: b)

S29. What action is easier in an array than a linked list?
a) adding a new element at the beginning
b) accessing a specific element
c) insertion an element in the middle
d) none of the above
e) all of the above

ANS: b)

S30. What is the equivalent of (*p).value?
a) p.value
b) &p.value
c) p*value
d) p->value
e) none of the above

ANS: d)

S31. Which of the following storage classes initializes the variable at 0?
a) auto
b) static
c) register
d) none of the above
e) all of the above

ANS: b) static (local variables)

S32. Which GNUPlot command will place a label (years) next to the horizontal (x) axis?
a) set label x 'years'
b) set xlabel 'years'
c) plot 'data.data' xlabel 'years'
d) set xtics 'years'
e) plot xlable 'years'

ANS: b)

S33. What will be the value of p after the following statements?
char phone[]="555-0202"; double p; p = atof(phone);
a) 5550202
b) 555.0202
c) 555.0
d) 5550202.0
e) none of the above

ANS: atof works like atoi, stopping at the first non numerical character c)

S34. What GNUPlot command will generate the following graph?

a) plot log(x) with lp
b) plot log(x) with l
c) plot log(x) with lp
d) plot log(x) with boxes
e) none of the above

ANS: b)

S35. What GNUPlot command will you use to have a graph without a legend?
a) unset key
b) set legend off
c) set key top right
d) set key invisible
e) none of the above

ANS: a) (i tested it)

S36. Which of these statements is correct to send the value of w into a binary file?
a) fwrite (outf, "%d", w);
b) fwrite (&w, sizeof(w), 1, outf);
c) fprintf (outf, &w, sizeof(w));
d) fwrite (outf, &w);
e) none are correct

ANS: fwrite(name of array, size of elements, number of elements, file to write to) b)

S37. How many pointer components are required in a structure used for a binary tree?
a) 1       b) 2       c) 3       d) 4       e) 0

ANS: b)

*/

#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
	int age, senior;
	scanf ("%d", &age);
	senior = age >= 65;
    if(!senior)
		printf ("You do not qualify for the seniors discount\n");
	else
		printf ("You qualify for the seniors discount");
	return (0);
}