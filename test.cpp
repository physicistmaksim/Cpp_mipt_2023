#include <iostream>

struct Segment {
    int const beg, end;
    Segment(int beg, int end): beg(beg), end(end) { }
    int length() const {
        if (end < beg) return 0;
        return end - beg;
    }
};

int main() {
    Segment a(2, 12);
    Segment const &a_ref = a;
    std::cout << a_ref.length() << std::endl;
    return 0;
}