
#include<stdio.h>

// Many hands make light work. 
// TWFueSBoYW5kcyBtYWtlIGxpZ2h0IHdvcmsu

char map_to_64(char c) {
    if (c==63) return '/' ;
    if (c==62) return '+' ;
    if (c>=52) return (c-52+'0') ;
    if (c>=26) return (c-26)+'a' ;
    return c+'A' ;
}

void print_base_64(char * s) {
    int r = 0 ;
    char b ;
    char b_n ;
    int i = 0 ;
    while(*s) {
        switch (r) {
            case 0:
                b = (*s>>2)&0x3f ;
                b_n = (*s<<4)&0x3f ;
                break ;
            case 1:
                b = ((*s>>4)|b_n)&0x3f ;
                b_n = (*s<<2)&0x3f ;
                break ;
            case 2: 
                b = ((*s>>6)|b_n)&0x3f ;
                b_n = *s ;
                break ;
            case 3:
                b = b_n&0x3f;
        }
        if (r!=3) s++ ;
        r = (r+1)%4 ;
        printf("%c", map_to_64(b)) ;
        i++ ;
    }
    if (r) {
        printf("%c", map_to_64(b_n&0x3f)) ;
        i++ ;
    }
    while (i%4) {
        printf("=") ;
        i++ ;
    }
    
    return ;
}

int main(int argc, char * argv[]) {
    char * to_convert = argv[1] ;
    printf("input: %s\noutput: ", to_convert) ;
    print_base_64(to_convert) ;
    printf("\n") ;
    
    return 0 ;
}
