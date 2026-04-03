void main()
{// Vampire Ray hit script which gives HP to its parent
// Only used by Tel'Erond's vampire's ray
    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");

    if(target!=NULL()){
      void Parent = getentityproperty(self,"parent");
      int Health = getentityproperty(Parent, "health");

      changeentityproperty(Parent, "health", Health + 20);
    }
}