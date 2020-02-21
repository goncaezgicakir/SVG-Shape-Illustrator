#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Collection.h"
#include "Iterator.h"


namespace CollectionInterface
{

	template <typename E, template <typename... arg> class Container>
	class Queue : virtual public Collection <E, Container>
	{
	public:

		//no parameter constructor
		Queue(){};
		//destructor
		~Queue(){};

		virtual typename Container<E>::iterator element() = 0;
		virtual bool offer(E elem) = 0;
		virtual typename Container<E>::iterator poll() = 0;

	};//Queue ends

}//CollectionInterface ends	

#endif