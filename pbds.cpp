#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using oset = tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update>;

//  CAUTIONNNN !!!! bsdk...    replace in code ::: int --> ll  (fking overflow...);


// find_by_order, order_of_key
/*

    oset s;  // kind of a multiset using {val, idx}

    s.size()                    ==> Yees it works.
    s.insert({val , idx});
    s.erase({val, idx});          !! does nothing if not present

    s.order_of_key({val, idx});  ---> no. of values strictly!! < {val, idx};

                                     {val, idx-1}  <  {val, idx};

    auto it = s.find_by_order(6) ---> returns (iterator) to 6th index value in set (0-based !!);

    auto[val, idx] = *it;

    ... use the idk to do shit..


    SETUP ---
               1) remove #define int long long and use ll whenever want
               
*/

ll idk(oset &s, ll l, ll r) {
    // [l...r] incl. boht
    return s.order_of_key({r, inf}) - s.order_of_key({l, -inf});
}
