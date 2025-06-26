void explainVector() {

    vector<int> v; //--------->{}
    v.push_back(1);//--------->{1}
    v.emplace_back(2);//------->{1,2}

    vector<pair<int, int>> vec;
    v.push_back({1, 2});//------>pushback is slower than emblaceback
    v.emplace_back(1, 2);//----->emblaceback does not required curly braces

    vector<int> v(5, 100);//----->{100,100,100,100,100}

    vector<int> v(5);//------->{0,0,0,0,0} or five garbage value

    vector<int> v1(5, 20);
    vector<int> v2(v1); //------->v2 is another container with copy of v1

    //An iterator in C++ STL is an object that provides a way to access and traverse the elements of a container in a sequential manner, allowing both reading and modifying the elements.
    //v={10,20,30,40}
    vector<int>::iterator it = v.begin();//-------->v.begin() points to memory address of 0th index element(points to 10)

    it++;
    cout << *(it) << " ";//---------->print 20 as output

    it = it + 2;
    cout << *(it) << " ";//---------->print 40 as output

    vector<int>::iterator it = v.end();//-------> doesnot point to 40 but it point next memory location to 40 and then do it--
    vector<int>::iterator it = v.rend();// --------->point towards the just previous location before 10
    vector<int>::iterator it = v.rbegin();//---------> point to 40 and by i++ this moves to 30 then 20 then 10

    cout << v[0] << " " << v.at(0);//--------->accessing elements of vectors

    cout << v.back() << " ";//------> element from back i.e print 40 as output

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    for (auto it = v.begin(); it != v.end(); it++) { //------> instead of vector<int>::iterator it we can write AUTO        cout << *(it) << " ";
    }

    for(auto it:v){
        cout<<it<<" ";//-------->prints vector
    }

    //deletion
        v.erase(v.begin()+1);//-------->v={10,30,40}
        //v={1,2,3,4,5}
        v.erase(v.begin()+2,v.begin()+4);//-------v={1,2,5}---->[start,end)

    //insertion
        vector<int>v(2, 100); // {100, 100}
        v.insert(v.begin(), 300); // {300, 100, 100};
        v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

        vector<int> copy(2, 50); // {50, 50}
        v.insert(v.begin(), copy.begin(), copy.end()); // 50, 50, 300, 10, 10, 100, 100}

        // {10, 20}
        cout << v.size(); // 2

        //{10, 20}
        v.pop_back(); // {10}

        // v1 -> {10, 20}
        // v2 -> {30, 40}
        v1.swap(v2); // v1 -> {30, 40} v2 -> {10, 20}

        v.clear();//->clear entire vector
        cout<<v.empty();
}


