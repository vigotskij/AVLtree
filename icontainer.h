#ifndef ICONTAINER_H
#define ICONTAINER_H

typedef unsigned int Size ;

template <class ItemType>
class IContainer{
	public:
		// adding and removing items
		virtual void append( ItemType value ) = 0 ;
		virtual ItemType remove( ItemType value ) = 0 ;
		// info functions
		virtual bool search( ItemType value ) = 0 ;
		virtual Size size( void ) = 0 ;
		virtual bool isEmpty( void ) = 0 ;
		// clear everything
		virtual void clear( void ) = 0 ;
};

#endif // ICONTAINER_H
