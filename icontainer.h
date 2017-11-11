#ifndef ICONTAINER_H
#define ICONTAINER_H

typedef unsigned int Size ;

template <class ItemType>
class IContainer{
	public:
		// adding and removing items
		void append( ItemType value ) = 0 ;
		ItemType remove( ItemType value ) = 0 ;
		// info functions
		bool search( ItemType value ) = 0 ;
		Size size( void ) = 0 ;
		bool isEmpty( void ) = 0 ;
		// clear everything
		void clear( void ) = 0 ;
};

#endif // ICONTAINER_H
