void main()
{// Projectile hit script for arrows
// It will remove projectile if the latter aren't equipped with cloak of displacement
    void self = getlocalvar("self");
    void target = getlocalvar("damagetaker");
    char Shot = getentityproperty(self,"defaultname");
    void vAniID = getentityproperty(self,"animationID");
    int SFX;
    int Block;
    int Defense;
    int THP;

    if(target!=NULL()){
      Defense = getentityproperty(target, "defense", openborconstant("ATK_NORMAL10"));
      Block = getentityproperty(target, "aiflag", "blocking");
      THP = getentityproperty(target,"health");

      if(Defense!=0){
        if(Block==1){
          SFX = loadsample("data/sounds/guard.wav");
          killentity(self); //Suicide!
        } else if(Shot=="BArrow"){
          SFX = loadsample("data/sounds/fbhit.wav");

          if(THP > 15){
            damageentity(target, self, 15, 0, openborconstant("ATK_BURN"));
          } else{
            damageentity(target, self, 15, 1, openborconstant("ATK_BURN"));
          }
          killentity(self); //Suicide!
        } else if(Shot=="Webshot"){
          SFX = loadsample("data/chars/aranea/webhit.wav");
          damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL11"));
          killentity(self); //Suicide!
        } else if(Shot=="arrowP" && vAniID == openborconstant("ANI_IDLE")){
          SFX = loadsample("data/sounds/beat1.wav");

          if(THP > 5){
            damageentity(target, self, 5, 0, openborconstant("ATK_NORMAL2"));
          } else{
            damageentity(target, self, 5, 1, openborconstant("ATK_NORMAL2"));
          }
          changeentityproperty(self, "velocity", 0, 0, 0);
          changeentityproperty(self, "speed", 0);
          changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
        } else if(Shot=="arrowE"){
          SFX = loadsample("data/sounds/beat1.wav");

          if(THP > 10){
            damageentity(target, self, 10, 1, openborconstant("ATK_NORMAL"));
          } else{
            damageentity(target, self, 10, 1, openborconstant("ATK_NORMAL"));
          }
          killentity(self); //Suicide!
        } else if(Shot=="Dagger"){
          SFX = loadsample("data/sounds/dagger.wav");

          if(THP > 10){
            damageentity(target, self, 10, 0, openborconstant("ATK_NORMAL"));
          } else{
            damageentity(target, self, 10, 1, openborconstant("ATK_NORMAL"));
          }
          killentity(self); //Suicide!
        } else if(Shot=="SRockE"){
          SFX = loadsample("data/sounds/beat1.wav");

          if(THP > 5){
            damageentity(target, self, 5, 0, openborconstant("ATK_NORMAL"));
          } else{
            damageentity(target, self, 5, 1, openborconstant("ATK_NORMAL"));
          }
          killentity(self); //Suicide!
        } else if(Shot=="Spear"){
          SFX = loadsample("data/sounds/dagger.wav");

          if(THP > 18){
            damageentity(target, self, 18, 1, openborconstant("ATK_NORMAL"));
          } else{
            damageentity(target, self, 18, 1, openborconstant("ATK_NORMAL"));
          }
          killentity(self); //Suicide!
        } else if(Shot=="DerroSpear"){
          SFX = loadsample("data/sounds/dagger.wav");

          if(THP > 18){
            damageentity(target, self, 12, 1, openborconstant("ATK_NORMAL"));
          } else{
            damageentity(target, self, 12, 1, openborconstant("ATK_NORMAL"));
          }
          killentity(self); //Suicide!
        } else if(Shot=="Jamur"){
          SFX = loadsample("data/sounds/beat1.wav");

          if(THP > 12){
            damageentity(target, self, 12, 0, openborconstant("ATK_NORMAL"));
          } else{
            damageentity(target, self, 12, 1, openborconstant("ATK_NORMAL"));
          }
          killentity(self); //Suicide!
        }
        playsample(SFX, 0, 120, 120, 100, 0);
      }
    }
}