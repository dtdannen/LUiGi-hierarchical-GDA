#include "BWAPI.h"
#include "BWTA.h"
#include <map>
#include <boost\foreach.hpp>
#include <boost\tokenizer.hpp>
#include <boost\lexical_cast.hpp>
#include <boost\format.hpp>
#include "UnitProductionManager.h"

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
	( std::ostringstream() << std::dec << x ) ).str()

class AttackClosestScript {

public:

	AttackClosestScript(std::set<BWAPI::Unit*>, BWAPI::Position);
	AttackClosestScript::AttackClosestScript();
	void update();
	bool finished();
	void finishedProduce(std::map<BWAPI::UnitType , int> * How_Many_Died ,int* Total_Died, int * Enemy_Scale , int * Our_Scale , int * StillMoving);
	void setUnits( std::set<BWAPI::Unit*> availableUnits );
	void killWorkerUnits();

private:
	std::set<BWAPI::Unit*> unitsForCombat;
	std::set<BWAPI::Unit*> nearbyEnemyUnits;
	std::set<BWAPI::Unit*> nearbyWorkerEnemyUnits;
	std::map<int, int> attackAssignments;

	BWAPI::Unit* findClosestEnemyUnit(BWAPI::Unit* myUnit, std::set<BWAPI::Unit*>);
	BWAPI::Unit* findClosestEnemyUnitNOK(BWAPI::Unit*, std::set<BWAPI::Unit*>, std::map<int,int>);
	
	BWAPI::Position destination;
	bool targetPriorityWorkerUnit;

};