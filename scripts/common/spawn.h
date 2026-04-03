void wake()
{
    void self = getlocalvar("self");
    if(getentityproperty(self, "x")<=0 || getentityproperty(self, "x")>=getindexedvar(11))
    {
        changeentityproperty(self, "invincible", 1);
        changeentityproperty(self, "invinctime", 2000000+openborvariant("elapsed_time"));
        if(getentityproperty(self, "x")<getindexedvar(11)/2)
        {
            changeentityproperty(self, "velocity", 0.6, 0, 0);
        }
        else
        {
            changeentityproperty(self, "velocity", -0.6, 0, 0);
        }
        changeentityproperty(self, "animation", openborconstant("ANI_WALK"));
        return 1;
    }
    return 0;
}

int check_inscreen(void self)
{
    if(getentityproperty(self, "animnum")!=openborconstant("ANI_SPAWN") && getentityproperty(self, "x")>0 && getentityproperty(self, "x")<getindexedvar(11))
    {
	    changeentityproperty(self, "invincible", 0);
	    changeentityproperty(self, "invinctime", 0);
	    changeentityproperty(self, "velocity", 0, 0, 0);
	    changeentityproperty(self, "subject_to_screen", 1);
        changeentityproperty(self, "animation", openborconstant("ANI_SPAWN"));
        return 1;
    }
    else
    {
        return 0;
    }
}
