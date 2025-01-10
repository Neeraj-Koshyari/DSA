----------------------------------------------- Pythagorus: --------------------------------------------

  how to determine the other 2 values by given one value
  
  Vlog link : [Click me](https://byjus.com/maths/pythagorean-triples/)
  Problem Link: [Click me](https://codeforces.com/problemset/problem/1487/D)


------------------------------------- C++ STL: Policy based data structures [Link](https://codeforces.com/blog/entry/11080) ------------------------------
  Using the above data structure we can find index of an element in set in log(n) time

  Header files needs to include:
    #include <ext/pb_ds/assoc_container.hpp> // Common file
    #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

  template:
  ------------------------------------------  for unique elements (set)  ---------------------------------------
    typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

  ------------------------------------------  for duplicate elemets (multiset)  ----------------------------------
    typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

  then while insertion do st.insert{value,index} this will bring uniqueness.

  Basic functions: 
    set_name.find_by_order(value)    //returns an iterator to the k-th largest element (counting from zero)
    set_name.order_of_key(value)     //returns the number of items in a set that are strictly smaller than our item.
