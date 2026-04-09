void main(){
    void vSelf = getlocalvar("self");
    int PIndex = getentityproperty(vSelf,"playerindex");

    if(PIndex==0){
      setglobalvar("0Talk",1);
      setglobalvar("1Talk",NULL());
    } else if(PIndex==1){
      setglobalvar("1Talk",1);
      setglobalvar("0Talk",NULL());
    }
}
