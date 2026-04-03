void main()
{// Special Reaction for Quest of Riddles' sentries
    void self = getlocalvar("self");
    int React = getentityvar(self,1);
    int Lock = getglobalvar("RLock");
    char Name = getentityproperty(self,"defaultname");

    if(React==NULL()){
      setentityvar(self,1,5);
      changeentityproperty(self,"defense", openborconstant("ATK_NORMAL3"), 1,1);
      changeentityproperty(self,"defense", openborconstant("ATK_NORMAL9"), 1,1);
      changeentityproperty(self,"defense", openborconstant("ATK_NORMAL12"), 1,1);

      if(Name == "ZombOrcR" && Lock==NULL()){
        setglobalvar("RLock",1);
      } else if(Name == "GhoulR" && Lock==NULL()){
        setglobalvar("RLock",0);
      } else if(Name == "SkeletonR" && Lock==NULL()){
        setglobalvar("RLock",-1);
      }
    }
}
