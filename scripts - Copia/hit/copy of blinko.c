void main()
{// Blink effect script
    void self = getlocalvar("self"); //Get calling entity.
    int Health = getentityproperty(self,"health");
    int Type = getlocalvar("attacktype");

    if (Health > 0){
      changeentityproperty(self, "colourmap", 1);
      changeentityproperty(self, "maptime", 20 + openborvariant("elapsed_time"));

      if(Type == openborconstant("ATK_FREEZE")){
        changeentityproperty(self, "freezetime", 1);
      }
    }
}