void inhomo() {
  TCanvas *c1 = new TCanvas("c1", "Inhomogeneity Fit", 200, 10, 700 ,500);
  Double_t y[4] = {112.3, 103.5, 93.6, 84.5};
  Double_t x[4]= { 112.8, 103.8, 94.0, 84.6};
  Double_t xerr[4] = {1.2, 1.1, 1.0, .9};
  Double_t yerr[4] ={.7, .6, .6, .5};

  gr = new TGraphErrors(4, x, y, xerr, yerr);
  gr->Draw("AP");
  gr->Fit("pol1");
/*  gr->Fit("relativistic");*/
  gStyle->SetOptFit(1111);
};

int main(){
  inhomo();
}
