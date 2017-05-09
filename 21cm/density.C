#include "TMath.h"
#include <iostream>

double geometry(double freq, double sun_vel, double sun_distance, double angle, double vlsr, double rotation)
{
  double rad = angle/180*3.14159265;
  double vel = (1420.406-freq)*299792.458/1420.406 - vlsr;
  cout << "velocty " <<  vel << endl;
  double radius = (rotation*sun_distance*TMath::Sin(rad))/(vel + sun_vel*TMath::Sin(rad));
  cout << "radius " << radius << endl;
  double gal_angle = TMath::ASin(sun_distance*TMath::Sin(rad)/radius);
  double other_angle = 2*3.14159265 - gal_angle - rad;
  cout << "other angle " << other_angle << endl;
//  cout << TMath::Sin(other_angle) << " uh " << radius << " what  " << TMath::Sin(rad) << endl;
  return TMath::Sin(other_angle)*radius/TMath::Sin(rad);
}

void density()
{
 double number, Vlsr;
  char tmp[200];
  double temp;
  double freq;
  double sun_vel = 220;
  double sun_distance = 1000000000000000000;
  char str[200];
  double rotation = 200;
  double d = 0;
  char tmp_str[1000];
  ifstream *file;
  file = new ifstream[17];
  char numbstr[200];
  cout << "1" << endl;
  double angles[17] = {95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175};
  double vlsr[17] = {-32, -32, -32, -32, -32, -32,-32, -32, -32, -32, -32, -32, -32,-32, -32, -32, -32};
  TH2* h1 = new TH2F("h1", "hydrogen density", 72, 0, 360, 74, 0, 2000000000000000000);

  for( int a = 0; a < sizeof(angles)/sizeof(angles[0]); a = a+1){
//  for( int a = 1; a < 2; a = a+1){
  sprintf(str, "/home/robin/jlab/21cm/g%d.dat", angles[a]);
  sprintf(numbstr, "g%d", angles[a]);

  file[a].open(str);

  TH1D* hist = new TH1D(numbstr,numbstr,148,(1420.406-1420.98844)*299792.458/1420.406 - vlsr[a],(1420.406-1419.84000)*299792.458/1420.406 - vlsr[a]);
  while (1){
    file[a].getline(tmp_str, 256, ',');
    freq = atof(tmp_str);

    file[a].getline(tmp_str, 256);
    temp = atof(tmp_str);
    

    /*if (temp < 99)
    {
	      hist->Fill((1420.406-freq)*299792.458/1420.406 -vlsr[a],0);
    }
    if (temp > 99) /  {*/
	      hist->Fill((1420.406-freq)*299792.458/1420.406 -vlsr[a],temp);
        d = geometry(freq, sun_vel, sun_distance, angles[a], vlsr[a], rotation);
        cout << "d=" << d << endl;
        h1->Fill(angles[a], d, temp-95);
	  //}

    if(!file[a].good()) break;
    
  }
  cout << "collected data from " << angles[a] << endl;
    hist->Draw();
    hist->Reset();
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
  
  h1->Draw("pollego2z");
}
