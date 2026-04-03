
#include "data/scripts/defines.h"

#import "data/scripts/lib.c"

void set_main_opp(void self, void opp) {
    setentityvar(self,27,opp);
}

char get_main_opp(void self) {
    return getentityvar(self,27);
}

void set_bindgrab_partner(void self, void partner) {
    int p = getentityproperty(self, "playerindex");
    setglobalvar("bindgrab_partner"+p, partner);
}

void get_bindgrab_partner(void self) {
    int p = getentityproperty(self, "playerindex");
    return getglobalvar("bindgrab_partner"+p);
}

void set_bindgrab_type(void self, void type) {
    int p = getentityproperty(self, "playerindex");
    setglobalvar("bindgrab_type"+p, type);
}

void get_bindgrab_type(void self) {
    int p = getentityproperty(self, "playerindex");
    return getglobalvar("bindgrab_type"+p);
}

void set_grabbed_opp(void self,void opp) {
    sev(self,"grabbed_opp",opp);
    changeentityproperty(self,"opponent",opp);
    changeentityproperty(opp,"opponent",self);
}

void get_grabbed_opp(void self) {
    if ( !gep(gev(self,"grabbed_opp"),"exists") ) sev(self,"grabbed_opp",NULL());

    return gev(self,"grabbed_opp");
}
