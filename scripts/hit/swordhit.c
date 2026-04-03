void main(){
    void vSelf = getlocalvar("self");
    void target = getentityproperty(vSelf,"opponent");
    int iPlIndex = getentityproperty(vSelf,"playerindex");
    int Dir = getentityproperty(vSelf,"direction");
    int SwordS = getglobalvar(iPlIndex+"5");
    int Power = getglobalvar("Girdle");
    int SFX = loadsample("data/sounds/holy.wav");
    int SFX2 = loadsample("data/sounds/bigslice.wav");
    int Defense;
    int THealth;
    int r = rand()%50;

    if(target!=NULL()){
      Defense = getentityproperty(target, "defense", openborconstant("ATK_NORMAL12"));
      THealth = getentityproperty(target, "health");

      if(Defense!=0 && SwordS == 5){
        damageentity(target, vSelf, 200, 1, openborconstant("ATK_NORMAL12"));
        playsample(SFX, 0, 120, 120, 100, 0);
      } else if(SwordS == 6 && r > 45){
        damageentity(target, vSelf, 1000, 1, openborconstant("ATK_NORMAL15"));
      } else if(Power>=1){ // works even against nodrop enemies
        spawn01("Quaker",0,0,0);
        playsample(SFX2, 0, 120, 120, 100, 0);

        if(THealth<=0){
          if(Dir==1){
            tossentity(target, 3, 6);
          } else {
            tossentity(target, 3, -6);
          }
        }
      }
    }
}

void spawn01(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fY: Y location adjustment.
      //fZ: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    
	return vSpawn; //Return spawn.
}
