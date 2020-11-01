# Vector

```cpp
#include<vector>
vector<object_type> v ( size_of_object , intial_value )
vector<int> v (10,5) ;
vector<int> v = {2,4,5,9} ;
```
10^7 ===>>> 0,5

10^8 ===>>> 2,5

### Iterators 

v.begin()    || O(1) || Returns an iterator pointing to the first element 

v.end()      || O(1) || Returns an iterator pointing to the last element 

v.rbegin()   || O(1) || Returns a reverse iterator pointing to the last element 

v.rend()     || O(1) || Returns a reverse iterator pointing to the first element 

v.cbegin()   || O(1) || Returns a const_iterator pointing to the first element 

v.cend()     || O(1) || Returns a const_iterator pointing to the last element 

v.crbegin()  || O(1) || Returns a const_reverse_iterator pointing to the last element 

v.crend()    || O(1) || Returns a const_reverse_iterator pointing to the first element 

### Element Access 

v.front()    || O(1) || Returns a reference pointing to the first element 

v.back()     || O(1) || Returns a reference pointing to the last element 

v.at(pos)    || O(1) || Returns a reference to the element at position pos (O-Indexed)

operator[pos]|| O(1) || Returns a reference to the element at position pos (O-Indexed)

v.data()     || O(1) || Returns a pointer to the first element 

### Capacity 

v.size()     || O(1) || Returns the number of elements 

v.max_size() || O(1) || Returns the maximum number of elements that the container can hold

v.empty()    || O(1) || Returns whether the container is empty 

v.resize(n)  ||      || Change size of vector to n size

If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond.
   
If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n
   
Complexity : Linear on the number of elements inserted / erased 

### Modifiers 

**assign**

v.assign(n,val) OR v1.assign(v2 first iterator ,v2 last iterator)

Complexity : Linear on initial + final sizes

**insert**

v.insert(iterator,val) OR v.insert(iterator,n,val) OR v1.insert(v1 iterator,v2 first iterator,v2 last iterator)

Complexity : Linear on the number of elements inserted plus the number of elements after position

**erase**

v.erase(iterator) OR v.erase(first iterator , last iterator)

Complexity : Linear on the number of elements erased plus the number of elements after the last element deleted 

(Linear on the size of vector before erase operation)

**emplace**

v.emplace(iterator,val) || Insert a new element at position of iterator (faster)
Complexity : Linear on the number of elements after position

v.push_back(val)    || O(1) || Add element at the end 

v.emplace_back(val) || O(1) || Add element at the end   (faster)

v.pop_back()        || O(1) || Delete the last element 

v1.swap(v2)         || O(1) || Sawp two container

swap(v[0],v[2])     || O(1) || Sawp two elements

v.clear()  || Linear in size || Removes all elements , leaving the vector with a size of 0

### Member functions 

v1.operator=(v2) OR v1=v2|| Linear in size || Assigns new contents , replacing its current contents, and modifying its size  

## vector of boolean

```cpp
vector<bool>v;
```
like vector, except data, emplace, and emplace_back, add to

v.flip() || Linear in size || Flips all values : All instances of true become false, and all instances of false become true