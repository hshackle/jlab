void density()
{
  double number, Vlsr;
  char tmp[200];
  double temp;
  double freq;
  double sun_vel = 220;
  double sun_distance = 1000000000000000000;
  char str[200];
  char tmp_str[1000];
  ifstream *file;
  file = new ifstream[19];
  char numbstr[200];
  cout << "1" << endl;
  double angles[19] = {90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180};
  double vlsr[19] = {-32, -32, -32, -32, -32, -32, -32,-32, -32, -32, -32, -32, -32, -32,-32, -32, -32, -32, -32};
  TH2* h1 = new TH2F("h1", "hydrogen density", 72, 0, 360, 74, 0, 10);
  h1->Fill(100, 5, 3);
  h1->Fill(160, 9, 5);
  h1->Draw("pollego2z");

  //for( int a = 0; a < sizeof(angles)/sizeof(angles[0]); a = a+1){
  for( int a = 0; a < 1; a = a+1){
  sprintf(str, "/home/robin/jlab/21cm/g%d.dat", angles[a]);
  sprintf(numbstr, "g%d", angles[a]);

  file[a].open(str);

  TH1D* hist = new TH1D(numbstr,numbstr,148,(1420.406-1420.98844)*299792.458/1420.406 - vlsr[a],(1420.406-1419.84000)*299792.458/1420.406 - vlsr[a]);
  while (1){
    file[a].getline(tmp_str, 256, ',');
    freq = atof(tmp_str);

    file[a].getline(tmp_str, 256);
    temp = atof(tmp_str);

    if (temp < 99)
    {
	      hist->Fill((1420.406-freq)*299792.458/1420.406 -vlsr[a],0);
    }
    if (temp > 99)
	 /  {
	      hist->Fill((1420.406-freq)*299792.458/1420.406 -vlsr[a],temp-99);
	  }

    if(!file[a].good()) break;
  }
 /* 
  double bin;
  for(int i=0;i<148;i++)
  {
    if (hist->GetBinContent(148-i) > 99)
    {
	  bin = 148-i;
	  break;
	}
    }

  double average;
  for(int i=bin;i>bin-8;i--)
    {
      average += hist->GetBinContent(i);
      cout << average << endl;
    }
  average/=8;

  for(int i=0;i<148;i++)
    {
      if (hist->GetBinContent(i) >99)
	{
	  hist->SetBinContent(i, hist->GetBinContent(i)-average);
	}
  }*/
  
  }
//  hist->Draw();
  
}
