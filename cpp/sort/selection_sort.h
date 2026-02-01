#include <iterator>
#include <functional>

template <typename It, typename Comp = std::less<>>

void selection_sort(It begin, It end, Comp comp = Comp{}) {
    if (begin == end || std::next(begin) == end) {
        return;
    }
    It curr_dstp = begin;
    It last_elem = std::prev(end);
    while (curr_dstp != last_elem) {
        It slct_elem = curr_dstp;
        It curr_srcp = std::next(curr_dstp);
        while (curr_srcp != end) {
            if (comp(*curr_srcp, *slct_elem)) {
                slct_elem = curr_srcp;
            }
            curr_srcp = std::next(curr_srcp);
        }
        std::swap(*curr_dstp, *slct_elem);
        curr_dstp = std::next(curr_dstp);
    }
}
