void main()
{// Take damage script for siege tower pushers
    void self = getlocalvar("self");
    void target = getentityvar(self, 0);
    int Num = getentityvar(self, 1);
    
    setentityvar(target, Num, 0);
}
