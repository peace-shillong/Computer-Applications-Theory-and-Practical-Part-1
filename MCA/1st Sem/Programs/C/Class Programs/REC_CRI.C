//Record Criket
//K.Dkhar
//2015
struct cr_team_list{
	char name[20];
	int no_runs,no_wicks,catches_takn,catches_droped,run_out;
	char desig[10], sp_status[10];
};
void main(){
	int i,c,des;
	//char sp=' ';
	struct cr_team_list s[11];
	for(i=0;i<2;i++){
	clrscr();
	printf("\n\tCricket Record System\n");
	printf("Enter Player Information\n");
	printf("Enter Player's Name: \n");
	scanf("%s",s[i].name);
	printf("Enter Runs Achieved: \n");
	scanf("%d",&s[i].no_runs);
	printf("Enter No of Wickets Taken:\n");
	scanf("%d",&s[i].no_wicks);
	printf("Enter No of Catches taken\n");
	scanf("%d",&s[i].catches_takn);
	printf("Enter No of Catches Dropped: \n");
	scanf("%d",&s[i].catches_droped);
	printf("Enter No of Run out\n");
	scanf("%d",&s[i].run_out);
	printf("Enter Player's Designation\nEnter 1 for Batsman\nEnter 2 for Bowler:\n");
	scanf("%d",&des);
	if(des==1){
		strcpy(s[i].desig,"Batsman");
	}
	else
		strcpy(s[i].desig,"Bowler");
	printf("Special Status if any:\n(C-Captain,V-Vice Captain W-Wicket keeper O-Others\n");
	scanf("%s",s[i].sp_status);
       //	strcpy(sp,s[i].sp_status);
/*	switch(sp){
	       //	case:
	       //	case :
	       //	case :
		//case :
		//case :
		//case :
			strcpy(s[i].sp_status,sp);
			break;
		default :
		strcpy(s[i].sp_status,"L");
	}*/
	clrscr();
	}//loop ends
	printf("\n\n\t Displaying Team Information");
	printf("\n\nName\tSp_Status\tRuns\tWickets\tCatches: Taken\tDropped\tRun out\tDesignation\n--------------------------------------------------\n");

	for(c=0;c<2;c++){
//		if(s[i].sp_status=='C')
		printf("\n%s\t(%s)\t%d\t%d\t%d\t%d\t%d\t%s\n",s[c].name,s[c].sp_status,s[c].no_runs,s[c].no_wicks,s[c].catches_takn,s[c].catches_droped,s[c].run_out,s[c].desig);
	}
	getch();
}