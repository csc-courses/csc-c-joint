
#include<stdio.h>
#include<string.h>

#define N 8 


void print_aux(char * a, int n) {
    int i ;
    for (i=0;i<n;i++) 
        printf("%c", (a[i])?'1':'0' ) ;
    return ; 
}

void print_results(char * a, char * b, char *c, char carry, int n) {
    int i ;
    printf("A: ") ;
    print_aux(a,n) ;
    printf("\nB: ") ;
    print_aux(b,n) ;
    printf("\nC: ") ;
    print_aux(c,n) ;
    printf("\n%scarry out\n\n", (!carry)?"no ":"") ;
    return ;
}


// ------------------------


char full_adder(char a, char b, char c_in, char * c_out) {
    *c_out = (a & b)|(b&c_in)|(a&c_in) ;
    return a ^ b ^ c_in ;
}

int main(int argc, char * argv[]) {
    char r_A[N], r_B[N], acc[N] ;
    char cy_flag, carry ;
    int i ;
    for (i=0;i<N;i++) {
        r_A[i] = (argv[1][i]=='1') ;
        r_B[i] = (argv[2][i]=='1') ;
        acc[i] = 0 ;
    }
    cy_flag = 0 ; 
    
    for (i=(N-1);i>=0;i--) {
        acc[i] = full_adder(r_A[i],r_B[i],cy_flag,&carry) ;
        cy_flag = carry ;
    }
    
    print_results(r_A, r_B, acc, cy_flag, N) ;
    return 0 ;
}
