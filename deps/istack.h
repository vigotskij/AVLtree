#ifndef ISTACK_H
#define ISTACK_H
// typedef unsigned long Size ;

template <class ItemType>
class IStack {
	public:
		virtual void push( ItemType value ) = 0 ;
		virtual ItemType pop( void ) = 0 ;
		virtual ItemType peek( void ) = 0 ;
		virtual bool isEmpty( void ) = 0 ;
		virtual Size stackSize( void ) = 0 ;
};

#endif // ISTACK_H
