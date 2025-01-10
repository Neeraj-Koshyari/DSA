----------------------------------------------- Pythagorus: --------------------------------------------

  how to determine the other 2 values by given one value
  
  Vlog link : [Click me](https://byjus.com/maths/pythagorean-triples/)
  Problem Link: [Click me](https://codeforces.com/problemset/problem/1487/D)


------------------------------------- C++ STL: Policy based data structures [Link](https://codeforces.com/blog/entry/11080) ------------------------------<br>
  Using the above data structure we can find index of an element in set in log(n) time<br>

  Header files needs to include:<br>
    <code>#include <ext/pb_ds/assoc_container.hpp> // Common file
    #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update</code>

  name space:<br>
    <code>using namespace __gnu_pbds;</code>


  template:<br>
  ------------------------------------------  for unique elements (set)  ---------------------------------------<br>
    <code>typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;</code>

  ------------------------------------------  for duplicate elemets (multiset)  ----------------------------------<br>
    <code>typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;</code>

  then while insertion do st.insert{value,index} this will bring uniqueness.

  Basic functions: <br>
    <code>me.insert(value);
    me.erase(value);
    set_name.find_by_order(value)    //returns an iterator to the k-th largest element (counting from zero)<br>
    set_name.order_of_key(value)     //returns the number of items in a set that are strictly smaller than our item.</code>

  example:
  <code>
  #include <ext/pb_ds/assoc_container.hpp> // Common file
  #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

  using namespace __gnu_pbds;
  
  typedef tree<
  pair<int, int>,
  null_type,
  less<pair<int, int>>,
  rb_tree_tag,
  tree_order_statistics_node_update> ordered_set;
  
  int n = nums.size();
  
  vector<int> ans(n);
  ordered_set st;
  for(int i=0;i<n;i++){
      st.insert({nums[i],i});
      ans[i] = st.order_of_key({nums[i],i});
  }

  return ans;</code>
