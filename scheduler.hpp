#ifndef SCHEDULER_CPP_INCLUDED_422_MTD_
#define SCHEDULER_CPP_INCLUDED_422_MTD_

#include <unordered_set>
#include "command.hpp"
#include "command_sequence.hpp"
#include "subsystem.hpp"

class Scheduler {
  public:
	bool schedule( Command& );
	bool schedule( CommandSequence& )
	bool repeat( Command& );
	bool repeat( CommandSequence& );
	bool repeat( Command&, int );
	bool repeat( CommandSequence&, int );

  private:
	std::unordered_set<Subsystem*> my_active_subsystems;
};

#endif // SCHEDULER_CPP_INCLUDED_422_MTD
