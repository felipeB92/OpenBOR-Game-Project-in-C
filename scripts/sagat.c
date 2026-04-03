
void changeBranchByTotalScore(int score, void branchLow, void branchHigh, int now) {
	int players=openborvariant("count_players");
	int x;
	int totalscore=0;
	for(x=0;x<players;x++) {
		totalscore+=getplayerproperty(x, "score",0);
	}
	if(totalscore<score) {
		if(branchLow!= 0) {
			jumptobranch(branchLow, now);
		}
	} else {
		jumptobranch(branchHigh, now);
		
	}
}


