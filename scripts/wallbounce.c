//Wall Jump without animationscript
//Author: O Ilusionista
//Version: V1 - 2018.03.03
//Thanks: Bloodbane and Damon Caskey.
void main()
{
    void vSelf = getlocalvar("self"); //Get calling player
	void facing = getentityproperty(vSelf, "direction"); // Get Direction
	void vAniID = getentityproperty(vSelf,"animationID"); //Get current animation ID
    void iJump = playerkeys(vSelf, 1, "jump"); //New key status of "Jump"
	int y = getentityproperty(vSelf, "a");	// Get Y pos
	int b = getentityproperty(vSelf, "base");	// Get Base pos
	
	if(vAniID == openborconstant("ANI_JUMP") || vAniID == openborconstant("ANI_FORWARDJUMP") || vAniID == openborconstant("ANI_RUNJUMP"))
	{ //Jumping, jumping forward or Run Jumping?

		if (iJump && y > b+20)
		{ //New jump key press and Y position is greater than the Base position by 20 pixels, so it won't trigger right when you start jumping?
		changeentityproperty(vSelf, "aiflag", "jumping", 0); // Disable jumping aiflag, so the common jump routine won't take action
		changeentityproperty(vSelf, "aiflag", "attacking", 1); // Enable attacking aiflag, so the common jumpattack routine won't take action
		changeentityproperty(vSelf, "animation", openborconstant("ANI_FOLLOW39")); // Change to FOLLOW40 anim
		}
	}
}