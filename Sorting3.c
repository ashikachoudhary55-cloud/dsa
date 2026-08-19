#include  < stdio.h > 
#include  < stdlib.h > 
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
int  findKSum ( int  arr [],  int  n ,  int  k ,  int  T , 
int  start ,  int  count ,  int  sum )  { 
if  ( count  ==  k  -  1 )  { 
int  target  =  T  -  sum ; 
if  ( binarySearch ( arr ,  n ,  target )) 
return  1 ; 
return  0 ; 
} 
for  ( int  i  =  start ;  i  <  n ;  i ++)  { 
if  ( findKSum ( arr ,  n ,  k ,  T , 
i  +  1 ,  count  +  1 , 
sum  +  arr [ i ])) 
return  1 ; 
} 
return  0 ; 
} 
int  main ()  { 
int  n ,  k ,  T ; 
printf ( "Enter n: " ); 
scanf ( "%d" ,  & n ); 
int  arr [ n ]; 
printf ( "Enter elements:\n" ); 
for  ( int  i  =  0 ;  i  <  n ;  i ++) 
scanf ( "%d" ,  & arr [ i ]); 
printf ( "Enter k: " ); 
scanf ( "%d" ,  & k ); 
printf ( "Enter T: " ); 
scanf ( "%d" ,  & T ); 
// Sort the array 
for  ( int  i  =  0 ;  i  <  n  -  1 ;  i ++)  { 
for  ( int  j  =  0 ;  j  <  n  -  i  -  1 ;  j ++)  { 
if  ( arr [ j ]  >  arr [ j  +  1 ])  { 
int  temp  =  arr [ j ]; 
arr [ j ]  =  arr [ j  +  1 ]; 
arr [ j  +  1 ]  =  temp ; 
} 
} 
} 
if  ( findKSum ( arr ,  n ,  k ,  T ,  0 ,  0 ,  0 )) 
printf ( "YES\n" ); 
else 
printf ( "NO\n" ); 
return  0 ; 
} 
