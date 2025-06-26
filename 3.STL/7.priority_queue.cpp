void explainPO() {
priority_queue<int>pq;

pq.push(5); // (5) 
pq.push(2); // (5.2)
pq.push(8); // (8, 5, 2)
pq.emplace(10); // (10, 8, 5, 2)

cout << pq.top(); // prints 10

pq.pop(); // (8, 5, 2)

cout << pq.top(); // prints 8

// size swap empty function same as others

// Minimum Heap 
priority_queue<int, vector<int>, greater<int>> pq; 
pq.push(5); // (5)
pq.push(2); //(2.5) 
pq.push(8); // (2, 5, 8)
pq.emplace(10); // (2, 5, 8, 10)

cout cout << pq.top(); // prints 2
}
/*a priority queue is a container adaptor that provides a way to store elements in a sorted order based on some priority.
 It is implemented as a max-heap by default, where the element with the highest priority is always at the front of the queue 
 (i.e., the greatest element in the container).*/