class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int,int>mp;
    RandomizedSet() {}

    bool insert(int val) {
        if(mp.count(val) == 0 || mp[val] == -1){
            mp[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if(mp.count(val) && mp[val] != -1){
            swap(nums[nums.size()-1],nums[mp[val]]);
            mp[nums[mp[val]]] = mp[val];
            mp[val] = -1;
            nums.pop_back();
            return true;
        }
        return false;
    }

    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
