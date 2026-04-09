void main()
{
    void self = getlocalvar("self");
    void vAniID  = getentityproperty(self,"animationID");
    int Dir = getentityproperty(self, "direction");
    int x = getentityproperty(self, "x");
    int y = getentityproperty(self, "a");
    int z = getentityproperty(self, "z");
    int Vx = getentityproperty(self, "xdir");
    int C;
    
	int D;

    if(Dir == 1){
      C = 150;
      
	D = 0;
    } else {
      C = -150;
      D = 1;
    }

    if(y < checkwall(x+C,z) && vAniID == openborconstant("ANI_respawn") && Dir == 0){
      changeentityproperty(self, "direction", 1);
      changeentityproperty(self, "velocity", -Vx);
    }else if(y < checkwall(x+C,z) && vAniID == openborconstant("ANI_respawn") && Dir == 1)
    {
      changeentityproperty(self, "direction", 0);
      changeentityproperty(self, "velocity", -Vx);
    }
}
