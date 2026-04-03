void main()
{//Script for death blast
    void self = getlocalvar("self");
    void target = getlocalvar("damagetaker");
    int THP = getentityproperty(target,"health");

    if(target && THP > 0){
      damageentity(target, self, 5000, 1, openborconstant("ATK_NORMAL"));
    }
}
