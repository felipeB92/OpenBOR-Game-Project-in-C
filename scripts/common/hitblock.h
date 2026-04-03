void knockback(void other, float spd)
{
    if(getentityproperty(other, "direction")==1) {spd = -spd;}
    changeentityproperty(other, "velocity", spd, 0, 0);
}
