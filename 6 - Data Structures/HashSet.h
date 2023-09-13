#ifndef HASHSET_H
#define HASHSET_H
#include <iostream>
#include <iterator>
#include "Set.h"
#include "Collection.h"
#include "Iterator.h"


namespace CollectionInterface
{
	template <typename E, template <typename... arg> class Container>
	class HashSet : public Set<E, Container>
	{	
	public:

		typedef typename Container<E>::size_type size_type;
		//no parameter constructor
		HashSet();
		//assignment operator overloading
		HashSet<E, Container>& operator=(const HashSet<E, Container>& obj);
		//destructor
		~HashSet();
		//getter
		
		Container<E>& Iterator();
		void add(E elem);
		void addAll(Collection<E, Container>& collect);
		void clear();
		bool contains(E elem);
		bool containsAll(Collection<E, Container>& collect);
		bool isEmpty();
		void remove(E elem);
		void removeAll(Collection<E, Container>& collect);
		void retainAll(Collection<E, Container>& collect);
	    size_type size();
	    Container<E>& getContained();

	private:
		Container<E> contained;	

	};//HashSet ends

}//CollectionInterface ends	

#endif