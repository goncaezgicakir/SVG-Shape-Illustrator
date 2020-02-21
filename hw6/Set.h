#ifndef SET_H
#define SET_H
#include <iostream>
#include "Collection.h"
#include "Iterator.h"



namespace CollectionInterface
{

	template <typename E, template <typename... arg> class Container>
	class Set : public Collection <E, Container>
	{
	public:
		//no parameter constructor
		Set(){};
	
	};//Set ends

}//CollectionInterface ends	

#endif