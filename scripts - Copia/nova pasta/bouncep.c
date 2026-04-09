void main()
{
    void self = getlocalvar("self");
    int Dir = getentityproperty(self, "direction");
    int x = getentityproperty(self, "x");
    int y = getentityproperty(self, "a");
    int z = getentityproperty(self, "z");
    int Vx = getentityproperty(self, "xdir");
    void Anim = getentityproperty(self, "animationID");
    int C;
    int D;

    if(Dir == 1){
      C = -180;
      D = 0;
    } else {
      C = 180;
      D = 1;
    }

    if(y <= checkwall(x+C,z) && (Anim == openborconstant("ANI_FOLLOW7") || Anim == openborconstant("ANI_FOLLOW8") || Anim == openborconstant("ANI_FOLLOW9") || Anim == openborconstant("ANI_FOLLOW6") || Anim == openborconstant("ANI_FOLLOW4") || Anim == openborconstant("ANI_FOLLOW5")  || Anim == openborconstant("ANI_GRABWALK")  || Anim == openborconstant("ANI_GRABFORWARD"))){
      changeentityproperty(self, "velocity", -Vx-1);
      changeentityproperty(self, "direction", D);
    }
}