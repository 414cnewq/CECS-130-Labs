	#ifdef DEBUG
	cout << "3d Check Started" <<endl;
	#endif 
	char tmp[3];
	int lowStart, highStart;
	//algorithm inspired by https://github.com/aarondancer/3D-Tic-Tac-Toe/blob/master/src/com/company/Grid.java
	lowStart = (lastZ - 3 + 1) < 0 ? 0:lastZ - 3 +1;
	highStart = 0;
	for(; lowStart <=highStart; lowStart++)
	{
		tmp[0]=0; tmp[1]=0; tmp[2]=0;
		int t=lowStart, p =0, final, count=0;
		while(t< (lowStart+3))
		{
			tmp[p]=Arrays[t][lastX][lastY];
			t++; p++;
		}
		final = tmp[0];
		for(int i = 1; i<3; i++)
		{
			if((tmp[i] =='X' || tmp[i]=='O') && tmp[i]==final) count++;
			final = tmp[i];
		}
		if(count == 3-1) return tmp[3];
		
	}
	lowStart = (lastY - 3 + 1) < 0 ? 0:lastY - 3 +1;
	highStart = 0;
	for(; lowStart <=highStart; lowStart++)
	{
		tmp[0]=0; tmp[1]=0; tmp[2]=0;
		int t=lowStart, p =0, final, count=0;
		while(t< (lowStart+3))
		{
			tmp[p]=Arrays[lastZ][lastX][t];
			t++; p++;
		}
		final = tmp[0];
		for(int i = 1; i<3; i++)
		{
			if((tmp[i] =='X' || tmp[i]=='O') && tmp[i]==final) count++;
			final = tmp[i];
		}
		if(count == 3-1) return tmp[3];
		
	}
	lowStart = (lastX - 3 + 1) < 0 ? 0:lastX - 3 +1;
	highStart = 0;
	for(; lowStart <=highStart; lowStart++)
	{
		tmp[0]=0; tmp[1]=0; tmp[2]=0;
		int t=lowStart, p =0, final, count=0;
		while(t< (lowStart+3))
		{
			tmp[p]=Arrays[lastZ][t][lastY];
			t++; p++;
		}
		final = tmp[0];
		for(int i = 1; i<3; i++)
		{
			if((tmp[i] =='X' || tmp[i]=='O') && tmp[i]==final) count++;
			final = tmp[i];
		}
		if(count == 3-1) return tmp[3];
		
	}
	#ifdef DEBUG
	cout << "3d Check got to end " << endl;
	#endif
	 return 'C';
