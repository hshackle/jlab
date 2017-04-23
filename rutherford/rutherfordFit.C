#include "Riostream.h"

void rutherfordFit() {
  TCanvas *c1 = new TCanvas("c1", "Data", 200, 10, 700 ,500);
  Double_t y[5] = {.66, .12, .02, .005, .0009};
//  Double_t x[4]= {85, 94, 104, 113};
  Double_t x[5]= {15, 20, 30, 40, 60};
  Double_t yerr[5] = {.03, .005, .00049, .000253, .00004669};
  Double_t xerr[5] ={ 0.5, 0.5, 0.5, 0.5, 0.5};



  gr = new TGraphErrors(6, x, y, xerr, yerr);
  gr->GetYaxis()->SetTitle("Counts");
  gr->GetXaxis()->SetTitle("Angle");
  gr->SetTitle();
  gr->Draw("AP");
  gr->SetMarkerStyle(21);
  TF1 *classic = new TF1("classic", "[0]*x*x", -100, 100);
  classic->SetParameter(0, .03);
  //gr->Fit("classic");
  TF1 *conv = new TF1("conv", "[0]*(-0.00156785*TMath::Power(x, 5) + 0.251308*TMath::Power(x, 4) - 14.9756*TMath::Power(x, 3) + 413.025*TMath::Power(x, 2) - 5238.2*x + 24333.2)", -100, 100);
  conv->SetParameter(0, .005);
  gr->Fit("conv");
  gStyle->SetOptFit(1111);
};

int main(){
  rutherfordFit();
}
