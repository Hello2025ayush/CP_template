#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,     tree_order_statistics_node_update>;
// find_by_order, order_of_key


/*

oset<ll> s          // declaration
s.insert(18)        // insert
less -> greater     // store ele in descending order
less -> less_equal  // becomes multiset
s.erase(value)      // O(logn)  -> nothing happens if not present
s.order_of_key(val) // O(logn)

TRICK --> s.order_of_key(val) --> no. of ele strictly less that this val.

s.find_by_order(3)  // O(logn) return iterator  of value at index 3 (0 - based)
*(above) == index (0 based)


s.lower_bound()  --> same as set
s.upper_bound()  --> same as set

*/
