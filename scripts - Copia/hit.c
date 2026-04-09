#include "data\scripts\common\hitblock.h"

void main()
{
	if(getlocalvar("blocked"))
	{
        knockback(getlocalvar("damagetaker"), 1);
    }
}

