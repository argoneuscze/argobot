#pragma once

#include "Manager.h"
#include <BWAPI/Unit.h>
#include <vector>

class UnitManager : public Manager
{
	using unitRefs = std::vector<std::reference_wrapper<BWAPI::Unit>>;

private:
	std::vector<BWAPI::Unit> workers;

	template <typename InputIterator, typename Pred>
	unitRefs getUnitRefs(InputIterator begin, InputIterator end, Pred func)
	{
		unitRefs ret;
		for (auto it = begin; it != end; ++it)
		{
			if (func(*it))
				ret.push_back(std::ref(*it));
		}
		return ret;
	}

public:
	void onStart() override;

	const std::vector<BWAPI::Unit>& getAllWorkers() const;
	unitRefs getIdleWorkers();
};

