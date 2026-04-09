void slide(float speed)
{
    void self = getlocalvar("self");
    //if(getentityproperty(self, "base") < getentityproperty(self, "a") - 0.5) {return 0;}
    if(getentityproperty(self, "direction")==0){speed = -speed;}
    changeentityproperty(self, "velocity",speed, 0, 0);
}