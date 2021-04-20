#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include "lib.h"
auto swap ( void* a , void* b ) {
 auto t = a ;
 a = b ;
 b = t ;
 }
 auto partition ( void* array , void* low , void* high ) {
 auto pivot = & array [ (int) high ] ;
 auto i = ( low - 1 ) ;
 auto j = low ;
 while0: if(!( j <= high - 1 )) goto end0;
 if (!( & array [ (int) j ] < pivot )) goto else1;
 i ++ ;
 swap ( & array [ (int) i ] , & array [ (int) j ] ) ;
 else1: {
 }
 j ++ ;
 goto while0 ;
 end0:
 swap ( & array [ (int) i + 1 ] , & array [ (int) high ] ) ;
 return ( i + 1 ) ;
 }
 auto quickSort ( void* array , void* low , void* high ) {
 if (!( low < high )) goto else2;
 auto pi = partition ( array , low , high ) ;
 quickSort ( array , low , pi - 1 ) ;
 quickSort ( array , pi + 1 , high ) ;
 else2: {
 }
 }
 auto main ( ) {
 auto array = { 1 , 5 , 2 , 3 , 4 } ;
 auto size = 5 ;
 quickSort ( array , 0 , size - 1 ) ;
 printf ( array ) ;
 return ( 0 ) ;
 }
 