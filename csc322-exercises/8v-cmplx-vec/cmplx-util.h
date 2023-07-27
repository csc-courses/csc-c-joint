
/* header file for complex vectors
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

void cmplx_printf_v(struct Complex * c, int dim );
struct Complex * cmplx_copy_v(struct Complex * dst, struct Complex * src, int dim );
struct Complex cmplx_inner( struct Complex * v1, struct Complex * v2, int dim ) ;


