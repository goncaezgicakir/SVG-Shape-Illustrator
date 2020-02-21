#include <iostream>
#include <iterator>
#include <set>
#include "HashSet.h"
using namespace std;

namespace CollectionInterface
{

	//no parameter constructor
	template <typename E, template <typename... arg> class Container>
	HashSet<E, Container>::HashSet()
	{
		
	}

	
	//assignment operator overloading
	template <typename E, template <typename... arg> class Container>
	HashSet<E, Container>& HashSet<E, Container>::operator=(const HashSet<E, Container>& obj)
	{
		if(this == &obj)
		{
			return *this;
		}

		else
		{
			int capacity = contained.size();
			int size = obj.size();

			typename Container<E>::iterator it1;
			typename Container<E>::iterator it2;
			it2 = obj.begin(); 
			it1 = contained.begin();

			for(int i=0 ; i<size ; ++i)
			{
				if(size<capacity)
					*(it1+i) = *(it2+i);
				else
					*(it1+i) = 0;
			}

		}	

		return *this;	
	}

	//destructor
	template <typename E, template <typename... arg> class Container>
	HashSet<E, Container>::~HashSet()
	{
	}
		

	//getter
	template <typename E, template <typename... arg> class Container>
	Container<E>& HashSet<E, Container>::getContained()
	{
		return contained;
	}

	template <typename E, template <typename... arg> class Container>
	Container<E>& HashSet<E, Container>::Iterator() 
	{
		
	}

	template <typename E, template <typename... arg> class Container>
	void HashSet<E, Container>::add(E elem)
	{
		//cout<<"add func."<<endl;

		typename Container<E>::iterator it;
		int f_add = 0;

		for(it=contained.begin() ; it!=contained.end() ; ++it)
		{
			if(*it == elem)	
			{	
				f_add = 1;
				break;
			}
		}

		if(f_add == 0)
		{
			it = contained.end();
			contained.insert(it, elem);
		}	

	}

	template <typename E, template <typename... arg> class Container>
	void HashSet<E, Container>::addAll(Collection<E, Container>& collect)
	{
		//cout<<"addAll func."<<endl;

		typename Container<E>::iterator it1;
		typename Container<E>::iterator it2;
		int f_add;

		for(it1=contained.begin() ; it1!=contained.end() ; ++it1)
		{
			for(it2=collect.getContained().begin() ; it2!=collect.getContained().end() ; ++it2)
			{
				if(*it1!= *it2)
				{	
					f_add = 1;
					break;
				}	
				else
					f_add = 0;
			}
			
			if(f_add = 1)	
				it2 = contained.end();

		}

	}
		
	template <typename E, template <typename... arg> class Container>
	void HashSet<E, Container>::clear()
	{
		//cout<<"clear func."<<endl;

		contained.clear();
			
	}
	template <typename E, template <typename... arg> class Container>
	bool HashSet<E, Container>::contains(E elem)
	{
		//cout<<"contains func."<<endl;

		typename Container<E>::iterator it;

		for(it=contained.begin() ; it!=contained.end() ; ++it)
		{
			
			if(*it == elem)
			{	
				return true;
			}
		}	
		return false;
	}

	template <typename E, template <typename... arg> class Container>
	bool HashSet<E, Container>::containsAll(Collection<E, Container>& collect)
	{	
		//cout<<"containsAll func."<<endl;

		typename Container<E>::iterator it1;
		typename Container<E>::iterator it2;
		int f_cont = 0;

		for(it1=contained.begin() ; it1!=contained.end() ; ++it1)
		{
			for(it2=collect.getContained().begin() ; it2!=collect.getContained().end() ; ++it2)
			{
				if(*it1 == *it2)
					f_cont++;	
			}
		}	


			if(f_cont == collect.getContained().size())
				return 1;
			else
				return 0;
		
	}

	template <typename E, template <typename... arg> class Container>
	bool HashSet<E, Container>::isEmpty()
	{
		//cout<<"isEmpty func."<<endl;

		if(contained.size() == 0)
			return 1;
		else
			return 0;
	}

	template <typename E, template <typename... arg> class Container>
	void HashSet<E, Container>::remove(E elem)
	{
		//cout<<"remove func."<<endl;

		typename Container<E>::iterator it;
		it=contained.begin() ;
		while( it!=contained.end()  )
		{
			if(*it == elem)
			{	

				contained.erase(it++);
				break;
			}
			else
			{
				 ++it;
			}
			
		}	

	}

	template <typename E, template <typename... arg> class Container>
	void HashSet<E, Container>::removeAll(Collection<E, Container>& collect)
	{
		//cout<<"removeAll func."<<endl;

		typename Container<E>::iterator it;

		for(it=collect.getContained().begin() ; it!=collect.getContained().end() ; ++it)
		{
			if(contains(*it) == true)
			{
				
				remove(*it);
				
			}
				
		}


	}

	template <typename E, template <typename... arg> class Container>
	void HashSet<E, Container>::retainAll(Collection<E, Container>& collect)
	{
		//cout<<"retainAll func."<<endl;

		typename Container<E>::iterator it1;
		typename Container<E>::iterator it2;
		int f_remv;

		for(it1=contained.begin() ; it1!=contained.end() ; ++it1)
		{
			for(it2=collect.getContained().begin() ; it2!=collect.getContained().end() ; ++it2)
			{
				if(*it1 == *it2)
				{	
					f_remv = 1;
					break;
				}	
				else
					f_remv = 0;
			}
			if(f_remv == 0)
				remove(*it1);

			f_remv = 0;
		}

	}

	template <typename E, template <typename... arg> class Container>
	typename Container<E>::size_type HashSet<E, Container>::size()
	{		
		//cout<<"size func."<<endl;

		return contained.size();
	}

}//CollectionInterface ends

