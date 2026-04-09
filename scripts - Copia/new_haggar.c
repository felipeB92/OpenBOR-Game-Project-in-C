




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

	
	
    if((attack && attackH) || (attack && attackH)){
      if (vAniID == openborconstant("ANI_follow8")){ //In valid animations?
	performattack(vEnt, openborconstant("ANI_follow5"));
	}
	
}	 	


	
    if((attack && attackH) || (attack && attackH)){
      if (vAniID == openborconstant("ANI_FOLLOW11")){ //In valid animations?
	performattack(vEnt, openborconstant("ANI_grabattack"));
	}
	
}	 

if((attack && attackH) || (attack && attackH)){
      if (vAniID == openborconstant("ANI_follow10")){ //In valid animations?
	performattack(vEnt, openborconstant("ANI_grabattack2"));
	}
	
}	 

if((attack && attackH) || (attack && attackH)){
      if (vAniID == openborconstant("ANI_follow9")){ //In valid animations?
	performattack(vEnt, openborconstant("ANI_follow6"));
	}
	
}	 	


if((attack && attackH) || (attack && attackH)){
      if (vAniID == openborconstant("ANI_follow4")){ //In valid animations?
	performattack(vEnt, openborconstant("ANI_follow7"));
	}
	
}	 	


if((jump && jumpH) || (jump && jumpH)){
      if (vAniID == openborconstant("ANI_grab")){ //In valid animations?
	performattack(vEnt, openborconstant("ANI_follow4"));
	
        
	 }	

	}

if((jump && jumpH) || (jump && jumpH)){
      if (vAniID == openborconstant("ANI_grabbackwalk")){ //In valid animations?
	performattack(vEnt, openborconstant("ANI_follow8"));
	
        
	 }	

	}
if((jump && jumpH) || (jump && jumpH)){
      if (vAniID == openborconstant("ANI_grabwalk")){ //In valid animations?
	performattack(vEnt, openborconstant("ANI_follow9"));
	
        
	 }	

	}
} 	