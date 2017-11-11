#ifndef TREE_H
#define TREE_H

#ifndef ICONTAINER_H
	#include "icontainer.h"
#endif

#define NULL 0
#define nullptr 0

template <class ItemType>
class Tree: public IContainer<ItemType> {
	private:
		struct Node{
			ItemType value ;
			Node *root, *left, *right ;

			Node( void ){
				root = nullptr ;
				left = nullptr ;
				right = nullptr ;
			}
			virtual ~Node(void){
			}
			private:
			Node( const Node &otherNode ) ;
			Node& operator=( const Node &otherNode ) ;
		};

		Node *root ;

		Tree( const Tree &otherTree ) ;
		Tree operator= ( const Tree &otherTree ) ;
	public:
		// constructor and destructor
		Tree( void ) ;
		virtual ~Tree( void ) ;
		// adding and removing items
		virtual void append( ItemType value ) ;
		virtual ItemType remove( ItemType value ) ;
		// info functions
		virtual bool search( ItemType value ) ;
		virtual Size size( void ) ;
		virtual bool isEmpty( void ) ;
		// clear everything
		virtual void clear( void ) ;
};

//
// PRIVATE
//

//
//  PUBLIC
//
// constructor and destructor
template<class ItemType>
Tree<ItemType>::Tree( void ){
	root = nullptr ;
}
template<class ItemType>
Tree<ItemType>::~Tree( void ){
	clear() ;
	if( root ) delete root ;
}
// adding and removing functions
template<class ItemType>
void Tree<ItemType>::append( ItemType value ){
	;
}
template<class ItemType>
ItemType Tree<ItemType>::remove( ItemType value ){
	;
}
// info functions
template<class ItemType>
bool Tree<ItemType>::search( ItemType value ){
	;
}
template<class ItemType>
Size Tree<ItemType>::size( void ){
	;
}
template<class ItemType>
bool Tree<Itemtype>::isEmpty( void ){
	return root == nullptr ;
}
// clean everything
void Tree<ItemType>::clear( void ){
}


//
// factory
//
template<class ItemType>
IContainer<ItemType>* factoryContainer( void ){
	return new Tree<ItemType> ;
}

#endif // TREE_H
