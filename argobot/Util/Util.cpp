#include <BWAPI/Unit.h>

template <typename InputIterator, typename Pred, typename Exec>
void forEachIf(InputIterator begin, InputIterator end, Pred pred, Exec func)
{
	for (auto it = begin; it != end; ++it)
	{
		if (pred(*it))
			func(*it);
	}
}

template <typename InputIterator, typename Pred>
std::vector<BWAPI::Unit> getSubset(InputIterator begin, InputIterator end, Pred pred)
{
	std::vector<BWAPI::Unit> ret;
	for (auto it = begin; it != end; ++it)
	{
		if (pred(*it))
			ret.push_back(*it);
	}
	return ret;
}

