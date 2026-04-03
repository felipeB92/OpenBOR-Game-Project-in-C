




void main()
{
        


    int  plIndex = getlocalvar("player");
    void vEnt = getplayerproperty(plIndex, "entity");
    void vAniID = getentityproperty(vEnt,"animationID"); //Get current animation ID
	 
	
    int attack2 = playerkeys(plIndex, 1, "attack2");
    int attack2H = playerkeys(plIndex, 0, "attack2");

    int attack = playerkeys(plIndex, 1, "attack");
    int attackH = playerkeys(plIndex, 0, "attack");

    int jump = playerkeys(plIndex, 0, "jump");
    int jumpH = playerkeys(plIndex, 1, "jump");

	
	
    

	


if((jump && jumpH) || (jump && jumpH)){
      if (vAniID == openborconstant("ANI_grab")){ //In valid animations?
	performattack(vEnt, openborconstant("ANI_follow9"));
	
        
	 }	

	}




} 	