
#include "data/scripts/defines.h"
#import "data/scripts/lib.c"

#import "data/scripts/player_check_entities.c"

#import "data/scripts/water_puddle.c"
#import "data/scripts/ladder.c"
#import "data/scripts/climbable_area.c"
#import "data/scripts/halcove.c"


void main() {
  void self = getlocalvar("self");

    // CLIMBING AND ENTITIES COUNT FUNCS
    check_entitiesA(self);
    check_climb(self);
    check_climb_area(self);
    check_climb_halcove(self);

    if ( getlocalvar("water_puddle_found") == 1 ) check_ripple(self);
}

