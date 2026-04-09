
#include "data/scripts/defines.h"
#import "data/scripts/lib.c"

int get_grabber(void player) {
    return getentityvar(player, "grabber");
}

int set_grabber(void player, void grabber) {
    setentityvar(player, "grabber", grabber);
    changeentityproperty(player,"opponent",grabber);
    changeentityproperty(grabber,"opponent",player);
}

