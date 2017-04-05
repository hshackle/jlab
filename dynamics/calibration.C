void calibration() {
  TCanvas *c1 = new TCanvas("c1", "Inhomogeneity Fit", 200, 10, 700 ,500);
  Double_t y[3] = {99.69, 202.5, 0};
  Double_t x[3]= {111.3, 201.5,0};
  Double_t xerr[3] = {.2, .2, .1};
  Double_t yerr[3] ={1, 2, .1};

  gr = new TGraphErrors(3, x, y, xerr, yerr);
  gr->Draw("AP");
  gr->Fit("pol1");
/*  gr->Fit("relativistic");*/
  gStyle->SetOptFit(1111);
};

int main(){
  calibration();
}
