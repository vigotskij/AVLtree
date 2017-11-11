#ifndef ISTACK_H
	#include "istack.h"
#endif

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#define nullptr 0
#define NULL 0

template <class ItemType>
class DStack: public IStack<ItemType> {
	private:
		struct Node {
			ItemType value ;
			Node *next ;

			Node( void ) {
				value = NULL ;
				next = nullptr ;
			}
			virtual ~Node( void ) {}

			private:
			Node ( const Node &node ) ;
			Node& operator= (const Node &node ) ;
		};

		Node *top ;

		Size usedSpaces ;

		// copy constructor ;
		DStack(const DStack &stack ) ;
		// operator=
		DStack& operator=( const DStack& otherStack );

		//helpers
	public:
		DStack( void ) ;
		virtual ~DStack( void ) ;

		// métodos heredados de la interfaz
		virtual void push( ItemType value ) ;
		virtual ItemType pop( void ) ;
		virtual ItemType peek( void ) ;
		virtual bool isEmpty( void ) ;
		virtual Size stackSize( void ) ;
};

//
// PRIVATE
//

//
// PUBLIC
//
template <class ItemType>
DStack<ItemType>::DStack( void ) {
	top = nullptr ;
	usedSpaces = 0 ;
}
template <class ItemType>
DStack<ItemType>::~DStack( void ) {
	while ( top != nullptr ) {
		usedSpaces-- ;
		Node *oldTop = top ;
		top = oldTop->next ;

		delete oldTop ;
	}
	if( top ) delete top ;
}

template <class ItemType>
void DStack<ItemType>::push( ItemType value ) {
	Node *newNode ;
	newNode = new Node() ;

	newNode->value = value ;

	Node *oldTop ;
	oldTop = top ;
	top = newNode ;
	top->next = oldTop ;

	usedSpaces++ ;
}
template <class ItemType>
ItemType DStack<ItemType>::pop( void ) {
	ItemType toReturn = NULL ;

	if( top != nullptr ) {
		usedSpaces-- ;

		Node *oldTop = top ;
		top = oldTop->next ;

		toReturn = oldTop->value ;

		delete oldTop ;
	}

	return toReturn ;
}
template <class ItemType>
ItemType DStack<ItemType>::peek( void ) {
	return top->value ;
}

template <class ItemType>
bool DStack<ItemType>::isEmpty( void ) {
	return ( usedSpaces == 0 ) ;
}
template <class ItemType>
Size DStack<ItemType>::stackSize( void ) {
	return usedSpaces ;
}

//
// FACTORY
//
template <class ItemType>
IStack<ItemType>* factoryStack( void ) {
	return new DStack<ItemType> ;
}
#endif // STACK_H
