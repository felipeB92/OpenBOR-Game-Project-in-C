
void saveanimal()
{
	int i;
	void p;
	char a;

	for(i =0; i<3; i++)
	{
		p = getplayerproperty(i, "ent");
		if(p!=NULL())
		{
			a = getentityproperty(p, "model");
			if(a=="a_chick" || a=="g_chick" || a=="t_chick")
			{
				setglobalvar("runanimal", "Chickenlegs");
				break;
			}
			else if(a=="a_rdrag" || a=="g_rdrag" || a=="t_rdrag")
			{
				setglobalvar("runanimal", "Red_Dragon");
				break;
			}
			else if(a=="a_bdrag" || a=="g_bdrag" || a=="t_bdrag")
			{
				setglobalvar("runanimal", "Blue_Dragon");
				break;
			}
		}
	}
}

void saveallmp()
{
	int i;
	void p;

	for(i =0; i<3; i++)
	{
		p = getplayerproperty(i, "ent");
		if(p!=NULL())
		{
			float mp = getentityproperty(p, "mp");
			mp /= 10;
			mp %= 2000;
			setglobalvar("player"+i+"mp", mp);
		}
	}

}
