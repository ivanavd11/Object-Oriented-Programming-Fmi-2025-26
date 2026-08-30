#include "Command.h"

Command::Command(Territory& terr)
	:territory(terr)
{

}
	
Territory& Command::getTerritory() const
{
	return territory;
}