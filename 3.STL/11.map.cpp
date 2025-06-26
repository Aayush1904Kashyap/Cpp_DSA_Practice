//key value pair where key are unique
//map store unique key in sorted order

void explainMap() {

map<int, int> mpp;//map<key,value>mpp;

map<int, pair<int, int>> mpp;

map< pair<int, int>, int> mpp;

mpp[1] = 2;

mpp.emplace((3, 1));

mpp.insert((2, 4));

mpp[{2,3}] = 10;

for(auto it: mpp) {
cout << it.first <<" "<< it.second << endl;
}

cout << mpp[1];
cout << mpp[5];

auto it=mpp.find(3);
cout<<*(it).second;

auto it=mpp.find(5);//->point after the map

auto it=mpp.lower_bound(2);
auto it=mpp.upper_bound(3);

//erase,swap,size,empty are same
}

void explainMultiMap(){
    //everything same as map,only it can store multiple keys
    //only mpp[key] cannot be used her
}

void explainUnorderedMap(){
    //same as set and unordered set difference
}