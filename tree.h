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
						break ;
					} else if( current->value > value && current->left == nullptr ){
						tr = current ;
						break ;
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
		Node* nodeContaining( ItemType value ){
			Node *tr = nullptr ;
			if( root != nullptr ){
				Node *current = root ;
				for( ; current != nullptr && current->value != value ; ){
					if( current->value < value ) current = current->right ;
					if( current->value > value ) current = current->left ;
				}
				if( current != nullptr ) tr = current ;
			}
			return tr ;
		}
		void clearFrom( Node *node ){
			if( node->left != nullptr ) cleanFrom( node->left ) ;
			if( node->right != nullptr ) cleanFrom( node->right ) ;
			if( node->root == nullptr ) delete node ;
			if( node->root != nullptr ) {
				if( node->root->value < node->value ){
					node->root->right = nullptr ;
					delete node ;
				} else if( node->root->value > node->value ){
					node->root->left = nullptr ;
					delete node ;
				}
			}
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
	helper = factoryStack<ItemType>() ;
	itemCount = 0 ;
}
template<class ItemType>
Tree<ItemType>::~Tree( void ){
	clear() ;
	for( ; !helper->isEmpty() ; helper->pop() );
	// if( helper ) delete helper ;
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
			right->root = current ;

			itemCount++ ;
		} else if( current->value > value ) {
			left = current->left ;

			left->value = value ;
			left->right = nullptr ;
			left->left = nullptr ;
			left->root = current ;

			itemCount++ ;
		}
	}
}

template<class ItemType>
ItemType Tree<ItemType>::remove( ItemType value ){
	ItemType tr = NULL ;
	if( search( value ) ){
		Node *toRemove = nodeContaining( value ) ;
		if( toRemove != root ) {
			if( toRemove->left != nullptr && toRemove->right != nullptr ){
				Node *father = toRemove->root ;
				Node *left = toRemove->left ;
				Node *right = toRemove->right ;

				if( right->value > father->value){
					father->right = right ;
					Node *temp = emptyNodeFor( left->value ) ;
					temp->left = left ;
					left->root = temp ;
				} else if( left->value < father->value ){
					father->left = left ;
					Node *temp = emptyNodeFor( right->value ) ;
					temp->right = right ;
                    right->root = temp ;
				}

			} else if( toRemove->left != nullptr && toRemove->right == nullptr ){
				Node *father = toRemove->root ;
				father->left = toRemove->left ;
				toRemove->left->root = father ;
			} else if( toRemove->right != nullptr && toRemove->left == nullptr ){
				Node *father = toRemove->root ;
				father->right = toRemove->right ;
				toRemove->right->root = father ;
			} else if( toRemove->left == nullptr && toRemove->right == nullptr ){
				;
			}
		} else if( toRemove == root ){
			if( toRemove->left != nullptr && toRemove->right != nullptr ){
				root = toRemove->right ;
				root->root = nullptr ;
				Node *temp = emptyNodeFor( toRemove->left ) ;
				temp->left = left ;
				left->root = temp ;
			} else if( toRemove->left != nullptr && toRemove->right == nullptr ){
				Node *oldRoot = root ;
				root = oldRoot->left ;
				root->root = nullptr ;
			} else if( toRemove->left == nullptr && toRemove->right != nullptr ){
				Node *oldRoot = root ;
				root = oldRoot->right ;
				root->root = nullptr ;
			} else if( toRemove->left == nullptr && toRemove->right == nullptr ){
				root = nullptr ;
			}
		}
		tr = toRemove->value ;
		delete toRemove ;
		itemCount-- ;
	}
	return tr ;
}
// info functions
template<class ItemType>
bool Tree<ItemType>::search( ItemType value ){
	bool tr = false ;
	if( root != nullptr ){
		Node *current = root ;
		for( ; current != nullptr && current->value != value ; ){
			if( current->value < value ) current = current->right ;
			if( current->value > value ) current = current->left ;
		}
		if ( current != nullptr ) tr = ( current->value == value ) ;
	}
    return tr ;
}
template<class ItemType>
Size Tree<ItemType>::size( void ){
	return itemCount ;
}
template<class ItemType>
bool Tree<ItemType>::isEmpty( void ){
	return root == nullptr ;
}
// clean everything
template<class ItemType>
void Tree<ItemType>::clear( void ){
    clearFrom( root ) ;
}


//
// factory
//
template<class ItemType>
IContainer<ItemType>* factoryContainer( void ){
	return new Tree<ItemType> ;
}

#endif // TREE_H
