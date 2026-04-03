
void walk_aa()
{
	 void self = getlocalvar("self");
	 void target = findtarget(self);
	 if(target != NULL() )
	 {
		 int aid = getentityproperty(target, "animationid");
		 if(aid==openborconstant("ANI_RUNJUMPATTACK") || aid==openborconstant("ANI_JUMPATTACK"))
		 {
			 if(getentityproperty(target, "z") > getentityproperty(self, "z") )
			 {changeentityproperty(self, "velocity", getentityproperty(self, "xdir"), -0.1, getentityproperty(self, "tossv"));}
			 else
			 {changeentityproperty(self, "velocity", getentityproperty(self, "xdir"), 0.1, getentityproperty(self, "tossv"));}
		 }
	 }
}