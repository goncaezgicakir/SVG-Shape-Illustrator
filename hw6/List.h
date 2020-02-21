#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Collection.h"
#include "Iterator.h"


namespace CollectionInterface
{

	template <typename E, template <typename... arg> class Container>
	class List : virtual public Collection <E, Container>
	{
	public:

		//no parameter constructor
		List(){};
		//destructor
		~List(){};
	
	};//Set ends

}//CollectionInterface ends	

#endif