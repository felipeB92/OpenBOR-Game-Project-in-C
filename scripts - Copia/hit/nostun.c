void main()
{// Anti stun script
    void self = getlocalvar("self"); //Get calling entity
    void target = getentityproperty(self,"opponent");
    int Type = getlocalvar("attacktype");
    int Defense;

    if(Type == openborconstant("ATK_FREEZE")){
      changeentityproperty(self, "freezetime", 1);
    }

    if(Type == openborconstant("ATK_NORMAL2")){
      Defense = getentityproperty(target, "defense", openborconstant("ATK_NORMAL2"));

      if(Defense == 0){
        changeentityproperty(self, "dot", 1, "force", 0);
      }
    } else if(Type == openborconstant("ATK_NORMAL8")){
      Defense = getentityproperty(target, "defense", openborconstant("ATK_NORMAL8"));

      if(Defense == 0){
        changeentityproperty(self, "dot", 1, "force", 0);
      }
    }
}