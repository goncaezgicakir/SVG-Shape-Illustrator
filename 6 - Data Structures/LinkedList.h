#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <iterator>
#include <iostream>
#include <stdexcept>
#include <exception>
#include "List.h"
#include "Queue.h"
#include "Collection.h"
#include "Iterator.h"


namespace CollectionInterface
{

	template <typename E, template <typename... arg> class Container>
	class LinkedList : public Queue <E, Container>, public List <E, Container>
	{
	public:
		typedef typename Container<E>::size_type size_type;
		//no parameter constructor
		LinkedList();
		//assignment operator overloading
		LinkedList<E, Container>& operator=(const LinkedList<E, Container>& obj);
		//destructor
		~LinkedList();
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
	    typename Container<E>::iterator element() throw(std::exception);
		bool offer(E elem);
		typename Container<E>::iterator poll();

	    Container<E>& getContained();

	private:
		Container<E> contained;	

	};//LinkledList ends

}//CollectionInterface ends	

#endif