void main()
{
	void	s;
	void	value	=	getlocalvar("value");
	void	max		=	getlocalvar("max");
	void HUD; 
	void HUD2; 
	void HUD3; 
	void HUD4; 
	void HUD5;
	if (!HUD){
	HUD = loadsprite("data/bgs/1.gif");
	}	
	if (!HUD2){
	HUD2 = loadsprite("data/bgs/2.gif");
	}
	if (!HUD3){
	HUD3 = loadsprite("data/bgs/3.gif");
	}
	if (!HUD4){
	HUD4 = loadsprite("data/bgs/1.gif");
	}
	if (!HUD5){
	HUD5 = loadsprite("data/bgs/2.gif");
	}	
	
    int sprLoad = getglobalvar("sprLoad");
	
	
	if(max==1){
		return;
	}else{}

	void percent=value*100/max;
	percent%=++percent;

	void dot=percent%3;
	if(dot==0)
		s=">___";
	else if(dot==1)
		s="_>__";
	else
		s="__>_";
	if (sprLoad==NULL()){
	drawsprite(HUD5, percent*480*0.01-28, 185, 170, 1);
}
	if (percent<=20){
	drawstring(100,260,0,"Loading_ Heroes"+s+percent+"%__Complete");
	
	}
	else if (percent>20 && percent <=40){
	drawstring(100,60,0,"Pablo M Vera"+s+percent+"%__Complete");
		if (sprLoad==NULL()){drawsprite(HUD, 0, 50, 170, 1);}
	}
	else if (percent>40 && percent <=60){
	drawstring(143,242,2,"How_about_some_Fun_Factor"+s+percent+"%__Complete");
		if (sprLoad==NULL()){drawsprite(HUD, 0, 50, 170, 1);
		drawsprite(HUD2, 50, 55, 170, 2);}
	}
	else if (percent>60 && percent <=80){
	drawstring(143,242,2,"Where_is_Deadpool???"+s+percent+"%__Complete");
		if (sprLoad==NULL()){drawsprite(HUD, 0, 50, 170, 1);
	drawsprite(HUD2, 50, 55, 170, 2);
		drawsprite(HUD3, 310, 35, 170, 1);}
	}else{
	drawstring(143,242,1,"AVENGERS_ASSEMBLE!"+s+percent+"%__Complete");
		if (sprLoad==NULL()){drawsprite(HUD, 0, 50, 170, 1);
	drawsprite(HUD2, 50, 55, 170, 2);
	drawsprite(HUD3, 310, 35, 170, 1);
		drawsprite(HUD4, 328, 75, 170, 2);}
	}
	

	
	//loading log
	if (percent==5){
	log("\n");
    log("---------------------------------------------------------------------loading 5%---- ");
	log("\n");
	}
	if (percent==10){
	log("\n");
    log("---------------------------------------------------------------------loading 10%---- ");
	log("\n");
	}
	if (percent==15){
	log("\n");
    log("---------------------------------------------------------------------loading 15%---- ");
	log("\n");
	}
	if (percent==20){
	log("\n");
    log("---------------------------------------------------------------------loading 20%---- ");
	log("\n");
	}
	if (percent==25){
	log("\n");
    log("---------------------------------------------------------------------loading 25%---- ");
	log("\n");
	}
	if (percent==30){
	log("\n");
    log("---------------------------------------------------------------------loading 30%---- ");
	log("\n");
	}
	
	drawbox(0,259,480,15,11,rgbcolor(0,122,133),0);
	drawbox(0,259,percent*480*0.01,5,15,rgbcolor(0,233,233),0);
	drawbox(0,264,percent*480*0.01,5,15,rgbcolor(0,213,233),0);
	drawbox(0,269,percent*480*0.01,5,15,rgbcolor(0,193,233),0);
	drawline(percent*480*0.01, 257, percent*480*0.01, 273, 25, rgbcolor(255,255,255), 0);

	//drawline(x1, y1, x2, y2, z, color, alpha)
	//drawbox(x, y, width, height, z, color, alpha)
}
