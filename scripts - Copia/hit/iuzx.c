void main()
{// Endure script (to prevent entity from death)
    void self = getlocalvar("self"); //Get calling entity.
    int HP = getentityproperty(self, "health");
    int Damage = getlocalvar("damage"); //Get received damage
    int Type = getlocalvar("attacktype");

    if(Type == openborconstant("ATK_FREEZE")){
      changeentityproperty(self, "freezetime", 1);
    }

    if(HP <= Damage && HP <= 500 && Type != openborconstant("ATK_NORMAL7")){
      changeentityproperty(self, "health", 500);
    }
}