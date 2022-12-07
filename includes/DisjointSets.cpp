/* Your code here! */
#include "../includes/DisjointSets.hpp"

void DisjointSets::addelements(int num) {
    for (int i = 0; i < num; i++) {
        elements_.push_back(-1);
    }
}
int DisjointSets::find(int elem) {
    if (elements_.at(elem) < 0) {
        return elem;
    }
    int to_return = find(elements_.at(elem));
    elements_.at(elem) = to_return;
    return to_return;

}
void DisjointSets::setunion(int a, int b) {
    int new_size = (size(a) + size(b)) * -1;
    if (size(a) >= size(b)) {
        elements_.at(find(b)) = find(a);
        elements_.at(find(a)) = new_size;
    } else {
        elements_.at(find(a)) = find(b);
        elements_.at(find(b)) = new_size;
    }
}
int DisjointSets::size(int elem) {
    int index = find(elem);
    return elements_.at(index) * -1;
}