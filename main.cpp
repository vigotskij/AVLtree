#ifndef ICONTAINER_H
	#include "tree.h"
#endif
#include <iostream>
#include <stdlib>

int main ( int argv , char *argc[] ) {
	IContainer<int> *cont = factoryContainer<int>() ;

	cont->append( 5 ) ;
	cont->append( 102 ) ;
	cont->append( 3 ) ;
	cont->append( 712 ) ;
	cont->append( -113 ) ;

	std::cout << cont->search( 102 ) << std::endl ;
	std::cout << cont->remove( 102 ) << std::endl ;
	std::cout << cont->search( 102 ) << std::endl ;

	cont->append( 17 ) ;

	cont->clear() ;

    system( "pause" ) ;


    return 43 ;
}
