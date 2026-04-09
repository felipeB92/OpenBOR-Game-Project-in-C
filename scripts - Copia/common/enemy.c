#include "data/scripts/library/basic.h"
#include "data/scripts/library/spawn.h"
#include "data/scripts/library/target.h"

void offscreenkill( float dx, int E )
{// Check position relative to screen. If enemy is offscreen, suicide!
//  dx : Distance to screen edge
//  E  : Edge selection, 0 = left, 1 = right

    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int XPos = openborvariant("xpos"); //Get screen edge's position

    if( (x > XPos + 320 + dx) && (E == 1) ){ // Offscreen to the right?
      killentity(self); //Suicide!
    } else if( (x < XPos - dx) && (E == 0) ){ // Offscreen to the left?
      killentity(self); //Suicide!
    }
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

void tossA(void Name, float dx, float dy, float dz)
{ // Tossing fallen enemy
    void self = getlocalvar("self");
    int iDirection = getentityproperty(self, "direction");
    void vSpawn;

    vSpawn = spawn01(Name, dx, dy, dz);
    damageentity(vSpawn, self, 0, 1, openborconstant("ATK_NORMAL"));

    if(iDirection == 1){
      tossentity(vSpawn, 3, -1, 0);
    } else {
      tossentity(vSpawn, 3, 1, 0);
    }
}

void tossD(void Name, float dx, float dy, float dz)
{ // Tossing dead enemy
    void self = getlocalvar("self");
    int iDirection = getentityproperty(self, "direction");
    void vSpawn;

    vSpawn = spawn01(Name, dx, dy, dz);
    damageentity(vSpawn, self, 1000, 1, openborconstant("ATK_NORMAL"));

    if(iDirection == 1){
      tossentity(vSpawn, 3, -1, 0);
    } else {
      tossentity(vSpawn, 3, 1, 0);
    }
}

void tossI(void Name, float dx, float dy, float dz)
{ // Tossing idle enemy ignoring its SPAWN animation
    void self = getlocalvar("self");
    char vAlias = getentityproperty(self,"name");
    int iDirection = getentityproperty(self, "direction");
    void vSpawn;

    vSpawn = spawn01(Name, dx, dy, dz);
    changeentityproperty(vSpawn, "name", vAlias);
    setidle(vSpawn, openborconstant("ANI_IDLE"));
}

void revolver(float Ax, float Az)
{// Revolve with speed change
// For none type
    void self = getlocalvar("self");
    float Vx = getentityproperty(self,"xdir");
    float Vz = 2*getentityproperty(self,"zdir");
    int iDir = getentityproperty(self, "direction");
    float Nx;
    float Nz;

    if(iDir == 0){
      Vx = -Vx;
    }

    if(Vx > 0 && Vz == 0){
      Nx = Vx + Ax;
      Nz = Vx + Az;
    } else if(Vx > 0 && Vz > 0){
      Nx = 0;
      Nz = Vz + Az;
    } else if(Vx == 0 && Vz > 0){
      Nx = -Vz - Ax;
      Nz = Vz + Az;
    } else if(Vx < 0 && Vz > 0){
      Nx = Vx - Ax;
      Nz = 0;
    } else if(Vx < 0 && Vz == 0){
      Nx = Vx - Ax;
      Nz = Vx - Az;
    } else if(Vx < 0 && Vz < 0){
      Nx = 0;
      Nz = Vz - Az;
    } else if(Vx == 0 && Vz < 0){
      Nx = -Vz + Ax;
      Nz = Vz - Az;
    } else if(Vx > 0 && Vz < 0){
      Nx = Vx + Ax;
      Nz = 0;
    }

    if(iDir == 0){
      Nx = -Nx;
    }

    changeentityproperty(self, "velocity", Nx, 0.5*Nz); //Revolve!
}

void spawnChild(void Name, float dx, float dy, float dz)
{ // Spawn entity and set it as child
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, dz);
   changeentityproperty(Spawn, "parent", self);
}

