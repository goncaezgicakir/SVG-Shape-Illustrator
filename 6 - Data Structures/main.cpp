#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <exception>

#include "Set.h"
#include "Queue.h"
#include "List.h"
#include "Collection.h"
#include "Iterator.h"

#include "LinkedList.h"
#include "LinkedList.cpp"

#include "HashSet.h"
#include "HashSet.cpp"

#include "ArrayList.h"
#include "ArrayList.cpp"

using std::cout;
using std::ostream;
using std::endl;
using namespace CollectionInterface;



int main()
{
    HashSet <int,std::vector> obj1;

    {
        cout << "\n-------HASHSET - VECTOR-----------: \n";

        HashSet<int, std::vector > obj;
        HashSet<int, std::vector > obj2;

        //Add and Remove
        obj.add(1);
        obj.add(2);
        obj.add(3);
        obj.add(4);
        obj.add(5);
        obj2.add(4);
        obj2.add(5);
        cout << "Result of ContainsAll : " << obj.containsAll(obj2)<<endl;

        obj.remove(1);
        obj.remove(2);
        obj.remove(3);

        //Remove All
        obj.removeAll(obj2);
        cout << "Size after calling RemoveAll: "<<obj.size()<<endl;


        HashSet<int, std::vector > obj5;
        HashSet<int, std::vector > obj6;
        obj5.add(1);
        obj5.add(2);
        obj5.add(3);
        obj5.add(4);
        obj5.add(5);
        obj6.add(4);
        obj6.add(5);
        

        obj5.retainAll(obj6);
        cout << "Size after calling Retain All: "<<obj5.size()<<endl;

        obj5.clear();
        cout << "Size after calling Clear: "<<obj5.size()<<endl;

        cout << "Resul of isEmpty: "<<obj5.isEmpty()<<endl;
        obj5.add(1);
        cout << "Result of Contains: " << obj5.contains(1)<<endl;
    }

    {
        cout << "\n-------HASHSET - SET-----------: \n\n";
  
        HashSet<int, std::set > obj;
        HashSet<int, std::set > obj2;

        //Add and Remove
        obj.add(1);
        obj.add(2);
        obj.add(3);
        obj.add(4);
        obj.add(5);
        obj2.add(4);
        obj2.add(5);
        cout << "Result of ContainsAll: " << obj.containsAll(obj2)<<endl;
       
        obj.remove(1);
        obj.remove(2);
        obj.remove(3);

        //Remove All
        obj.removeAll(obj2);
        cout << "Size after calling RemoveAll: "<<obj.size()<<endl;

        
        HashSet<int, std::set > obj4;
        obj4.add(1);
        obj4.add(2);
        obj4.add(3);
        obj4.add(4);
        obj4.add(5);

        HashSet<int, std::set > obj5;
        HashSet<int, std::set > obj6;

        //Retain All
        obj5.add(1);
        obj5.add(2);
        obj5.add(3);
        obj5.add(4);
        obj5.add(5);
        obj6.add(4);
        obj6.add(5);

        //Remove All

        obj5.retainAll(obj6);

        cout << "Size after calling Retain All: "<<obj5.size()<<endl;
        obj5.clear();
        cout << "Size after calling Clear: "<<obj5.size()<<endl;
        cout << "Result of isEmpty: "<<obj5.isEmpty()<<endl;
        obj5.add(1);
        cout << "Result of Contains: " << obj5.contains(1)<<endl;
    }

    {
        cout << "\n-------HASHSET - LIST-----------: \n\n";
        
        HashSet<int, std::list > obj;
        HashSet<int, std::list > obj2;

        //Add and Remove
        obj.add(1);
        obj.add(2);
        obj.add(3);
        obj.add(4);
        obj.add(5);
        obj2.add(4);
        obj2.add(5);
        cout << "Size after calling ContainsAll: " << obj.containsAll(obj2)<<endl;
        
        obj.remove(1);
        obj.remove(2);
        obj.remove(3);

        //Remove All
        obj.removeAll(obj2);
        cout << "Size after calling RemoveAll: "<<obj.size()<<endl;

        
        HashSet<int, std::list > obj4;
        obj4.add(1);
        obj4.add(2);
        obj4.add(3);
        obj4.add(4);
        obj4.add(5);
        

        HashSet<int, std::list > obj5;
        HashSet<int, std::list > obj6;

        //Retain All
        obj5.add(1);
        obj5.add(2);
        obj5.add(3);
        obj5.add(4);
        obj5.add(5);
        obj6.add(4);
        obj6.add(5);
        //Remove All
        
        obj5.clear();
        cout << "Size after calling Clear: "<<obj5.size()<<endl;
        cout << "Result of isEmpty: "<<obj5.isEmpty()<<endl;
        obj5.add(1);
        cout << "Result of Contains: " << obj5.contains(1)<<endl;
    }

    {
        cout << "\n-------ARRAY - VECTOR-----------: \n\n";
     
        ArrayList<int, std::vector > obj;
        ArrayList<int, std::vector > obj2;

        //Add and Remove
        obj.add(1);
        obj.add(2);
        obj.add(3);
        obj.add(4);
        obj.add(5);
        obj2.add(4);
        obj2.add(5);
        cout << "Result of ContainsAll: " << obj.containsAll(obj2)<<endl;
        
        obj.remove(1);
        obj.remove(2);
        obj.remove(3);

        //Remove All
        obj.removeAll(obj2);
        cout << "Size after calling RemoveAll: "<<obj.size()<<endl;

        ArrayList<int, std::vector > obj4;
        obj4.add(1);
        obj4.add(2);
        obj4.add(3);
        obj4.add(4);
        obj4.add(5);

        ArrayList<int, std::vector > obj5;
        ArrayList<int, std::vector > obj6;

        //Retain All
        obj5.add(1);
        obj5.add(2);
        obj5.add(3);
        obj5.add(4);
        obj5.add(5);
        obj6.add(4);
        obj6.add(5);
        //Remove All
        
        obj5.clear();
        cout << "Size after calling Clear: "<<obj5.size()<<endl;

        cout << "Result of isEmpty: "<<obj5.isEmpty()<<endl;
        obj5.add(1);
        cout << "Result of Contains: " << obj5.contains(1)<<endl;
    }
    {
        cout << "\n-------ARRAY - SET-----------: \n\n";

        ArrayList<int, std::set > obj;
        ArrayList<int, std::set > obj2;

        //Add and Remove
        obj.add(1);
        obj.add(2);
        obj.add(3);
        obj.add(4);
        obj.add(5);
        obj2.add(4);
        obj2.add(5);
        cout << "Result of ContainsAll: " << obj.containsAll(obj2)<<endl;
        
        obj.remove(1);
        obj.remove(2);
        obj.remove(3);

        //Remove All
        obj.removeAll(obj2);
        cout << "Size after calling RemoveAll: "<<obj.size()<<endl;

        ArrayList<int, std::set > obj4;
        obj4.add(1);
        obj4.add(2);
        obj4.add(3);
        obj4.add(4);
        obj4.add(5);

        ArrayList<int, std::set > obj5;
        ArrayList<int, std::set > obj6;

        //Retain All
        obj5.add(1);
        obj5.add(2);
        obj5.add(3);
        obj5.add(4);
        obj5.add(5);
        obj6.add(4);
        obj6.add(5);
        //Remove All

        obj5.retainAll(obj6);
        cout << "Size after calling Retain All: "<<obj5.size()<<endl;
        obj5.clear();
        cout << "Size after calling Clear: "<<obj5.size()<<endl;
        cout << "Result of isEmpty: "<<obj5.isEmpty()<<endl;
        obj5.add(1);
        cout << "Result of Contains: " << obj5.contains(1)<<endl;
    }
   {
        cout << "\n-------ARRAY - LIST-----------: \n\n";
        
        ArrayList<int, std::list > obj;
        ArrayList<int, std::list> obj2;
        //Add and Remove
        obj.add(1);
        obj.add(2);
        obj.add(3);
        obj.add(4);
        obj.add(5);
        obj2.add(4);
        obj2.add(5);
        cout << "Result of ContainsAll: " << obj.containsAll(obj2)<<endl;
        
        obj.remove(1);
        obj.remove(2);
        obj.remove(3);

        
        ArrayList<int, std::list > obj4;
        obj4.add(1);
        obj4.add(2);
        obj4.add(3);
        obj4.add(4);
        obj4.add(5);
       
        ArrayList<int, std::list > obj5;
        ArrayList<int, std::list > obj6;

        //Retain All
        obj5.add(1);
        obj5.add(2);
        obj5.add(3);
        obj5.add(4);
        obj5.add(5);
        obj6.add(4);
        obj6.add(5);
        //Remove All
        
        obj5.clear();
        cout << "Size after calling Clear: "<<obj5.size()<<endl;
        cout << "Result of isEmpty: "<<obj5.isEmpty()<<endl;
        obj5.add(1);
        cout << "Result of Contains: " << obj5.contains(1)<<endl;
    }

    {
        cout << "\n-------LINKEDLIST - VECTOR-----------: \n\n";
        
        LinkedList<int, std::vector > obj;
        LinkedList<int, std::vector> obj2;

        //Add and Remove
        obj.add(1);
        obj.add(2);
        obj.add(3);
        obj.add(4);
        obj.add(5);
        obj2.add(4);
        obj2.add(5);
        cout << "Result of ContainsAll: " << obj.containsAll(obj2)<<endl;
        
        obj.remove(1);
        obj.remove(2);
        obj.remove(3);

        cout << "Size after calling remove: "<<obj.size()<<endl;
        //Remove All
        obj.removeAll(obj2);
        cout << "Size after calling RemoveAll: "<<obj.size()<<endl;

        LinkedList<int, std::vector > obj5;
        LinkedList<int, std::vector > obj6;

        //Retain All
        obj5.add(1);
        obj5.add(2);
        obj5.add(3);
        obj5.add(4);
        obj5.add(5);
        obj6.add(4);
        obj6.add(5);
        //Remove All

        obj5.retainAll(obj6);
        cout << "Size after calling Retain All: "<<obj5.size()<<endl;
        obj5.clear();
        cout << "Size after calling Clear: "<<obj5.size()<<endl;
        cout << "Result of isEmpty: "<<obj5.isEmpty()<<endl;
        LinkedList<int, std::vector> obj7;
        obj7.add(5);
        cout << "Result of Contains: "<<obj7.contains(5)<<endl;
    }
    {
        cout << "\n-------LINKEDLIST - SET-----------: \n\n";
        
        LinkedList<int, std::set > obj;
        LinkedList<int, std::set> obj2;

        //Add and Remove
        obj.add(1);
        obj.add(2);
        obj.add(3);
        obj.add(4);
        obj.add(5);
        obj2.add(4);
        obj2.add(5);
        cout << "Result of ContainsAll: " << obj.containsAll(obj2)<<endl;
       
        obj.remove(1);
        obj.remove(2);
        obj.remove(3);

        cout << "Size after calling remove: "<<obj.size()<<endl;
        //Remove All
        obj.removeAll(obj2);
        cout << "Size after calling RemoveAll: "<<obj.size()<<endl;

        LinkedList<int, std::set > obj5;
        LinkedList<int, std::set > obj6;

        //Retain All
        obj5.add(1);
        obj5.add(2);
        obj5.add(3);
        obj5.add(4);
        obj5.add(5);
        obj6.add(4);
        obj6.add(5);
        //Remove All
        obj5.retainAll(obj6);
        cout << "Size after calling Retain All: "<<obj5.size()<<endl;
        obj5.clear();
        cout << "Size after calling Clear: "<<obj5.size()<<endl;
        cout << "Result of isEmpty: "<<obj5.isEmpty()<<endl;
        LinkedList<int, std::set> obj7;
        obj7.add(5);
        cout << "Result of Contains: "<<obj7.contains(5)<<endl;
    }
   {
        cout << "\n-------LINKEDLIST - LIST-----------: \n\n";
        
        LinkedList<int, std::list > obj;
        LinkedList<int, std::list> obj2;

        //Add and Remove
        obj.add(1);
        obj.add(2);
        obj.add(3);
        obj.add(4);
        obj.add(5);
        obj2.add(4);
        obj2.add(5);
        cout << "Size after calling ContainsAll: " << obj.containsAll(obj2)<<endl;
        
        obj.remove(1);
        obj.remove(2);
        obj.remove(3);
        cout << "Size after calling remove: "<<obj.size()<<endl;
        //Remove All
        obj.removeAll(obj2);
        cout << "Size after calling RemoveAll: "<<obj.size()<<endl;

        LinkedList<int, std::list > obj5;
        LinkedList<int, std::list > obj6;

        //Retain All
        obj5.add(1);
        obj5.add(2);
        obj5.add(3);
        obj5.add(4);
        obj5.add(5);
        obj6.add(4);
        obj6.add(5);
        //Remove All
        
        obj5.clear();
        cout << "Size after calling Clear: "<<obj5.size()<<endl;
        cout << "Result of isEmpty: "<<obj5.isEmpty()<<endl;
        LinkedList<int, std::list> obj7;
        obj7.add(5);
        cout << "Result of Contains: "<<obj7.contains(5)<<endl;
    }


    return 0;
}

