void main()
{// Blink effect + pain time script
    void self = getlocalvar("self");
    void target = getentityproperty(self,"opponent");
    int Health = getentityproperty(self,"health");
    int Damage = getlocalvar("damage");
    int Type = getlocalvar("attacktype");
    int Pain = getlocalvar("Pain"+self);
    int Defense;

    if(Health > 0){
      if(Pain == NULL() || Pain <= openborvariant("elapsed_time") - 150){
        changeentityproperty(self, "colourmap", 1);
        changeentityproperty(self, "maptime", 20 + openborvariant("elapsed_time"));

      } else {
        changeentityproperty(self, "health", Health + Damage);
      }

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

      if(Pain == NULL()){
        setlocalvar("Pain"+self, openborvariant("elapsed_time"));
      } else if(Pain <= openborvariant("elapsed_time") - 300){
        setlocalvar("Pain"+self, NULL());
      }
    }
}