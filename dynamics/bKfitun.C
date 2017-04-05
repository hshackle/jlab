void bKfitun() {
  TCanvas *c1 = new TCanvas("c1", "Inhomogeneity Fit", 200, 10, 700 ,500);
  Double_t y[4] = {232, 265, 311, 355};
//Double_t x[4]= {85, 94, 104, 113};
  Double_t x[4]= {90.02, 99.95, 110.95, 120.1};
/*  Double_t xerr[4] = {1.6, 1.7, 1.9, 1.9};*/
  Double_t xerr[4] = {.21, .21, .42, .36};
  Double_t yerr[4] ={2,3,3,1};



  gr = new TGraphErrors(4, x, y, xerr, yerr);
  gr->Draw("AP");
  TF1 *classic = new TF1("classic", "[0]*x*x", -100, 100);
  classic->SetParameter(0, .03);
  gr->Fit("classic");
  TF1 *relativistic = new TF1("relativistic", "TMath::Sqrt([0]*x*x + [1]*[1]) - [1]", -100, 100);
  relativistic->SetParameter(0, 20);
  relativistic->SetParameter(1, 150);
  gr->Fit("relativistic");
  gStyle->SetOptFit(1111);
};

int main(){
  bKfitun();
}
