
void throw_bottles()
{
    void self = getlocalvar("self");
    // check mp
    //int mp = getentityproperty(self, "mp");
    int dir = getentityproperty(self, "direction");
    int sx = getentityproperty(self, "x");
    int sz = getentityproperty(self, "z");
    int sa = getentityproperty(self, "a");
    int pot = getentityproperty(self, "mp")/10 + 1;
    int i;
    int x = 15;
    int y = 38;
    int off = 1;
    int cor ;
	if(pot>getentityproperty(self, "maxmp")/10) {pot = getentityproperty(self, "maxmp")/10;}
	cor = pot%2;
    if(dir==0)
    {
       x = -x;
    }
	if(getentityproperty(self, "name")=="Gilius_Thunderhead")
	{
		x = -x;
	}
    clearspawnentry();
    setspawnentry("name", "Magic");
    for(i=0; i<pot; i++)
    {
        void m = spawn();
        int s;
        changeentityproperty(m, "position", sx + x, sz+1, sa+y);
        if(cor==1)
        {
            s = (i+1)/2;
        }
        else
        {
            s = (i+2)/2;
        }
        changeentityproperty(m, "velocity", s*off/8.0);
        off = -off;
    }
    setlocalvar("pot", pot); // record magic level
    changeentityproperty(self, "mp", 0);
}

