	char c;
	for(int i = 1; i<8; i++)
	{
		bool horiz = (i<4); bool vert = (i>=4)&& i<7; bool diag=i>=7; 
		if(vert) i-=4; if(diag) i-=7;
		MoveToPlay(i, horiz,vert,diag);
		
		c=CheckForWin(); 
		
		if(c != NULL && !(c>'0' && c<'9'+1))
			break;
	}
	if(c!=NULL)
		return c;
	else
	{
		for(int i = 1; i<8; i++)
		{
			bool horiz = (i<4); bool vert = (i>3)&& i<7; bool diag=i<7; 
			MoveToPlay(i, horiz,vert,diag);
			
			c=isTie(); 
			if(c == true)
				return 0xFF;
		}
			
	}
	return 0;
