class SmallestInfiniteSet {
public:
    set<int>s;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
            s.insert(i);
    }
    
    int popSmallest() {
        int res=*s.begin();
        s.erase(s.begin());
        return res;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */