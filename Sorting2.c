#include  < stdio.h > 
void  sort ( int  arr [],  int  n )  { 
int  i ,  j ,  temp ; 
for  ( i  =  0 ;  i  <  n  -  1 ;  i ++)  { 
for  ( j  =  0 ;  j  <  n  -  i  -  1 ;  j ++)  { 
if  ( arr [ j ]  >  arr [ j  +  1 ])  { 
temp  =  arr [ j ]; 
arr [ j ]  =  arr [ j  +  1 ]; 
arr [ j  +  1 ]  =  temp ; 
} 
} 
} 
} 
int  binarySearch ( int  arr [],  int  n ,  int  target )  { 
int  low  =  0 ,  high  =  n  -  1 ; 
while  ( low  <=  high )  { 
int  mid  =  ( low  +  high )  /  2 ; 
if  ( arr [ mid ]  ==  target ) 
return  1 ; 
else  if  ( arr [ mid ]  <  target ) 
low  =  mid  +  1 ; 
else 
} 
high  =  mid  -  1 ; 
return  0 ; 
} 
int  main ()  { 
int  n ,  x ; 
printf ( "Enter n: " ); 
scanf ( "%d" ,  & n ); 
int  S1 [ n ],  S2 [ n ]; 
printf ( "Enter elements of S1:\n" ); 
for  ( int  i  =  0 ;  i  <  n ;  i ++) 
scanf ( "%d" ,  & S1 [ i ]); 
printf ( "Enter elements of S2:\n" ); 
for  ( int  i  =  0 ;  i  <  n ;  i ++) 
scanf ( "%d" ,  & S2 [ i ]); 
printf ( "Enter x: " ); 
scanf ( "%d" ,  & x ); 
sort ( S2 ,  n ); 
for  ( int  i  =  0 ;  i  <  n ;  i ++)  { 
int  target  =  x  -  S1 [ i ]; 
if  ( binarySearch ( S2 ,  n ,  target ))  { 
printf ( "YES\n" ); 
return  0 ; 
} 
} 
printf ( "NO\n" ); 
return  0 ; 
} 
