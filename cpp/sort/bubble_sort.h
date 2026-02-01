#include <iterator>
#include <functional>

template <typename It, typename Comp = std::less<>>

void bubble_sort(It begin, It end, Comp comp = Comp{}) {
    if (begin == end || std::next(begin) == end) {
        return;
    }
    bool swapped;
    It last = end;
    do {
        swapped = false;
        It curr = begin;
        while (curr != std::prev(last)) {
            if (comp(*std::next(curr), *curr)) {
                std::swap(*curr, *std::next(curr));
                swapped = true;
            }
            curr++;
        }
        last = curr;
    } while(swapped);
}
