#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>

namespace CollectionInterface
{

	template <typename E, template <typename... arg> class Container>
	class Iterator
	{
				
	public:
		//no parameter constructor
		Iterator();
		//constructor
		Iterator(const Container<E> obj);
		//destructor
		~Iterator();

		bool hasNext();
		Container<E> next();
		void remove();

	private:
		Container<E> it;	
 
	};//Iterator ends*/

}//CollectionIterface ends		

#endif			