#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main()
{
    int n, wood[1000000], longest, longestCount;
    longest =longestCount = 0;
    vector<int> v;
    map<int, int> m;
    map<int, int> mm;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &wood[i]);
    }
    for (int i = 0; i < n; i++)
    {
        m[wood[i]]++;
    }
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        v.push_back(it->first);
    }

    //for making sure the mapping is right
    /*for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" "<<m[v[i]]<<endl;
    }*/

    for (int i = 0; i < v.size(); i++)
    {
        if(m[v[i]]>1)mm[v[i]*2]+=m[v[i]]/2;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (m[v[i]] < m[v[j]])
                mm[v[i] + v[j]] += m[v[i]];
            else
                mm[v[i] + v[j]] += m[v[j]];
        }
    }

    for (map<int, int>::iterator it = mm.begin(); it != mm.end(); ++it)
    {
        if(it->second>longest){
            longest=it->second;
            longestCount=1;
        }else if(it->second==longest)longestCount++;
    }

    printf("%d %d",longest, longestCount);

    //for making sure the mapping is right
    /*for (int i = 0; i < w.size(); i++)
    {
        cout<<w[i]<<" "<<mm[w[i]]<<endl;
    }*/

    //sort(wood, wood + n);
    printf("\n");
    return 0;
}
