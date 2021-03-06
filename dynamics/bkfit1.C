void bkfit1() {
  TCanvas *c1 = new TCanvas("c1", "Inhomogeneity Fit", 200, 10, 700 ,500);
  Double_t y[4] = {222, 265, 312, 355};
  Double_t x[4]= {85, 94.5, 104, 113};
//  Double_t x[4]= {86.7, 95.6, 105.7, 114.8};
//  Double_t x[4]= {90, 100, 112, 120};
//  Double_t xerr[4] = {1.7, 1.6, 1.7, 1.8};
//  Double_t xerr[4] = {0,0,0,0};
//  Double_t xerr[4] = {1, 1, 1,1};
  Double_t xerr[4] = {.21, .21, .42, .36};
  Double_t yerr[4] ={1.47,1.08,.79,.66};



  gr = new TGraphErrors(4, x, y, xerr, yerr);
  gr->GetYaxis()->SetTitle("Kinetic Enery [kEv]");
  gr->GetXaxis()->SetTitle("Magnetic Field [G]");
  gr->SetTitle();
  gr->SetMarkerStyle(21);
  gr->Draw("AP");
  TF1 *classic = new TF1("classic", "[0]*x*x", -100, 100);
  classic->SetParameter(0, .03);
  gr->Fit("classic");
  TF1 *relativistic = new TF1("relativistic", "TMath::Sqrt([0]*[0] *x*x + [1]*[1]) - [1]", -100, 100);
  relativistic->SetParameter(0, 20);
  relativistic->SetParameter(1, 150);
  gr->Fit("relativistic");
  gStyle->SetOptFit(1111);
/*  leg = new TLegend(0.1,0.1,0.45,0.3);
  leg->AddEntry(fit1, "Relativistic Fit", "l");
  leg->AddEntry(fit2, "Classic Fit", "l");
  leg->SetTextSize(0.035);
//  leg->SetFillColorAlpha(0,0);
  leg->SetBorderSize(0);
  //leg->SetTextAlign(11);
  leg->Draw();*/
};

int main(){
  bkfit1();
}
