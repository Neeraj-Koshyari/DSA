----------------------------------------------- Pythagorus: --------------------------------------------

  how to determine the other 2 values by given one value
  
  Vlog link : [Click me](https://byjus.com/maths/pythagorean-triples/)
  Problem Link: [Click me](https://codeforces.com/problemset/problem/1487/D)


------------------------------------- C++ STL: Policy based data structures [Link](https://codeforces.com/blog/entry/11080) ------------------------------<br>
  Using the above data structure we can find index of an element in set in log(n) time<br>

  Header files needs to include:<br>
    #include <ext/pb_ds/assoc_container.hpp> // Common file<br>
    #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update


  template:<br>
  ------------------------------------------  for unique elements (set)  ---------------------------------------<br>
    typedef tree<<br>
    int,<br>
    null_type,<br>
    less<int>,<br>
    rb_tree_tag,<br>
    tree_order_statistics_node_update><br>
    ordered_set;<br>

  ------------------------------------------  for duplicate elemets (multiset)  ----------------------------------<br>
    typedef tree<<br>
    pair<int, int>,<br>
    null_type,<br>
    less<pair<int, int>>,<br>
    rb_tree_tag,<br>
    tree_order_statistics_node_update> ordered_set;<br>

  then while insertion do st.insert{value,index} this will bring uniqueness.

  Basic functions: <br>
    set_name.find_by_order(value)    //returns an iterator to the k-th largest element (counting from zero)<br>
    set_name.order_of_key(value)     //returns the number of items in a set that are strictly smaller than our item.<br>
