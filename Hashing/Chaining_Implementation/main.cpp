#include <bits/stdc++.h>

using namespace std;
struct MyHash{
private:
    int Bucket;
    list<int> *table;
public:
    MyHash(int b){
        Bucket=b;
        table=new list<int>[b];
    }
    void insert (int key){
        int index=key%Bucket;
        table[index].push_back(key);
    }
    void remove(int key){
        int index=key%Bucket;
        table[index].remove(key);
    }
    bool search(int key){
        int index=key%Bucket;
        for(auto item : table[index]){
            if(item==key){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    MyHash obj(7);
    obj.insert(9);
    obj.insert(17);
    obj.insert(15);
    obj.remove(9);
    if(obj.search(15))
        cout<<"15 availiable";
    return 0;
}
