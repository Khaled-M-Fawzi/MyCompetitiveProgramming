# Set & Multiset

Sets are containers that store unique elements following a specific order

set is paradigm of red_back_tree
```cpp
#inlcude<set>
set<object_type>object_name;
```
## Iterators 

st.begin()    || O(1) || Returns an iterator pointing to the first element 

st.end()      || O(1) || Returns an iterator pointing to the last element 

st.rbegin()   || O(1) || Returns a reverse iterator pointing to the last element 

st.rend()     || O(1) || Returns a reverse iterator pointing to the first element 

st.cbegin()   || O(1) || Returns a const_iterator pointing to the first element 

st.cend()     || O(1) || Returns a const_iterator pointing to the last element 

st.crbegin()  || O(1) || Returns a const_reverse_iterator pointing to the last element 

st.crend()    || O(1) || Returns a const_reverse_iterator pointing to the first element 

## Capacity 

st.size()     || O(1) || Returns the number of elements 

st.max_size() || O(1) || Returns the maximum number of elements that the container can hold

st.empty()    || O(1) || Returns whether the container is empty 

## Modifiers 

**Insert**

st.insert(val) O(log n)   OR 

st.insert(iterator,val) O(log n) (faster) // iterator = m.begin()   OR 

st1.insert(st2 first iterator,st2 last iterator) Complexity : number of elements inserted * log n

**Erase**

st.erase(iterator) O(log n) OR 

st.erase(val) O(log n) OR 

st.erase(first iterator , last iterator) Complexity : number of elements erased * log n

**Emplace**

st.emplace(val) || Insert a new element O(log n)   (faster)

st.emplace_hint(iterator,val) || Insert a new element with a pointer hint O(log n) (faster than st.emplace)
 
 
st1.swap(st2)  || O(1) || Swap two container

st.clear()  || Linear in size || Removes all elements , leaving the container with a size of 0

## Operations 

**count**

int cnt = st.count(val)  O(log n)

Searches the container for elements equivalent to val and returns the number of matches.

Because all elements in a set container are unique, the function can only return 1 (if the element is found) or zero (otherwise)
but not at multiset

**find**

auto it = st.find(val)  O(log n)

Searches the container for an element equivalent to val and returns an iterator to it if found
otherwise it returns an iterator to set::end
```cpp
    set<int>st;
    auto it = st.begin();
    for(int i=1;i<10;i++)
        st.insert(it,i);
    if(st.find(8)!=st.end())
        cout<<"found";
```

**lower_bound** 

auto it = st.lower_bound(val) O(log n)

Returns an iterator pointing to the first element in the container which either it is equal or greater than val
if no such element , it's return iterator it's value is size of set.

```cpp
    set<int>st;
    auto it=st.begin();
    for(int i=1;i<10;i++)
        st.insert(it,i);
     it = st.lower_bound(3);  // 3
```

**upper_bound**

auto it = st.upper_bound(val) O(log n)

Returns an iterator pointing to the first element in the container which it is greater than val
if no such element , it's return iterator it's value is size of set.

```cpp
    set<int>st;auto it=st.begin();
    for(int i=1;i<10;i++)
        st.insert(it,i);
     auto it = st.upper_bound(3);  // 4
```
**Equal_range**
```cpp
  set<int> st;
  for (int i=1; i<=5; i++) st.insert(i*10);   // st: 10 20 30 40 50

  pair<set<int>::const_iterator,set<int>::const_iterator> ret;
  
  ret = st.equal_range(30);
  cout << "the lower bound points to: " << *ret.first << '\n';  // 30
  cout << "the upper bound points to: " << *ret.second << '\n'; // 40
  
  ret = st.equal_range(5);
  cout << "the lower bound points to: " << *ret.first << '\n';  // 10
  cout << "the upper bound points to: " << *ret.second << '\n'; // 10
  
  ret = st.equal_range(50);
  cout << "the lower bound points to: " << *ret.first << '\n';  // 50
  cout << "the upper bound points to: " << *ret.second << '\n'; // 5

  ret = st.equal_range(60);
  cout << "the lower bound points to: " << *ret.first << '\n';  // 5
  cout << "the upper bound points to: " << *ret.second << '\n'; // 5
```
Complexity : O(log n)

## Multiset 

Multisets are containers that store elements following a specific order, and where multiple elements can have equivalent values
and it has the some properties of set