void main()
{// Anti DOT script
    void self = getlocalvar("self"); //Get calling entity.
    int Type = getlocalvar("attacktype");

    if(Type == openborconstant("ATK_NORMAL2") || Type == openborconstant("ATK_NORMAL8")){
      changeentityproperty(self, "dot", 1, "force", 0);
    }
}