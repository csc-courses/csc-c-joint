
/* header file for complex numbers
 * author:
 * last-update:
 *    26 jul 2023
 */
 

struct Complex {
	float real ;
	float imag ; 
} ;
 
void cmplx_printf(struct Complex * c ) ;
struct Complex * cmplx_copy(struct Complex * dst, struct Complex * src) ;
struct Complex * cmplx_add( struct Complex * sum, struct Complex * add ) ;
struct Complex * cmplx_mult( struct Complex * prod, struct Complex * mul ) ;


