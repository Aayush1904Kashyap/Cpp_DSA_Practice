void explainDeque() {

Deque<int>dq;

dq.push_back(1); // (1)
dq.emplace_back(2); // (1, 2)
dq.push_front(4); // (4, 1, 2)
dq.emplace_front(3); // (3, 4, 1, 2)

dq.pop_back(); // (3, 4, 1)
dq.pop_front(); // (4, 1)

dq.back();

dq.front();

// rest functions same as vector
// begin, end, rbegin, rend, clear, insert, size, swap
/*std::deque provides a versatile alternative to std::vector and std::list in scenarios
 where efficient insertion and deletion operations are needed at both ends of the container, 
 while also supporting efficient random access. It strikes a balance between the capabilities
  of std::vector and std::list, making it suitable for various applications where dynamic
   resizing and efficient element manipulation are required.
*/
}