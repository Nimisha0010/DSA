class LRUCache {
private:
   unordered_map<int,pair<int,list<int>::iterator>> cache;
   list<int> od;
   int capacity;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    int get(int key) {
        if(cache.find(key)==cache.end())return -1;
        od.erase(cache[key].second);
        od.push_back(key);
        cache[key].second=--od.end();
        return cache[key].first;
    }
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            od.erase(cache[key].second);
        }else if(cache.size()==capacity){
            int l=od.front();
            od.pop_front();
            cache.erase(l);
        }
        od.push_back(key);
        cache[key]={value,--od.end()};
    }
};
