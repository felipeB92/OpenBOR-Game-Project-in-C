#include "data/scripts/library/basic.h"
#include "data/scripts/library/spawn.h"
#include "data/scripts/library/target.h"

void stealth(int Value)
{ // Change stealth value
   void self = getlocalvar("self");

   changeentityproperty(self, "stealth", Value);
}

void spawnChild(void Name, float dx, float dy, float dz)
{ // Spawn entity and set it as child
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, dz);
   changeentityproperty(Spawn, "parent", self);
}

void shooterZ(void vName, float fX, float fY, float fZ, float Vx, float Vy, float Vz, int Edge, int Flag)
{// Shoot projectile based on left screen edge
// Z coordinate is based on shooter's
    void self = getlocalvar("self"); //Get calling entity
    int Direction = getentityproperty(self, "direction");
    void vSpawn; //Spawn object

    if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx ;
    }

    if (Flag == 0){
      vSpawn = spawn02(vName, fX, fY, fZ, Edge);
    } else if (Flag == 1){
      vSpawn = spawn04(vName, fX, fY, fZ, Edge);
    }

    changeentityproperty(vSpawn, "velocity", Vx, Vz, Vy);
}

void tossT2(void Shot, float dx, float dy, float dz, float Vy)
{ // Tossing targetted projectile
   void self = getlocalvar("self");
   float Vx = getlocalvar("x"+self);
   float Vz = getlocalvar("z"+self);
   void vShot;

   if( Vx!=NULL() && Vz!=NULL() ){
     vShot = spawn01(Shot, dx, dy, dz);
     changeentityproperty(vShot, "velocity", 0.5*Vx, 0.5*Vz, Vy);
   }
}

void attackF(void Ani)
{// Attack interruption if any player falls
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player

    if(target!=NULL()){
      void PAni = getentityproperty(target, "animationID");

      if(PAni == openborconstant("ANI_FALL")){
        dasher(0,0,0);
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void attackHold(void Ani)
{// Attack interruption if any player falls in Held Person state
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player

    if(target!=NULL()){
      void PAni = getentityproperty(target, "animationID");

      if(PAni == openborconstant("ANI_PAIN3") || PAni == openborconstant("ANI_FALL3") || PAni == openborconstant("ANI_RISE3")){
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void attackDizzy(void Ani)
{// Attack interruption if any player falls in dizzy state
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player

    if(target){
      void PAni = getentityproperty(target, "animationID");

      if(PAni == openborconstant("ANI_PAIN13") || PAni == openborconstant("ANI_FALL13") || PAni == openborconstant("ANI_RISE13")){
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void attackFront(int RxMin, int RxMax, int Rz, void Ani)
{// Attack interruption if player is facing enemy
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      int Tdir = getentityproperty(target, "direction");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1 && Tdir == 0){
        performattack(self, openborconstant(Ani)); //Change the animation
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0 && Tdir == 1){
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void dodgez( float Vx, float Vy, float Vz )
{// Dodge by moving up or down depending on z location
    void self = getlocalvar("self");
    int z = getentityproperty(self, "z");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    if(z > (openborvariant("PLAYER_MIN_Z") + openborvariant("PLAYER_MAX_Z")) / 2 ) {
      Vz = -Vz ;
    }

    if( Vx!=NULL() && Vy!=NULL() && Vz!=NULL() ){
      changeentityproperty(self, "velocity", Vx, Vz, Vy); //Dodge away!
    }
}

void Rdodgez( float Vx, float Vy, float Vz, float Rx, float Rz )
{// Dodgez with random velocity effect
// Only randomize x and z velocities
   int iDX;
   int iDZ;

   if(Rx!=0){
     iDX = (rand()%(Rx*10)*0.1);
   } else {
     iDX = 0;
   }

   if(Rz!=0){
     iDZ = (rand()%(Rz*10)*0.1);
   } else {
     iDZ = 0;
   }

   dodgez( Vx+iDX, Vy, Vz+iDZ );
}

void teledodgez( float dx, float dy, float dz )
{// Dodge by teleporting up or down depending on z location
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int z = getentityproperty(self,"z"); //Get character's z coordinate
    int a = getentityproperty(self,"a"); //Get character's a coordinate
    int dir = getentityproperty(self,"direction"); //Get character's facing direction
    float H;
    int FZ;

    if(z > (openborvariant("PLAYER_MIN_Z") + openborvariant("PLAYER_MAX_Z")) / 2 ) {
      dz = -dz ;
    }
    FZ = z+dz;

    if(dir==0){ // Facing left?
      dx = -dx ;
    }

    if((z + dz) > openborvariant("PLAYER_MAX_Z")) {
      FZ = openborvariant("PLAYER_MAX_Z");
    } else if((z + dz) < openborvariant("PLAYER_MIN_Z")) {
      FZ = openborvariant("PLAYER_MIN_Z");
    }

    H = checkwall(x+dx,FZ);

    if(H > 0){ // Is there a wall on teleport destination?
      dx = -dx ;
    }

    changeentityproperty(self, "position", x+dx, FZ, a+dy); //Teleport away!
}

void spawn07(void vName, float fX, float fY, float fZ)
{
	//Spawns entity on exact coordinate
	//
	//vName: Model name of entity to be spawned in.
	//fX: X coordinate
	//fY: Y height from ground
        //fZ: Z coordinate

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
        int XPos = openborvariant("xpos"); //Get screen edge's position

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	return vSpawn; //Return spawn
}

void spawnMinion(void Name, float dx, float dy, float dz)
{ // Spawn certain entity and matches its direction with own direction
   void self = getlocalvar("self");
   int Dir = getentityproperty(self,"direction");
   int Screen = openborvariant("hResolution"); // Get screen width
   void Spawn;

   Spawn = spawn04(Name, dx, dy, dz, Screen);
   changeentityproperty(Spawn, "direction", Dir);
}

void shootTC(void Shot, float dx, float dy, float dz)
{ // Shooting targetted projectile as child
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float Vx = getlocalvar("x"+self);
   float Vz = getlocalvar("z"+self);
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
   changeentityproperty(vShot, "parent", self);

   if( Vx!=NULL() && Vz!=NULL() ){
     changeentityproperty(vShot, "velocity", Vx, Vz);
     if (Vx < 0 && Direction == 1){ //Is projectile moving back?
       changeentityproperty(vShot, "direction", 0);
     } else if(Vx > 0 && Direction == 0){ //Is projectile moving back?
       changeentityproperty(vShot, "direction", 1);
     }
     if ( Vx < 0 ){ //Is Vx negative?
       Vx = -Vx;
     }
     changeentityproperty(vShot, "speed", Vx);
   }
}

void randomteleonscreen()
{// Randomly teleports onscreen

    void self = getlocalvar("self"); //Get calling entity
    int XPos = openborvariant("xpos"); //Get screen edge's position
    int Screen = openborvariant("hResolution"); // Get screen width
    int Width = openborvariant("PLAYER_MAX_Z") - openborvariant("PLAYER_MIN_Z"); // Get width
    int iRx = rand()%(Screen/2) + Screen/2 ;
    int iRz;

    iRz = rand()%(Width/2) + Width/2 ;

    changeentityproperty(self, "position", iRx + XPos, iRz + openborvariant("PLAYER_MIN_Z")); //Randomly teleport
}

void attackAnim(void PAni, void EAni)
{// Attack interruption if nearby opponent performs defined animation
// PAni : Player's animation to check
// EAni : Enemy's animation to change to
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest opponent

    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");

      if(PAnim == openborconstant(PAni)){
        performattack(self, openborconstant(EAni)); //Change the animation
      }
    }
}
