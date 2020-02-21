#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>
#include <iterator>
#include "List.h"
#include "Collection.h"
#include "Iterator.h"

namespace CollectionInterface
{

	template <typename E, template <typename... arg> class Container>
	class ArrayList : public List<E, Container>
	{
	public:
		typedef typename Container<E>::size_type size_type;
		//no parameter constructor
		ArrayList();
		//copy contructor
		ArrayList<E, Container>& operator=(const ArrayList<E, Container>& obj);
		//destructor
		~ArrayList();
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
	};//ArrayList ends

}//CollectionInterface ends	

#endif