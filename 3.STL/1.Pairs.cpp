void explainPair() {
    // Creating a pair of integers p with values 1 and 3
    pair<int, int> p = {1, 3};
    
    // Outputting the first and second elements of pair p
    cout << p.first << " " << p.second << endl;
    
    // Creating a pair where the first element is an integer, and the second element is another pair of integers
    pair<int, pair<int, int>> nested_pair = {1, {3, 4}};
    
    // Outputting the first element of the outer pair, and the first and second elements of the inner pair
    cout << nested_pair.first << " " << nested_pair.second.first << " " << nested_pair.second.second << endl;
    
    // Creating an array of pairs of integers
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    
    // Outputting the second element of the pair at index 1 in the array arr
    cout << arr[1].second << endl;
}
