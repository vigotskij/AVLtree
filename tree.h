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
		Size itemCount ;

		// helpers
		Node* emptyNodeFor( ItemType value ){
			Node *tr = nullptr ;
			if ( root != nullptr ){
				Node *current = root ;
				for ( ; current != nullptr ; ) {
					if ( current->value < value && current->right == nullptr ){
						tr = current ;
					} else if( current->value && current->left == nullptr ){
						tr = current ;
					}
					if ( current->value < value ){
						current = current->right ;
					} else if ( current->value > value ){
						current = current->left ;
					}
				}
			}
			return tr ;
		}

		// copyconstructor and operator=
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
	itemCount = 0 ;
}
template<class ItemType>
Tree<ItemType>::~Tree( void ){
	clear() ;
	if( root ) delete root ;
}
// adding and removing functions
template<class ItemType>
void Tree<ItemType>::append( ItemType value ){
	if( root == nullptr ){
		root->value = value ;
		root->left = nullptr ;
		root->right = nullptr ;
		root->root = nullptr ;

		itemCount++ ;
	} else {
		Node *current = emptyNodeFor( value ) ;
		if( current->value < value ){
			right = current->right ;

			right->value = value ;
			right->right = nullptr ;
			right->left = nullptr ;

			itemCount++ ;
		} else if( current->value > value ) {
			left = current->left ;

			left->value = value ;
			left->right = nullptr ;
			left->left = nullptr ;

			itemCount++ ;
		}
	}
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
bool Tree<ItemType>::isEmpty( void ){
	return root == nullptr ;
}
// clean everything
template<class ItemType>
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
