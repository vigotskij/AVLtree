#ifndef ICONTAINER_H
	#include "tree.h"
#endif

int main ( int argv , char *argc[] ) {
	IContainer<int> *cont = factoryContainer<int>() ;

	cont->append( 5 ) ;
	cont->append( 102 ) ;
	cont->append( 3 ) ;
	cont->append( 712 ) ;
    cont->append( -113 ) ;

    return 43 ;
}
