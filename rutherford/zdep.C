#include "Riostream.h"

void zdep() {
  TCanvas *c1 = new TCanvas("c1", "Inhomogeneity Fit", 200, 10, 700 ,500);
  Double_t y[2] = {1.483, 5.72};
//  Double_t x[4]= {85, 94, 104, 113};
  Double_t x[2]= {28, 79};
//  Double_t x[4]= {90, 100, 112, 120};
//  Double_t xerr[4] = {1.7, 1.6, 1.7, 1.8};
//  Double_t xerr[4] = {1, 1, 1,1};
  Double_t xerr[2] = {1, 2};
  Double_t yerr[2] ={.1, .5};



  gr = new TGraphErrors(2, x, y, xerr, yerr);
  gr->GetYaxis()->SetTitle("Kinetic Enery [kEv]");
  gr->GetXaxis()->SetTitle("Magnetic Field [G]");
  gr->SetTitle();
  gr->Draw("AP");
  gr->SetMarkerStyle(21);
  TF1 *classic = new TF1("classic", "[0]*x*x", -100, 100);
  classic->SetParameter(0, .03);
  gr->Fit("classic");
  /*TF1 *relativistic = new TF1("relativistic", "TMath::Sqrt([0]*x*x + [1]*[1]) - [1]", -100, 100);
  relativistic->SetParameter(0, 20);
  relativistic->SetParameter(1, 150);
  gr->Fit("relativistic");
  gStyle->SetOptFit(1111);
  TF1 *fit1 = new TF1("fit1", "TMath::Sqrt(x*x*20.3*20.3*.309777*.309777 + 554.032*554.032) - 554.032", 0,140);
  fit1->GetYaxis()->SetTitle("Kinetic Enery [kEv]");
  fit1->GetXaxis()->SetTitle("Magnetic Field [G]");
  fit1->SetTitle();
  fit1->Draw("SAME");
  TF1 *fit2 = new TF1("fit2", ".02823*x*x", 0,140);
  fit2->SetLineColor(4);
  fit2->Draw("SAME");
  leg = new TLegend(0.1,0.1,0.45,0.3);
  leg->AddEntry(fit1, "Relativistic Fit", "l");
  leg->AddEntry(fit2, "Classic Fit", "l");
  leg->SetTextSize(0.035);
  leg->SetFillColorAlpha(0,0);
  leg->SetBorderSize(0);
 leg->SetTextAlign(11);
  leg->Draw();*/
};

int main(){
zdep();
}
