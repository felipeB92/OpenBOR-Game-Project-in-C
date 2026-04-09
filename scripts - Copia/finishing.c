void main()
{// Increase resistance to prevent non-finishing blow to kill character
    void self = getlocalvar("self");
    int HP = getentityproperty(self, "health");
    int Damage = getlocalvar("damage"); //Get received damage
    int Type = getlocalvar("attacktype"); //Get received damage type

    if(HP <= Damage && HP <= 5 && (Type == openborconstant("ATK_NORMAL14") || Type == openborconstant("ATK_NORMAL18") || Type == openborconstant("ATK_NORMAL5") || Type == openborconstant("ATK_NORMAL1") || Type == openborconstant("ATK_NORMAL3") ) ){
      changeentityproperty(self, "health", 5);
    }


if(HP <= Damage && HP <= 10 && (Type == openborconstant("ATK_NORMAL14") || Type == openborconstant("ATK_NORMAL18") || Type == openborconstant("ATK_NORMAL5") || Type == openborconstant("ATK_NORMAL2") || Type == openborconstant("ATK_NORMAL1") || Type == openborconstant("ATK_NORMAL3") ) ){
     changeentityproperty(self, "health", 15);
    }
}