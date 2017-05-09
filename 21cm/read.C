void read()
{
  double number, Vlsr;
  char tmp[200];
  double temp[100];
  double freq[100];
  char str[200];
  char tmp_str[1000];
  ifstream *file;
  file = new ifstream[19];
  char numbstr[200];
  cout << "1" << endl;
  double angles[19] = {90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180};
  double vlsr[19] = {-32, -32, -32, -32, -32, -32, -32,-32, -32, -32, -32, -32, -32, -32,-32, -32, -32, -32, -32};

  //for( int a = 0; a < sizeof(angles)/sizeof(angles[0]); a = a+1){
  for( int a = 0; a < 1; a = a+1){
  sprintf(str, "/home/robin/jlab/21cm/g%d.dat", angles[a]);
  sprintf(numbstr, "g%d", angles[a]);

  file[a].open(str);

  TH1D* hist = new TH1D(numbstr,numbstr,37,(1420.406-1420.98844)*299792.458/1420.406 - vlsr[a],(1420.406-1419.84000)*299792.458/1420.406 - vlsr[a]);
  /*
  for(int i =0; i<148*2;i++)
    {
      if (i%2 == 0)
	{
	  file[a] >> x[a][i/2];
	  file[a] >> y[a][i/2];
	  if (y[a][i/2] < 95)
	    {
	      hist->Fill((1420.406-x[a][i/2])*299792.458/1420.406 -vlsr[a],0);
	    }
	  if (y[a][i/2] > 95)
	    {
	      hist->Fill((1420.406-x[a][i/2])*299792.458/1420.406 -vlsr[a],y[a][i/2]);
	    }
	}
    }
    */
  while (1){
    file[a].getline(tmp_str, 256, ",");
    freq = atof(tmp_str);

    file[a].getline(tmp_str, 256);
    temp = atof(tmp_str);

    if (temp < 95)
    {
	      hist->Fill((1420.406-freq)*299792.458/1420.406 -vlsr[a],0);
    }
    if (temp > 95)
	    {
	      hist->Fill((1420.406-freq)*299792.458/1420.406 -vlsr[a],y[a][i/2]);
	    }

    if(!file[a].good()) break;
  }}

/*
  double bin;
  for(int i=0;i<148;i++)
    {
      if (hist->GetBinContent(148-i) >95)
	{
	  bin = 148-i;
	  break;
	}
    }

  double average;
  for(int i=bin;i>bin-8;i--)
    {
      average += hist->GetBinContent(i);
    }
  average/=8;

  for(int i=0;i<148;i++)
    {
      if (hist->GetBinContent(i) >95)
	{
	  hist->SetBinContent(i, hist->GetBinContent(i)-average);
	}
    }
  
  hist->Fit("gaus","","",-15000,12000);
  double hwhm = sqrt(2*log(2))*gaus->GetParameter(2);
  double hwhme = sqrt(2*log(2))*gaus->GetParError(2);
  cout << hwhm << " +- " << hwhme << endl;
  */
  hist->Draw();
}
