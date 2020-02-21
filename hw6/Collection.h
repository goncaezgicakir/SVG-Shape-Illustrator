#ifndef COLLECTION_H
#define COLLECTION_H
#include "Iterator.h"

namespace CollectionInterface
{	
	template <typename E, template <typename... arg> class Container>
	class Collection
	{	
	public:
		
		typedef typename Container<E>::size_type size_type;
		
		virtual Container<E>& Iterator() = 0;
		virtual void add(E elem) = 0;
		virtual void addAll(Collection<E, Container>& collect) = 0;
		virtual void clear() = 0;
		virtual bool contains(E elem) = 0;
		virtual bool containsAll(Collection<E, Container>& collect) = 0;
		virtual bool isEmpty() = 0;
		virtual void remove(E elem) = 0;
		virtual void removeAll(Collection<E, Container>& collect) = 0;
		virtual void retainAll(Collection<E, Container>& collect) = 0;
		virtual size_type size() = 0;
		virtual Container<E>& getContained() = 0;


	};//Collection ends

}//CollectionInterface ends

#endif