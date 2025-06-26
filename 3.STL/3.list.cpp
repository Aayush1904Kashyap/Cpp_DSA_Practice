void explainList() {
list<int> ls;

ls.push_back(2); // (2)
ls.emplace_back(4); // 12,4)

ls.push_front(5); // (5, 2, 4);

ls.emplace_front(); (2, 4);

// rest functions same as vector
// begin, end, rbegin, rend, clear, insert, size, swap
//In summary, std::vector is typically preferred for its efficient random access and lower memory overhead, whereas std::list is favored for frequent insertions and deletions throughout the container
}