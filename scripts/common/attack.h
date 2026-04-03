
void riseinv(int t)
{
    void self = getlocalvar("self");
	changeentityproperty(self, "invincible", 1);
	//changeentityproperty(self, "blink", 1);
	changeentityproperty(self, "invinctime", t+openborvariant("elapsed_time"));
}

void switch_combo(char anim1, char anim2, int step, char name, float r1, float r2)
{
    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");
	if(getentityproperty(self, "model")!=getentityproperty(self, "name") && getentityproperty(self, "model")!="pc_skeleton")
	{
		return 0;
	}
    if(target==NULL())
    {
        target = findtarget(self);
    }
    if(target!=NULL())
    {
        char tname = getentityproperty(target, "defaultname");
        if(tname == name)
        {
            float x1 = getentityproperty(target, "x");
            float x2 = getentityproperty(self, "x");
            float z1 = getentityproperty(target, "z");
            float z2 = getentityproperty(self, "z");
            if(z1-z2<15 && z1-z2>-15 && x1-x2>-r1 && x1-x2<r1)
            {
                changeentityproperty(self, "animation", openborconstant(anim1));
                changeentityproperty(self, "combostep", 0, step);
            }
            else if(z1-z2<15 && z1-z2>-15 && x1-x2>-r2 && x1-x2<r2)
            {
                changeentityproperty(self, "animation", openborconstant(anim2));
                changeentityproperty(self, "combostep", 0, step);
            }
        }
    }
}

void hit_rider(char anim1, char anim2,float r1, float r2)
{
    void self = getlocalvar("self");
    void target = findtarget(self);
	if(getentityproperty(self, "model")!=getentityproperty(self, "name") && getentityproperty(self, "model")!="pc_skeleton")
	{
		return 0;
	}
    if(target!=NULL())
    {
        if(getentityproperty(target, "animal"))
        {
            float x1 = getentityproperty(target, "x");
            float x2 = getentityproperty(self, "x");
            float z1 = getentityproperty(target, "z");
            float z2 = getentityproperty(self, "z");
            if(z1-z2<15 && z1-z2>-15 && x1-x2>-r1 && x1-x2<r1)
            {
                changeentityproperty(self, "animation", openborconstant(anim1));
                changeentityproperty(self, "combostep", 0, 0);
            }
            else if(z1-z2<15 && z1-z2>-15 && x1-x2>-r2 && x1-x2<r2)
            {
                changeentityproperty(self, "animation", openborconstant(anim2));
                changeentityproperty(self, "combostep", 0, 0);
            }
        }
    }
}
