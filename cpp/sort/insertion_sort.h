#include <iterator>
#include <functional>

template <typename It, typename Comp = std::less<>>

void insertion_sort(It begin, It end, Comp comp = Comp{}) {
    if (begin == end || std::next(begin) == end) {
        return;
    }
    It curr_elem = std::next(begin);
    while (curr_elem != end) {
        auto curr_move_elem = std::move(*curr_elem);
        It inst_elem = curr_elem;
        while (inst_elem!=begin && comp(curr_move_elem, *std::prev(inst_elem))) {
            *inst_elem = std::move(*std::prev(inst_elem));
            inst_elem = std::prev(inst_elem);
        }
        *inst_elem = std::move(curr_move_elem);
        curr_elem = std::next(curr_elem);
    }
}
