
#include<stdio.h>
int main(int argc, char * argv[]) {
    short s[2] ;
    int i[2] ;
    long l[2] ;
    
    printf("s[0] @ %lu\ns[1] @ %lu\n", (unsigned long) &s[0], (unsigned long) &s[1] ) ;
    printf("i[0] @ %lu\ni[1] @ %lu\n", (unsigned long) &i[0], (unsigned long) &i[1] ) ;
    printf("l[0] @ %lu\nl[1] @ %lu\n", (unsigned long) &l[0], (unsigned long) &l[1] ) ;

    return 0 ;
}
