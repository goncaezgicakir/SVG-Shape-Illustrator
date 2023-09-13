#include "Iterator.h"

namespace CollectionInterface
{

	//no parameter constructor
	template <typename E, template <typename... arg> class Container>
	Iterator<E, Container>::Iterator()
	{
		it = nullptr;
	}

	//no parameter constructor
	template <typename E, template <typename... arg> class Container>
	Iterator<E, Container>::Iterator(const Container<E> obj)
	{
		it = obj;
	}


	//destructor
	template <typename E, template <typename... arg> class Container>
	Iterator<E, Container>::~Iterator()
	{

	}

	template <typename E, template <typename... arg> class Container>
	bool Iterator<E, Container>::hasNext()
	{
		if(it.end() == 1)
			return 0;
		else
			return 1;
	}

	template <typename E, template <typename... arg> class Container>
	Container<E> Iterator<E, Container>::next()
	{
		return *(++it);

	}

	template <typename E, template <typename... arg> class Container>
	void Iterator<E, Container>::remove()
	{

	}


}//CollectionInterface ends	



		

			
		