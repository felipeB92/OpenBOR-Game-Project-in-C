void main()
{// Uncover player's invisibility
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index

    changeplayerproperty(iPIndex, "weapon", 0);
}
