#include "TMath.h"
#include <iostream>

double geometry(double freq, double sun_vel, double sun_distance, double angle, double vlsr, double rotation)
{
  double rad = angle/180*3.14159265;
  double vel = (1420.406-freq)*299792.458/1420.406 - vlsr;
  double radius = (rotation*sun_distance*TMath::Sin(rad))/(vel + sun_vel*TMath::Sin(rad));
  double gal_angle = TMath::ASin(sun_distance*TMath::Sin(rad)/radius);
  double other_angle = 3.14159265 - gal_angle - rad;
//  cout << TMath::Sin(other_angle) << " uh " << radius << " what  " << TMath::Sin(rad) << endl;
  return (TMath::Sin(other_angle)*radius/TMath::Sin(rad))*3.2407*TMath::Power(10, -17);
}

double thermal(double vel, double sun_vel, double sun_distance, double angle, double rotation)
{
  double rad = angle/180*3.14159265;
  double radius = (rotation*sun_distance*TMath::Sin(rad))/(vel + sun_vel*TMath::Sin(rad));
  double gal_angle = TMath::ASin(sun_distance*TMath::Sin(rad)/radius);
  double other_angle = 3.14159265 - gal_angle - rad;
//  cout << TMath::Sin(other_angle) << " uh " << radius << " what  " << TMath::Sin(rad) << endl;
  return (TMath::Sin(other_angle)*radius/TMath::Sin(rad))*3.2407*TMath::Power(10, -17);
}

void density()
{
 double number, Vlsr;
  char tmp[200];
  double temp;
  double freq;
  double sun_vel = 220;
  double sun_distance = 8*3.086*TMath::Power(10, 16);
  char str[200];
  double rotation = 190;
  double d = 0;
  char tmp_str[1000];
  ifstream *file;
  file = new ifstream[17];
  char numbstr[200];
 double variance1 = thermal(-50, sun_vel, sun_distance, 120, rotation);
 double variance2 = thermal(-76, sun_vel, sun_distance, 120, rotation);
 cout << variance1 << " " << variance2 << endl;
  double angles[17] = {95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175};
  double vlsr[17] = {-25.23, -22.33, -19.17, -16.01, -12.60, -9.1, -5.61,-2.08, 8.78, 5.1, 8.31, 12.01, 15.51, 18.62, 21.76, 24.67, 24.47};
  //double vlsr[16] = {-25.23, -22.33, -19.17, -16.01, -12.60, -9.1, -5.61,-2.08, 8.78, 5.1, 8.31, 12.01, 15.51, 18.62, 21.76, 24.67};
  double tsys[17] = {103, 103, 103, 103, 103, 103, 103, 103, 103, 110, 110, 110, 110, 110, 110, 110, 102};
  TH2* h1 = new TH2F("h1", "hydrogen density", 72, 0, 360, 10, 0, 10);
  TH2* h2 = new TH2F("h1", "hydrogen error", 72, 0, 360, 10, 0, 10);

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
    

    if (temp < tsys[a])
    {
	      hist->Fill((1420.406-freq)*299792.458/1420.406 -vlsr[a],0);
    }
    if (temp > tsys[a]) /  {
	      hist->Fill((1420.406-freq)*299792.458/1420.406 -vlsr[a],temp);
        //d= geometry(1420.41, sun_vel, sun_distance, 140, 4.5, rotation);
        d = geometry(freq, sun_vel, sun_distance, angles[a], vlsr[a], rotation);
        if (0 < d < 10){
        cout << d - geometry(freq-.063, sun_vel, sun_distance, angles[a], vlsr[a], rotation) << " " << d - geometry(freq+.063, sun_vel, sun_distance, angles[a], vlsr[a], rotation) << endl;
        }
        //cout << "d=" << d << endl;
        h2->Fill(angles[a], d, TMath::Sqrt((temp-tsys[a]))*d);
        h1->Fill(angles[a], d, (temp - tsys[a])*d);
	  }

    if(!file[a].good()) break;
    
  }
  cout << "collected data from " << angles[a] << endl;
//    hist->Draw();
 //   hist->Reset();
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
/*  TH2D* dummy_his = new TH2D("dummy", "histo ttile", 100, -10, 10, 100, -10, 10);
  TCanvas* c1 = new TCanvas("theCanvas", "theCanvas", 600, 600);
  dummy_his->Draw("COL"); */
  h1->Draw("pollego2z");
}
