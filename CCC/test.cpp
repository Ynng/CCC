#include <map>
#include <iostream>

using namespace std;

int main(){
    map<int,int> mp;
    mp[1]=0;
    mp[12]=123;
    mp[23]=345;
    for(auto item = mp.begin();item!=mp.end();item++){
        cout<<item->first<<","<<item->second<<endl;
    }
    return 0;
}