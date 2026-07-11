/*
info
    - all function should work in O(1) runtime
    
    constraints:
        - range of values that val can have? [int_min, int_max]
        - number of operations expected to receive? [200k]
        - can get random be called with an empty set? no
        
        
        39 min 50 sec le3ft. after wrtiting all docstrings and until this point
        
    walkthrough
    
        DS brainstorm
            unordered_set 
                - insert o(1)
                - remove o(1)
                - getRandom is not possible? unless we can get random pointer from the set
                    but hten we have to traverse
                    
                how can we get a o(1) search?, insertion or removal?
                not with this DS only
                
                we could use an array to store all the values
                we leverage the rand() + (i+1) to get a random index.in o(1) 
                
                remove from the set is still o(1), but how do we remove from the vector?
                
                maybe an unordered_map with a key pointing to the index in the vector.
                if we want to remove an elemnet, we swap the value with the last element and pop back
                    and update the index position in the unordered map
                    
                32 min left, abt to start implementation
                

*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> ht;
    vector<int> values;
    
public:
    RandomizedSet() {
        /*
        inititates object
        ht is already empty
        */
    }
    
    bool insert(int val) {
        /*
            Inserts element val into the set if not present
            - return true if the element is not present, else false
        */
        
        // element present
        if(ht.find(val) != ht.end()) return false;
        
        // element not present
        this->values.push_back(val);
        ht[val] = this->values.size()-1;
        
        return true;
        // 26 min 50 sec left
    }
    
    bool remove(int val) {
        /*
            Removes element val from the set if present
            - return true if the element was present, else false
        */
        
        // element not present
        if(ht.find(val) == ht.end()) return false;
        
        // element present
        
        // indexes of values to swap
        int last = this->values.size()-1;
        int curr = ht[val]; /// idx of element to remove
        
        /*
        ht = {
            0:0,
            1:2,
            2:1
        }
        [0,2,1]
           c l
        
        */
        
        // swap values in the unordered_map
        this->ht[val] = last;
        this->ht[this->values[last]] = curr;
        
        // swap position with last element
        swap(this->values[curr], this->values[last]);
        
        // remove from the ht and vector
        this->ht.erase(val);
        this->values.pop_back();
        // 17 min 20 sec left
        
        return true;
        
    }
    
    int getRandom() {
       /*
        - returns a random element from the current set of elements
            - each element must have the same probability of being returned
       */ 
        
        int idx = rand() % this->values.size();
        return this->values[idx];
        // implemented before remove, 25 min left
    }
};
/*
okay, im getting some errors, but im not sure what they are related to
in the insert i was not doing n-1, i left it at 1

my bad, this costed me like 15 minutes. in an interview prob i wouldn trun the code so this may not impact me that bad

but i should always do a recap of the implementation and look at the hot spots
*/
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
